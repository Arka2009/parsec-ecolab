#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <time.h>
#include <assert.h>
#include "cpu_topology.h"
#include "pretty_print.h"

void init_app_info(app_info_t *app) {
    app->pid        = -1;
    app->numthreads = 0;
    int i;
    for(i = 0; i < MAX_THREADS; i++) {
        app->thr2cpuMap[i] = -1;
    }
}

void display_app_info(const app_info_t *app) {
    PRINTSCHED("----------APP-Structure--------");
    printf("pid : %d, numthreads : %d\n",app->pid,app->numthreads);
    PRINTSCHED("----------APP-Structure--------");
}

static inline pid_t launch_app(const char* binary, char *const arg[]) {
    int err;
    // Ensure that the shared libraries are loaded before
    /* Launch the application usig fork and exec */
    pid_t benchpid = fork();
    if (benchpid == 0) { /* Child Process */
        if (execv(binary,arg) < 0)
            perror("[launch_app] ");
        PRINTERROR("Binary couldn't be launched");
    } else {
        return benchpid;
    }
}

/* Launch Blackscholes wrapper */
int launch_blackscholes(unsigned int nt, app_info_t *app, const char *map_file) {
    char log[BUFSIZ];
    char nthreads[BUFSIZ];
    sprintf(nthreads,"%d",nt);
    app->numthreads = nt;

    /* Set the binary arguments */
    const char *binary = "/home/amaity/Desktop/parsec-3.0/pkgs/apps/blackscholes/inst/amd64-linux.gcc-hooks/bin/blackscholes";
    char *const arg[]  = {
        "/home/amaity/Desktop/parsec-3.0/pkgs/apps/blackscholes/inst/amd64-linux.gcc-hooks/bin/blackscholes",\
        nthreads,\
        "/home/amaity/Desktop/parsec-3.0/pkgs/apps/blackscholes/inputs/in_10M.txt",\
        "/home/amaity/Desktop/parsec-3.0/pkgs/apps/blackscholes/run/prices.txt",\
        (char*)0};
    
    /* Extract the thread to cpu mapping information */
    FILE *fc = fopen(map_file,"r");
    if(!fc) {
		PRINTERROR("Map File not found");
    }
    PRINTSCHED("Obtaining a static thread<---->CPU map");
    unsigned int i, cpu;
    char line[BUFSIZ];
	for(i=0; i<MAX_CPUS;i++) {
		if (fgets(line,BUFSIZ,fc) > 0) {
			//PRINTTOPO(line);
			sscanf(line,"%d,%d\n",&cpu,&app->thr2cpuMap[i]);
		}
    }

    /* Fork the process */
    pid_t pid = launch_app(binary,arg);
    app->pid  = pid;
    sprintf(log,"Started blackscholes with pid@%d\n",pid);
    return pid;
}

/* Launch Bodytrack wrapper */
pid_t launch_bodytrack(unsigned int nt, app_info_t *app, const char *map_file) {
    char log[BUFSIZ];
    char nthreads[BUFSIZ];
    sprintf(nthreads,"%d",nt);
    app->numthreads = nt;

    /* Set the binary arguments */
    const char *binary = "/home/amaity/Desktop/parsec-3.0/pkgs/apps/bodytrack/inst/amd64-linux.gcc-hooks/bin/bodytrack";
    char *const arg[]  = {
        "/home/amaity/Desktop/parsec-3.0/pkgs/apps/bodytrack/inst/amd64-linux.gcc-hooks/bin/bodytrack",\
        "/home/amaity/Desktop/parsec-3.0/pkgs/apps/bodytrack/inputs/sequenceB_261",\
        "4",\
        "261",\
        "4000",\
        "5",\
        "0",\
        nthreads,\
        (char*)0};
    
    /* Extract the thread to cpu mapping information */
    FILE *fc = fopen(map_file,"r");
    if(!fc) {
		PRINTERROR("Map File not found");
    }
    PRINTSCHED("Obtaining a static thread<---->CPU map");
    unsigned int i, cpu;
    char line[BUFSIZ];
	for(i=0; i<MAX_CPUS;i++) {
		if (fgets(line,BUFSIZ,fc) > 0) {
			//PRINTTOPO(line);
			sscanf(line,"%d,%d\n",&cpu,&app->thr2cpuMap[i]);
		}
    }

    pid_t pid = launch_app(binary,arg);
    app->pid  = pid;
    sprintf(log,"Started bodytrack with pid@%d\n",pid);
    return pid;
}

