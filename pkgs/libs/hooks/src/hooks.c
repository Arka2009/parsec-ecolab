/* Copyright (c) 2006-2008 by Princeton University
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Princeton University nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY PRINCETON UNIVERSITY ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL PRINCETON UNIVERSITY BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/** \file hooks.c
 * \brief An implementation of the PARSEC Hooks Instrumentation API.
 *
 * In this file the hooks library functions are implemented. The hooks API
 * is defined in header file hooks.h.
 *
 * The default functionality can be enabled and disabled by defining the
 * corresponding macros in file config.h. A detailed description of all
 * features is available there.
 */

/* NOTE: A detailed description of each hook function is available in file
 *       hooks.h.
 */
#include "include/hooks.h"
#include "config.h"

#include <stdio.h>
#include <assert.h>

#ifdef ECOLABKNL_HOOKS /* Compile with KNL specific hooks */
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sched.h>
#include <stdbool.h>
#include <assert.h>
#include <stdarg.h>
#include <limits.h>
#include <sys/types.h>
#endif

#if ENABLE_TIMING
#include <sys/time.h>
/** \brief Time at beginning of execution of Region-of-Interest.
 *
 * This variable will store the time when the Region-of-Interest is entered.
 * time_begin and time_end allow an accurate measurement of the execution time
 * of the benchmark.
 *
 * Time measurement can be enabled in file config.h.
 */
static double time_begin;
/** \brief Time at end of execution of Region-of-Interest.
 *
 * This variable will store the time when the Region-of-Interest is left.
 * time_begin and time_end allow an accurate measurement of the execution time
 * of the benchmark.
 *
 * Time measurement can be enabled in file config.h.
 */
static double time_end;
#endif //ENABLE_TIMING

#if ENABLE_SETAFFINITY
#include <sched.h>
#include <stdlib.h>
#include <stdbool.h>
#endif //ENABLE_SETAFFINITY

/** Enable debugging code */
#define DEBUG 0

#if DEBUG
/* Counters to keep track of number of invocations of hooks */
static int num_bench_begins = 0;
static int num_roi_begins = 0;
static int num_roi_ends = 0;
static int num_bench_ends = 0;
#endif

/** \brief Variable for unique identifier of workload.
 *
 * This variable stores the unique identifier of the current benchmark program.
 * It is set in function __parsec_bench_begin().
 */
static enum __parsec_benchmark bench;

/* NOTE: Please look at hooks.h to see how these functions are used */

void __parsec_bench_begin(enum __parsec_benchmark __bench) {
  #if DEBUG
  num_bench_begins++;
  assert(num_bench_begins==1);
  assert(num_roi_begins==0);
  assert(num_roi_ends==0);
  assert(num_bench_ends==0);
  #endif //DEBUG

  printf(HOOKS_PREFIX" PARSEC Hooks Version "HOOKS_VERSION"\n");
  fflush(NULL);

  //Store global benchmark ID for other hook functions
  bench = __bench;

  #if ENABLE_SETAFFINITY
  //default values
  int cpu_num= CPU_SETSIZE;
  int cpu_base = 0;

  //check environment for desired affinity
  bool set_range = false;
  char *str_num = getenv(__PARSEC_CPU_NUM);
  char *str_base = getenv(__PARSEC_CPU_BASE);
  if(str_num != NULL) {
    cpu_num = atoi(str_num);
    set_range = true;
    if(str_base != NULL) {
      cpu_base = atoi(str_base);
      set_range = true;
    }
  }

  //check for legal values
  if(cpu_num < 1) {
    fprintf(stderr, HOOKS_PREFIX" Error: Too few CPUs selected.\n");
    exit(1);
  }
  if(cpu_base < 0) {
    fprintf(stderr, HOOKS_PREFIX" Error: CPU range base too small.\n");
    exit(1);
  }
  if(cpu_base + cpu_num > CPU_SETSIZE) {
    fprintf(stderr, HOOKS_PREFIX" Error: CPU range exceeds maximum value (%i).\n", CPU_SETSIZE-1);
    exit(1);
  }

  //set affinity
  if(set_range) {
    cpu_set_t mask;
    CPU_ZERO(&mask);
    int i;
    for(i = cpu_base; i < cpu_base + cpu_num; i++) {
      CPU_SET(i, &mask);
    }
    printf(HOOKS_PREFIX" Using %i CPUs (%i-%i)\n", cpu_num, cpu_base, cpu_base+cpu_num-1);
    sched_setaffinity(0, sizeof(mask), &mask);
  }
  #endif //ENABLE_SETAFFINITY
}

