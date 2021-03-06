// (C) Copyright Christian Bienia 2007
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0.
//
//  file : ThreadGroup.cpp
//  author : Christian Bienia - cbienia@cs.princeton.edu
//  description : A class which can manage a group of threads

#if defined(HAVE_CONFIG_H)
# include "config.h"
#endif

#include <list>

#include "Thread.h"
#include "ThreadGroup.h"

#ifdef ENABLE_PARSEC_HOOKS
#include <hooks.h>
#endif

namespace threads {

ThreadGroup::ThreadGroup() {
}

ThreadGroup::~ThreadGroup() {
  for (std::list<Thread *>::iterator it = threads.begin(); it != threads.end(); it++) {
    delete(*it);
  }
}

//Create a new thread and add it to the group
void ThreadGroup::CreateThread(Runnable &tobj) {
  //tobj.tid = 1; /* Set its tid to 1 */
#ifdef ECOLABKNL_HOOKS
  Thread *temp = new Thread(tobj,15);
#else
  Thread *temp = new Thread(tobj);
#endif
  threads.push_front(temp);
}

//Create multiple new threads which use the same start function and add them to the group
void ThreadGroup::CreateThreads(int n, Runnable &tobj) {
  int i;
  Thread *temp;

  for(i=0; i<n; i++) {
     //tobj.tid = i+1; /* Set its tid to 1 */
#ifdef ECOLABKNL_HOOKS
     temp = new Thread(tobj,i+1);
#else
     temp = new Thread(tobj);
#endif
     threads.push_front(temp);
  }
}

//Add an already existing thread
void ThreadGroup::AddThread(Thread *t) {
  threads.push_front(t);
}

//Remove a thread from the group
void ThreadGroup::RemoveThread(Thread *t) {
  threads.remove(t);
}

//Join all threads
void ThreadGroup::JoinAll() {
  for (std::list<Thread *>::iterator it = threads.begin(); it != threads.end(); it++) {
    (*it)->Join();
  }
}

//Number of threads in this group
int ThreadGroup::Size() const {
  return (int)threads.size();
}

} //namespace threads