/* Launch canneal wrapper */
pid_t launch_canneal(unsigned int nt, app_info_t *app, const char *map_file) {
    char log[BUFSIZ];
    char nthreads[BUFSIZ];
    sprintf(nthreads,"%d",nt);
    app->numthreads = nt;

    const char *binary = "/home/amaity/Desktop/parsec-3.0/pkgs/kernels/canneal/inst/amd64-linux.gcc-hooks/bin/canneal";
    char *const arg[]  = {
        "/home/amaity/Desktop/parsec-3.0/pkgs/kernels/canneal/inst/amd64-linux.gcc-hooks/bin/canneal",\
        nthreads,\
        "15000",\
        "2000",\
        "/home/amaity/Desktop/parsec-3.0/pkgs/kernels/canneal/inputs/2500000.nets",\
        "6000",\
        (char*)0};

    /* Extract the thread to cpu mapping information */
    FILE *fc = fopen(map_file,"r");
    if(!fc) {
		PRINTERROR("Map File not found");
    }
    PRINTSCHED("Obtaining a static thread<---->CPU map");
    unsigned int i, cpu;
    char line[BUFSIZ];
	for(i=0; i<MAX_CPUS;i++) {
		if (fgets(line,BUFSIZ,fc) > 0) {
			//PRINTTOPO(line);
			sscanf(line,"%d,%d\n",&cpu,&app->thr2cpuMap[i]);
		}
    }

    pid_t pid = launch_app(binary,arg);
    app->pid  = pid;
    sprintf(log,"Started canneal with pid@%d\n",pid);
    return pid;
}

/* Launch dedup wrapper */
pid_t launch_dedup(unsigned int nt, app_info_t *app, const char *map_file) {
    char log[BUFSIZ];
    char nthreads[BUFSIZ];
    sprintf(nthreads,"%d",nt);
    app->numthreads = nt;

    const char *binary = "/home/amaity/Desktop/parsec-3.0/pkgs/kernels/dedup/inst/amd64-linux.gcc-hooks/bin/dedup";
    char *const arg[]  = {
        "/home/amaity/Desktop/parsec-3.0/pkgs/kernels/dedup/inst/amd64-linux.gcc-hooks/bin/dedup",\
        "-c",\
        "-p",\
        "-v",\
        "-t",\
        nthreads,\
        "-i",\
        "/home/amaity/Desktop/parsec-3.0/pkgs/kernels/dedup/inputs/FC-6-x86_64-disc1.iso",\
        "-o",\
        "dump/output.dat.ddp",\
        (char*)0};

    /* Extract the thread to cpu mapping information */
    FILE *fc = fopen(map_file,"r");
    if(!fc) {
		PRINTERROR("Map File not found");
    }
    PRINTSCHED("Obtaining a static thread<---->CPU map");
    unsigned int i, cpu;
    char line[BUFSIZ];
	for(i=0; i<MAX_CPUS;i++) {
		if (fgets(line,BUFSIZ,fc) > 0) {
			//PRINTTOPO(line);
			sscanf(line,"%d,%d\n",&cpu,&app->thr2cpuMap[i]);
		}
    }

    pid_t pid = launch_app(binary,arg);
    app->pid  = pid;
    sprintf(log,"Started dedup with pid@%d\n",pid);
    return pid;
}