void __parsec_bench_end() {
  #if DEBUG
  num_bench_ends++;
  assert(num_bench_begins==1);
  assert(num_roi_begins==1);
  assert(num_roi_ends==1);
  assert(num_bench_ends==1);
  #endif //DEBUG

  fflush(NULL);
  #if ENABLE_TIMING
  printf(HOOKS_PREFIX" Total time spent in ROI: %.3fs\n", time_end-time_begin);
  #endif //ENABLE_TIMING
  printf(HOOKS_PREFIX" Terminating\n");
}

void __parsec_roi_begin() {
  #if DEBUG
  num_roi_begins++;
  assert(num_bench_begins==1);
  assert(num_roi_begins==1);
  assert(num_roi_ends==0);
  assert(num_bench_ends==0);
  #endif //DEBUG

  printf(HOOKS_PREFIX" Entering ROI\n");
  fflush(NULL);

  #if ENABLE_TIMING
  struct timeval t;
  gettimeofday(&t,NULL);
  time_begin = (double)t.tv_sec+(double)t.tv_usec*1e-6;
  #endif //ENABLE_TIMING

  #if ENABLE_SIMICS_MAGIC
  MAGIC_BREAKPOINT;
  #endif //ENABLE_SIMICS_MAGIC

  #if ENABLE_PTLSIM_TRIGGER
  ptlcall_switch_to_sim();
  #endif //ENABLE_PTLSIM_TRIGGER
}


void __parsec_roi_end() {
  #if DEBUG
  num_roi_ends++;
  assert(num_bench_begins==1);
  assert(num_roi_begins==1);
  assert(num_roi_ends==1);
  assert(num_bench_ends==0);
  #endif //DEBUG

  #if ENABLE_SIMICS_MAGIC
  MAGIC_BREAKPOINT;
  #endif //ENABLE_SIMICS_MAGIC

  #if ENABLE_PTLSIM_TRIGGER
  ptlcall_switch_to_native();
  #endif //ENABLE_PTLSIM_TRIGGER

  #if ENABLE_TIMING
  struct timeval t;
  gettimeofday(&t,NULL);
  time_end = (double)t.tv_sec+(double)t.tv_usec*1e-6;
  #endif //ENABLE_TIMING

  printf(HOOKS_PREFIX" Leaving ROI\n");
  fflush(NULL);
}


#ifdef ECOLABKNL_HOOKS
/* Hash Maps */
static int core_map[MAX_CPUS];
static int socket_map[MAX_CPUS];
static int L1i_map[MAX_CPUS];
static int L1d_map[MAX_CPUS];
static int L2_map[MAX_CPUS];
static int L3_map[MAX_CPUS];
static int core_cpu_matrix[MAX_CPUS][MAX_CPUS];
static int L2_cpu_matrix[MAX_CPUS][MAX_CPUS];
static int L3_cpu_matrix[MAX_CPUS][MAX_CPUS];
static int socket_cpu_matrix[MAX_CPUS][MAX_CPUS];
static int numcpus, numcores, numL2, numL3, numsockets;
static int thr2CPUMap[MAX_CPUS];
static bool cpu_topo_detected = false;

