#define _GNU_SOURCE
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sched.h>
#include <stdbool.h>
#include <assert.h>
#include <stdarg.h>
#include <limits.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include "cpu_topology.h"
#include "pretty_print.h"
#include "sched_params.h"
#include "launch_app.h"

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
static bool cpu_topo_detected = false;

/* Compute t2 - t1 */
inline long long calculate_time_diff_spec(struct timespec t2, struct timespec t1) {
    long long elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000000000LL + t2.tv_nsec - t1.tv_nsec;
    return elapsedTime;
}

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

	char *dir = getenv("PARSECROOT");
    if(!dir) {
        PRINTERROR("Please set PARSECROOT!!!\n");
    }
	char command[BUFSIZ];
	
	/* Obtain The Topology Information from lscpu */
	if(system("lscpu -p > topology.txt") < 0) {
		PRINTERROR("Unable to obtain topology Information");
	}
	//PRINTTOPO("Topology.txt created");

	/* Extract the information from topology.txt */
	FILE *fd = fopen("topology.txt","r");
	if(!fd) {
		PRINTERROR("File topology.txt not found");
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
	//display_topology(&core_cpu_matrix[0][0],numcores,numcpus/numcores,"Core-id");

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
	//display_topology(&L2_cpu_matrix[0][0],numL2,numcpus/numL2,"L2-id");

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
	//display_topology(&socket_cpu_matrix[0][0],numsockets,numcpus/numsockets,"socket-id");


	fclose(fd);
	topo->numcpus    = numcpus;
	topo->numcores   = numcores;
	topo->numsockets = numsockets;
	topo->model      = model;
	
	if(system("rm topology.txt") < 0) {
		PRINTERROR("Unable to obtain topology.txt");
	}
	//PRINTTOPO("Topology.txt deleted");
	cpu_topo_detected = true;
	return 0;
}

/**
 * Supply the PID and a static map table
 * inorder to correctly affine a thread/task
 */
int affinity_set_cpu(const pid_t pid, int _id, const unsigned int thr2CPUMap[], const unsigned int numthreads) {
		// PRINTTOPO("Obtaining a static thread<---->CPU map");
	// for(i=0; i<MAX_CPUS;i++) {
	// 	if (fgets(line,BUFSIZ,fc) > 0) {
	// 		//PRINTTOPO(line);
	// 		sscanf(line,"%d,%d\n",&cpu,&thr2CPUMap[i]);
	// 	}
	// }
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
	thr_id       = _id % MAX_CPUS; /* Ensure that there is no overflow */
	cpuid        = thr2CPUMap[thr_id];
	CPU_SET(cpuid,&set);

	int rc = sched_setaffinity(pid,sizeof(cpu_set_t),&set);
	if(rc != 0) {
		char log[BUFSIZ];
		sprintf(log,"Affinity failed for LWP@%d-tid@%u : ",pid,_id);
		perror(log);
	}
	return cpuid;
}

/* Affine all the threads of an applications */
void affine_app(const app_info_t *app) {
    struct timespec t1, t2;
    long long t2t1;
    clock_gettime(CLOCK_REALTIME,&t1);

    char dirname[BUFSIZ];
    char log[BUFSIZ];
    unsigned int num_tid = 0;
    unsigned int linux_taskid[MAX_THREADS];
    unsigned int i;

	/* Extract the parameters */
	const pid_t pid                 = app->pid;
	const unsigned int *thr2CPUMap  = app->thr2cpuMap;
	const unsigned int numthreads   = app->numthreads;

    /* Obtain the TIDs of all the slave threads */
    sprintf(dirname,"/proc/%d/task",pid);
    DIR *proc_dir = opendir(dirname);
    if(proc_dir) {
        struct dirent *entry;
        while((entry = readdir(proc_dir)) != NULL) {
            if(entry->d_name[0] == '.')
                continue;
            int tid = atoi(entry->d_name);
            linux_taskid[num_tid++] = tid;
        }
    } else {
        sprintf(log,"Application process-%s doesn't Exists",dirname);
        perror(log);
        PRINTERROR(log);
    }
    closedir(proc_dir);

    /* Appropriately (and statically) affine the master and the slave threads */
    for (i = 0; i < num_tid; i++) {
        if(i == 0) {
            assert(pid == linux_taskid[i]); /* Ensure the pid and master (linux) taskid are same */
            affinity_set_cpu(pid,0,thr2CPUMap,numthreads);
        } else {
            //printf("num_tid = %d, i = %d\n",num_tid,i);
            affinity_set_cpu(linux_taskid[i],i,thr2CPUMap,numthreads);
        }
    }

	/* Also affine the appropriate NUMA domain */
    clock_gettime(CLOCK_REALTIME,&t2);
    t2t1 = calculate_time_diff_spec(t2,t1);
}