/* Launch ferret wrapper */
pid_t launch_ferret(unsigned int nt, app_info_t *app, const char *map_file) {
    char log[BUFSIZ];
    char nthreads[BUFSIZ];
    sprintf(nthreads,"%d",nt);
    app->numthreads = nt;

    const char *binary = "/home/amaity/Desktop/parsec-3.0/pkgs/apps/ferret/inst/amd64-linux.gcc-hooks/bin/ferret";
    char *const arg[]  = {
        "/home/amaity/Desktop/parsec-3.0/pkgs/apps/ferret/inst/amd64-linux.gcc-hooks/bin/ferret",\
        "/home/amaity/Desktop/parsec-3.0/pkgs/apps/ferret/inputs/corel",\
        "lsh",\
        "/home/amaity/Desktop/parsec-3.0/pkgs/apps/ferret/inputs/queries",\
        "50",\
        "20",\
        nthreads,\
        "dump/output.txt",\
        (char*)0};

    /* Extract the thread to cpu mapping information */
    FILE *fc = fopen(map_file,"r");
    if(!fc) {
		PRINTERROR("Map File not found");
    }
    PRINTSCHED("Obtaining a static thread<---->CPU map");
    unsigned int i, cpu;
    char line[BUFSIZ];
	for(i=0; i<MAX_CPUS;i++) {
		if (fgets(line,BUFSIZ,fc) > 0) {
			//PRINTTOPO(line);
			sscanf(line,"%d,%d\n",&cpu,&app->thr2cpuMap[i]);
		}
    }

    pid_t pid = launch_app(binary,arg);
    app->pid  = pid;
    sprintf(log,"Started ferret with pid@%d\n",pid);
    return pid;
}

/* Launch fluidanimate wrapper */
pid_t launch_fluidanimate(unsigned int nt, app_info_t *app, const char *map_file) {
    char log[BUFSIZ];
    char nthreads[BUFSIZ];
    sprintf(nthreads,"%d",nt);
    app->numthreads = nt;

    const char *binary = "/home/amaity/Desktop/parsec-3.0/pkgs/apps/fluidanimate/inst/amd64-linux.gcc-hooks/bin/fluidanimate";
    char *const arg[]  = {
        "/home/amaity/Desktop/parsec-3.0/pkgs/apps/fluidanimate/inst/amd64-linux.gcc-hooks/bin/fluidanimate",\
        nthreads,\
        "500",\
        "/home/amaity/Desktop/parsec-3.0/pkgs/apps/fluidanimate/inputs/in_500K.fluid",\
        "dump/out.fluid",\
        (char*)0};

    /* Extract the thread to cpu mapping information */
    FILE *fc = fopen(map_file,"r");
    if(!fc) {
		PRINTERROR("Map File not found");
    }
    PRINTSCHED("Obtaining a static thread<---->CPU map");
    unsigned int i, cpu;
    char line[BUFSIZ];
	for(i=0; i<MAX_CPUS;i++) {
		if (fgets(line,BUFSIZ,fc) > 0) {
			//PRINTTOPO(line);
			sscanf(line,"%d,%d\n",&cpu,&app->thr2cpuMap[i]);
		}
    }

    pid_t pid = launch_app(binary,arg);
    app->pid  = pid;
    sprintf(log,"Started fluidanimate with pid@%d\n",pid);
    return pid;
}

/* Launch raytrace wrapper */
pid_t launch_raytrace(unsigned int nt, app_info_t *app, const char *map_file) {
    char log[BUFSIZ];
    char nthreads[BUFSIZ];
    sprintf(nthreads,"%d",nt);
    app->numthreads = nt;

    const char *binary = "/home/amaity/Desktop/parsec-3.0/pkgs/apps/raytrace/inst/amd64-linux.gcc-hooks/bin/rtview";
    char *const arg[]  = {
        "/home/amaity/Desktop/parsec-3.0/pkgs/apps/raytrace/inst/amd64-linux.gcc-hooks/bin/rtview",\
        "/home/amaity/Desktop/parsec-3.0/pkgs/apps/raytrace/inputs/thai_statue.obj",\
        "-automove",\
        "-nthreads ",\
        nthreads,\
        "-frames",\
        "200",\
        "-res",\
        "1920",\
        "1080",\
        (char*)0};

    /* Extract the thread to cpu mapping information */
    FILE *fc = fopen(map_file,"r");
    if(!fc) {
		PRINTERROR("Map File not found");
    }
    PRINTSCHED("Obtaining a static thread<---->CPU map");
    unsigned int i, cpu;
    char line[BUFSIZ];
	for(i=0; i<MAX_CPUS;i++) {
		if (fgets(line,BUFSIZ,fc) > 0) {
			//PRINTTOPO(line);
			sscanf(line,"%d,%d\n",&cpu,&app->thr2cpuMap[i]);
		}
    }

    pid_t pid = launch_app(binary,arg);
    app->pid  = pid;
    sprintf(log,"Started raytrace with pid@%d\n",pid);
    return pid;
}