static int initialize_topology() {
	PRINTTOPO("Initializing Topology");
	unsigned int i, j;
#ifdef DEBUG_CPU_UARCH
	char log[BUFSIZ];
#endif

	for(i = 0; i < MAX_CPUS; i++) {
#ifdef DEBUG_CPU_UARCH
		sprintf(log,"Initializing CPU-%d details",i);
		PRINTTOPO(log);
#endif
		for(j = 0; j < MAX_CPUS; j++) {
			core_cpu_matrix[i][j]   = -1;
			L2_cpu_matrix[i][j]     = -1;
			L3_cpu_matrix[i][j]     = -1;
			socket_cpu_matrix[i][j] = -1;
		}
		core_map[i]   = -1;
		socket_map[i] = -1;
		L1i_map[i]    = -1;
		L1d_map[i]    = -1;
		L2_map[i]     = -1;
		L3_map[i]     = -1;
		thr2CPUMap[i] = -1;
	}
	numcpus           = -1;
	numcores          = -1;
	numsockets        = -1;
	numL2             = -1;
	numL3             = -1;
	cpu_topo_detected = false;
	return 0;
}

static void display_topology(const unsigned int *A, unsigned int m, unsigned int n, const char *rowname) {
	PRINTTOPO("Display Matrix Topology");
	unsigned int i, j;
	printf("%s\n",rowname);
	for(i = 0; i < MAX_CPUS; i++) {
		if (i < m) {
			printf("               %d|",i);
			for(j = 0; j < MAX_CPUS; j++) {
				if(j < n) {
					printf("%d\t",A[i*MAX_CPUS+j]);
				}
			}
			printf("\n");
		}
	}
}

int detect_cpu(void) {
	FILE *fff;
	int family,model=-1;
	char buffer[BUFSIZ],*result;
	char vendor[BUFSIZ];
	char printstmt[BUFSIZ];
	char printstmt1[BUFSIZ];
	char printstmt2[BUFSIZ];
	char printstmt3[BUFSIZ];

	fff=fopen("/proc/cpuinfo","r");
	if (fff==NULL) return -1;

	while(1) {
		result=fgets(buffer,BUFSIZ,fff);
		if (result==NULL) break;

		if (!strncmp(result,"vendor_id",8)) {
			sscanf(result,"%*s%*s%s",vendor);

			if (strncmp(vendor,"GenuineIntel",12)) {
				sprintf(printstmt,"%s not an Intel chip\n",vendor);
				PRINTTOPO(printstmt);
				return -1;
			}
		}

		if (!strncmp(result,"cpu family",10)) {
			sscanf(result,"%*s%*s%*s%d",&family);
			if (family!=6) {
				sprintf(printstmt,"Wrong CPU family %d\n",family);
				PRINTTOPO(printstmt);
				return -1;
			}
		}

		if (!strncmp(result,"model",5)) {
			sscanf(result,"%*s%*s%d",&model);
		}

	}
	fclose(fff);


	sprintf(printstmt1,"Found ");
	switch(model) {
		case CPU_SANDYBRIDGE:
			sprintf(printstmt2,"Sandybridge");
			break;
		case CPU_SANDYBRIDGE_EP:
			sprintf(printstmt2,"Sandybridge-EP");
			break;
		case CPU_IVYBRIDGE:
			sprintf(printstmt2,"Ivybridge");
			break;
		case CPU_IVYBRIDGE_EP:
			sprintf(printstmt2,"Ivybridge-EP");
			break;
		case CPU_HASWELL:
		case CPU_HASWELL_ULT:
		case CPU_HASWELL_GT3E:
			sprintf(printstmt2,"Haswell");
			break;
		case CPU_HASWELL_EP:
			sprintf(printstmt2,"Haswell-EP");
			break;
		case CPU_BROADWELL:
		case CPU_BROADWELL_GT3E:
			sprintf(printstmt2,"Broadwell");
			break;
		case CPU_BROADWELL_EP:
			sprintf(printstmt2,"Broadwell-EP");
			break;
		case CPU_SKYLAKE:
		case CPU_SKYLAKE_HS:
			sprintf(printstmt2,"Skylake");
			break;
		case CPU_SKYLAKE_X:
			sprintf(printstmt2,"Skylake-X");
			break;
		case CPU_KABYLAKE:
		case CPU_KABYLAKE_MOBILE:
			sprintf(printstmt2,"Kaby Lake");
			break;
		case CPU_KNIGHTS_LANDING:
			sprintf(printstmt2,"Knight's Landing");
			break;
		case CPU_KNIGHTS_MILL:
			sprintf(printstmt2,"Knight's Mill");
			break;
		case CPU_ATOM_GOLDMONT:
		case CPU_ATOM_GEMINI_LAKE:
		case CPU_ATOM_DENVERTON:
			sprintf(printstmt2,"Atom");
			break;
		default:
			sprintf(printstmt2,"Unsupported model %d\n",model);
			model=-1;
			break;
	}
	sprintf(printstmt3,"Processor : ");
	strcat(printstmt3,printstmt2);
	strcat(printstmt1,printstmt3);
	PRINTTOPO(printstmt1);
	
	initialize_topology();
	return model;
}


