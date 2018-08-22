#ifndef _CPU_TOPOLOGY_H
#define _CPU_TOPOLOGY_H

#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
#include "sched_params.h"
#include "launch_app.h"

/* CPU Model codes */
#define CPU_SANDYBRIDGE		    42
#define CPU_SANDYBRIDGE_EP	    45
#define CPU_IVYBRIDGE		    58
#define CPU_IVYBRIDGE_EP	    62
#define CPU_HASWELL		        60
#define CPU_HASWELL_ULT		    69
#define CPU_HASWELL_GT3E	    70
#define CPU_HASWELL_EP		    63
#define CPU_BROADWELL		    61
#define CPU_BROADWELL_GT3E	    71
#define CPU_BROADWELL_EP	    79
#define CPU_BROADWELL_DE	    86
#define CPU_SKYLAKE		        78
#define CPU_SKYLAKE_HS		    94
#define CPU_SKYLAKE_X		    85
#define CPU_KNIGHTS_LANDING	    87
#define CPU_KNIGHTS_MILL	    133
#define CPU_KABYLAKE_MOBILE	    142
#define CPU_KABYLAKE		    158
#define CPU_ATOM_SILVERMONT	    55
#define CPU_ATOM_AIRMONT	    76
#define CPU_ATOM_MERRIFIELD	    74
#define CPU_ATOM_MOOREFIELD	    90
#define CPU_ATOM_GOLDMONT	    92
#define CPU_ATOM_GEMINI_LAKE	122
#define CPU_ATOM_DENVERTON	    95

typedef struct __cpu_topo {
	unsigned int numcpus;
	unsigned int numcores;
	unsigned int numsockets;
	int model;
} cpu_topology_t;

/* The first two functions are "initialization" routines must be called before any of the affinity functions are called */
int  detect_cpu(void);
int  detect_topology(cpu_topology_t*);

/* Affinity Functions */
int affinity_set_cpu(const pid_t pid, int _id, const unsigned int thr2CPUMap[], const unsigned int numthreads);
long long calculate_time_diff_spec(struct timespec, struct timespec);

/* Affine all the threads of an applications */
void affine_app(const app_info_t *app);

#endif /* _CPU_TOPOLOGY_H */