/* Launch swaptions wrapper */
pid_t launch_swaptions(unsigned int nt, app_info_t *app, const char *map_file) {
    char log[BUFSIZ];
    char nthreads[BUFSIZ];
    sprintf(nthreads,"%d",nt);
    app->numthreads = nt;

    const char *binary = "/home/amaity/Desktop/parsec-3.0/pkgs/apps/swaptions/inst/amd64-linux.gcc-hooks/bin/swaptions";
    char *const arg[]  = {
        "/home/amaity/Desktop/parsec-3.0/pkgs/apps/swaptions/inst/amd64-linux.gcc-hooks/bin/swaptions",\
        "-ns",\
        "128",\
        "-sm",\
        "1000000",\
        "-nt",\
        nthreads,\
        (char*)0};

    /* Extract the thread to cpu mapping information */
    FILE *fc = fopen(map_file,"r");
    if(!fc) {
		PRINTERROR("Map File not found");
    }
    PRINTSCHED("Obtaining a static thread<---->CPU map");
    unsigned int i, cpu;
    char line[BUFSIZ];
	for(i=0; i<MAX_CPUS;i++) {
		if (fgets(line,BUFSIZ,fc) > 0) {
			//PRINTTOPO(line);
			sscanf(line,"%d,%d\n",&cpu,&app->thr2cpuMap[i]);
		}
    }

    pid_t pid = launch_app(binary,arg);
    app->pid  = pid;
    sprintf(log,"Started swaptions with pid@%d\n",pid);
    return pid;
}

/* Launch streamcluster wrapper */
pid_t launch_streamcluster(unsigned int nt, app_info_t *app, const char *map_file) {
    char log[BUFSIZ];
    char nthreads[BUFSIZ];
    sprintf(nthreads,"%d",nt);
    app->numthreads = nt;

    const char *binary = "/home/amaity/Desktop/parsec-3.0/pkgs/kernels/streamcluster/inst/amd64-linux.gcc-hooks/bin/streamcluster";
    char *const arg[]  = {
        "/home/amaity/Desktop/parsec-3.0/pkgs/kernels/streamcluster/inst/amd64-linux.gcc-hooks/bin/streamcluster",\
        "10",\
        "20",\
        "128",\
        "1000000",\
        "200000",\
        "5000",\
        "none",\
        "dump/output.txt",\
        nthreads,\
        (char*)0};

    /* Extract the thread to cpu mapping information */
    FILE *fc = fopen(map_file,"r");
    if(!fc) {
		PRINTERROR("Map File not found");
    }
    PRINTSCHED("Obtaining a static thread<---->CPU map");
    unsigned int i, cpu;
    char line[BUFSIZ];
	for(i=0; i<MAX_CPUS;i++) {
		if (fgets(line,BUFSIZ,fc) > 0) {
			//PRINTTOPO(line);
			sscanf(line,"%d,%d\n",&cpu,&app->thr2cpuMap[i]);
		}
    }

    pid_t pid = launch_app(binary,arg);
    app->pid  = pid;
    sprintf(log,"Started streamcluster with pid@%d\n",pid);
    return pid;
}


bool waitapp(const app_info_t *apps, int num_apps) {
    int i, status, rc;
    char log[BUFSIZ];
    bool all_apps_finished = true;
    for(i = 0; i < num_apps; i++) {
        rc = waitpid(apps[i].pid,&status,WNOHANG);
        if (rc < 0) {
            sprintf(log,"wait failed on App-%d",apps[i].pid);
            perror(log);
            PRINTERROR(log);
        } else if (rc > 0) {
            sprintf(log,"App-%d finished",apps[i].pid);
            PRINTSCHED(log);
            all_apps_finished = all_apps_finished & true;
        } else {
            all_apps_finished = all_apps_finished & false;
        }
    }
    return all_apps_finished;
}