int detect_topology(cpu_topology_t *topo) {
	PRINTTOPO("Extracting CPU Topology");

	int model = detect_cpu();
	
	if (model < 0) {
		PRINTERROR("Ivalid CPU Model");
	}
	
	/* Obtain The Topology Information from lscpu */
	if(system("lscpu -p > topology.txt") < 0) {
		PRINTERROR("Unable to obtain topology Information");
	}
	PRINTTOPO("Topology.txt created");
	/* Obtain The static mapping Information */
	if(system("cp /home/amaity/Desktop/thrd_cpu_map.csv static_thr2cpu_map.csv")) {
		PRINTERROR("Unable to obtain the static map");	
	}
	PRINTTOPO("Static map created");

	/* Extract the information from topology.txt */
	FILE *fd = fopen("topology.txt","r");
	FILE *fc = fopen("static_thr2cpu_map.csv","r");
	if(!fd) {
		PRINTERROR("File topology.txt not found");
	}
	if(!fc) {
		PRINTERROR("File static_thr2cpu_map.csv not found");
	}

	char line[BUFSIZ];
	char *substr = "#\0";
	unsigned int i, j, col, cpu, node;

	i = 0;
	while(fgets(line,BUFSIZ,fd) > 0) {
		if (strstr(line,substr) != NULL) {
			/* Ignore */
		}
		else {
			if(model == CPU_KNIGHTS_LANDING) {
				/* 
                 * KNL doesnt have a L3 Cache
				 * -------------------------
				 * Please try to detect automatically the
				 * absence/presence of L3 cache. 
				 */
				sscanf(line,"%d,%d,%d,%d,,%d,%d,%d\n",\
				&cpu,&core_map[i],&socket_map[i],&node,\
				&L1i_map[i],&L1d_map[i],&L2_map[i]);
			} else {
				sscanf(line,"%d,%d,%d,%d,,%d,%d,%d,%d\n",\
				&cpu,&core_map[i],&socket_map[i],&node,\
				&L1i_map[i],&L1d_map[i],&L2_map[i],&L3_map[i]);
			}

			i++;
		}
	}
	numcpus = i;

	/* Obtain the core, L2, L3 and socket siblings */
	numcores   = numcpus;
	numsockets = numcpus;
	numL2      = numcpus;
	numL3      = numcpus;
	for(i = 0; i < numcores; i++) {
		col = 0;
		for(j = 0; j < numcpus; j++) {
			if (core_map[j] == i)
				core_cpu_matrix[i][col++] = j;
		}
		if (col == 0)
			break;
	}
	numcores = i;
	display_topology(&core_cpu_matrix[0][0],numcores,numcpus/numcores,"Core-id");

	for(i = 0; i < numL2; i++) {
		col = 0;
		for(j = 0; j < numcpus; j++) {
			if (L2_map[j] == i)
				L2_cpu_matrix[i][col++] = j;
		}
		if (col == 0)
			break;
	}
	numL2 = i;
	display_topology(&L2_cpu_matrix[0][0],numL2,numcpus/numL2,"L2-id");

	if (model != CPU_KNIGHTS_LANDING) {
		for(i = 0; i < numL3; i++) {
			col = 0;
			for(j = 0; j < numcpus; j++) {
				if (L3_map[j] == i)
					L3_cpu_matrix[i][col++] = j;
			}
			if (col == 0)
				break;
		}
		numL3 = i;
		display_topology(&L3_cpu_matrix[0][0],numL3,numcpus/numL3,"L3-id");
	} else {
		PRINTTOPO("No L3 cache for Xeon Phi series");
	}

	for(i = 0; i < numsockets; i++) {
		col = 0;
		for(j = 0; j < numcpus; j++) {
			if (socket_map[j] == i)
				socket_cpu_matrix[i][col++] = j;
		}
		if (col == 0)
			break;
	}
	numsockets = i;
	display_topology(&socket_cpu_matrix[0][0],numsockets,numcpus/numsockets,"socket-id");


	fclose(fd);
	topo->numcpus    = numcpus;
	topo->numcores   = numcores;
	topo->numsockets = numsockets;
	topo->model      = model;
	
	if(system("rm topology.txt") < 0) {
		PRINTERROR("Unable to obtain topology.txt");
	}
	PRINTTOPO("Topology.txt deleted");
	cpu_topo_detected = true;

	PRINTTOPO("Obtaining a static thread<---->CPU map");
	for(i=0; i<MAX_CPUS;i++) {
		if (fgets(line,BUFSIZ,fc) > 0) {
			//PRINTTOPO(line);
			sscanf(line,"%d,%d\n",&cpu,&thr2CPUMap[i]);
		}
	}
	return 0;
}


