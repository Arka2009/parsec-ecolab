#ifndef _SCHEDPARAMS_H
#define _SCHEDPARAMS_H

#define MAX_CPUS	                    256
#define MAX_ARGS                        15            /* Maximum Number of arguments of any benchmark applications */
#define SCHED_EPOCH_LENGTH              10000         /* In microsecond */
#define MAX_THREADS                     256           /* Maximum number of threads an application can launch at any point */
#define MAX_APPS                        300           /* Maximum Application, that can be supported in the system */
#define LIM_AFFINE_ITER                 5             /* limit the number of iterations schedule_affine_map is called */
//#define VTUNE_PROFILE                                 /* Enable VTune profiling */

#endif /* _SCHEDPARAMS_H */