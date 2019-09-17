// (C) Copyright Christian Bienia 2007
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0.
//
//  file : Thread.cpp
//  author : Christian Bienia - cbienia@cs.princeton.edu
//  description : A C++ thread

#if defined(HAVE_CONFIG_H)
# include "config.h"
#endif

#if defined(HAVE_LIBPTHREAD)
# include <pthread.h>
#else //default: winthreads
# include <windows.h>
# include <process.h>
#endif //HAVE_LIBPTHREAD

#include <typeinfo>
#include <iostream>
#include "Thread.h"

#ifdef ENABLE_PARSEC_HOOKS
#include <hooks.h>
#endif

namespace threads {

#if defined(HAVE_LIBPTHREAD)
// Unfortunately, thread libraries such as pthreads which use the C
// calling convention are incompatible with C++ member functions.
// To provide an object-oriented thread interface despite this obstacle,
// we make use of a helper function which will wrap the member function.
extern "C" {
  static void *thread_entry(void *arg) {
    Runnable *tobj = static_cast<Runnable *>(arg);
    tobj->Run();

    return NULL;
  }
#ifdef ECOLABKNL_HOOKS
  static void *thread_entry_wrapper(void *arg) {
    ecolab_bodytrack_thread_t *targ = static_cast<ecolab_bodytrack_thread_t *>(arg);
    /* Add the ECOLAB CPU Affinity Code here (tobj->tid)*/
    std::cout << "[parsec.bodytrack] : creating slave-thread@"<<targ->tid<<std::endl;
    //ecolab_set_cpu_affinity(targ->tid);
    thread_entry((void *)&targ->tobj);

    return NULL;
  }
#endif
}
#else //default: winthreads
extern "C" {
  unsigned __stdcall thread_entry(void *arg) {
    Runnable *tobj = static_cast<Runnable *>(arg);
    tobj->Run();
	return NULL;
  }
}
#endif //HAVE_LIBPTHREAD


//Constructor, expects a threadable object as argument
#ifdef ECOLABKNL_HOOKS
Thread::Thread(Runnable &_tobj, unsigned int tid) throw(ThreadCreationException) : targ{.tid = tid, .tobj = _tobj} {
#else
Thread::Thread(Runnable &_tobj) throw(ThreadCreationException) : tobj(_tobj) {
#endif
#if defined(HAVE_LIBPTHREAD)
#ifdef ECOLABKNL_HOOKS
  targ.tid  = tid;
  targ.tobj = _tobj;
  int rc = pthread_create(&t, NULL, &thread_entry_wrapper, (void *)&targ);
#else
  int rc = pthread_create(&t, NULL, &thread_entry, (void *)&tobj);
#endif
  
  if(rc) {
    ThreadCreationException e;
    throw e;
  }
#else //default: winthreads
  t = (void *)_beginthreadex(NULL, 0, &thread_entry, (void *)&tobj, 0, &t_id);
  if(!t) {
    ThreadCreationException e;
    throw e;
  }
#endif //HAVE_LIBPTHREAD
}

//Wait until Thread object has finished
void Thread::Join() {
  Stoppable *_tobj;
  bool isStoppable = true;

  //call Stop() function if implemented
  try {
#ifdef ECOLABKNL_HOOKS
    _tobj = &dynamic_cast<Stoppable &>(targ.tobj);
#else
    _tobj = &dynamic_cast<Stoppable &>(tobj);
#endif
  } catch(std::bad_cast e) {
    isStoppable = false;
  }
  if(isStoppable) {
    _tobj->Stop();
  }

#if defined(HAVE_LIBPTHREAD)
  pthread_join(t, NULL);
#else //default: winthreads
  WaitForSingleObject(t, INFINITE);
  CloseHandle(t);
#endif //HAVE_LIBPTHREAD
}

} //namespace threads