/**
 * setting ht_enable ensures that all the
 * the cpus are treated unique resources.
 * If it is disabled then each core is treated
 * a unique resource and all the computation is
 * affined to all the ht threads within a core.
 */
int affinity_set_cpu(int _id, bool ht_enable) {
	/* Change this for all micro-architectures */
	int thr_id, cpuid = -1;
	int numsiblings, i;
	if(!cpu_topo_detected) {
		PRINTERROR("CPUs and/or Topology not yet detected");
	}
	cpu_set_t set;
	CPU_ZERO(&set);

#ifdef DEBUG_CPU_UARCH	
	char log[BUFSIZ];
	sprintf(log,"numcpus = %d, cpuid = %d",numcpus,cpuid);
	PRINTTOPO(log);
#endif

	if (ht_enable) {
		thr_id       = _id % numcpus; /* Ensure that there is no overflow */
		cpuid        = thr2CPUMap[thr_id];
		CPU_SET(cpuid, 		&set);
	}
	else {
		/* treat the CPUID similar to core-id */
		cpuid       = _id % numcores; /* Ensure that there is no overflow */
		assert(numcores > 0);
		assert(numcpus  > 0);
		numsiblings = numcpus / numcores;
		for(i = 0; i < numsiblings; i++) {
			CPU_SET(core_cpu_matrix[cpuid][i],&set);
		}
	}
	int rc = sched_setaffinity(0,sizeof(cpu_set_t),&set);
	if(rc != 0) {
		fprintf(stderr,"Set Affinity failed for tid#%u\n",_id);
		exit(EXIT_FAILURE);
	}
	return cpuid;
}

#define SPINTIME 2
void ecolab_set_cpu_affinity(int _id) {
  int cpuid  = affinity_set_cpu(_id,true);
  char log[BUFSIZ];

  /* Busy Spins to ensure the thread has been affined */
  //int i, j, k;
  //for(i = 0; i < SPINTIME; i++) {
  //  for(j = 0; j < SPINTIME; j++) {
  //    for(k = 0; k < SPINTIME; k++);
  //   }
  //}
  sprintf(log,"Finished Spinning, thr@%d<------->@%d,actually running on cpu@%d",_id,cpuid,sched_getcpu());
  PRINTTOPO(log);
}

void ecolab_set_cpu_affinity2(int _id, const char *msg) {
  int cpuid  = affinity_set_cpu(_id,true);
  char log[BUFSIZ];

  sprintf(log,"%s : Finished Spinning, thr@%d<------->@%d,actually running on cpu@%d",msg,_id,cpuid,sched_getcpu());
  PRINTTOPO(log);
}

#endif /* ECOLABKNL_HOOKS */
