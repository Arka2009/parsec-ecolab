//!/usr/bin/python3

// Launch The applications
// ---- APP1 (store the pid/tids)
// ---- APP2 (store the pid/tids)
// ---- APP3 (store the pid/tids)

// while(1) {
// Get the APP1-3 usage statistics
// Affine the pid/tids appropriatly
// }
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
#include "launch_app.h"

/* Schedule a list of apps */
void schedule_affine_map(app_info_t *app, unsigned int num) {
    unsigned int i, j = 0;
    while(1) {
        for(i = 0; i < num; i++) 
            affine_app(&app[i]);
        
        /* Check if all the child processes has exited */
        /* Non blocking wait for all the child processes */
        if (waitapp(app,num)) 
            break;
        
        /* Sleep for rest of scheduling epoch */
        usleep(SCHED_EPOCH_LENGTH);
    }
}

void exp1a_alloc1() {
     PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    app_info_t app[MAX_APPS];
    char *map_file2 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/exp1a_alloc1.csv";
    unsigned int nthreads = 1;

    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    init_app_info(&app[0]);
    launch_blackscholes(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1a_alloc1 Finished : blackscholes finished");
    

    init_app_info(&app[0]);
    launch_bodytrack(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1a_alloc1 Finished : bodytrack finished");
    

    init_app_info(&app[0]);
    launch_canneal(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1a_alloc1 Finished : canneal finished");
    

    init_app_info(&app[0]);
    launch_dedup(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1a_alloc1 Finished : dedup finished");
    

    init_app_info(&app[0]);
    launch_ferret(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1a_alloc1 Finished : ferret finished");
    

    init_app_info(&app[0]);
    launch_fluidanimate(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1a_alloc1 Finished : fluidanimate finished");
    

    init_app_info(&app[0]);
    launch_raytrace(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1a_alloc1 Finished : raytrace finished");
    

    init_app_info(&app[0]);
    launch_streamcluster(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1a_alloc1 Finished : streamcluster finished");
    

    init_app_info(&app[0]);
    launch_swaptions(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1a_alloc1 Finished : swaptions finished");
    
}

void exp1a_alloc2() {
     PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    app_info_t app[MAX_APPS];
    char *map_file2 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/exp1a_alloc2.csv";
    unsigned int nthreads = 1;

    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    init_app_info(&app[0]);
    launch_blackscholes(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1a_alloc2 Finished : blackscholes finished");
    

    init_app_info(&app[0]);
    launch_bodytrack(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1a_alloc2 Finished : bodytrack finished");
    

    init_app_info(&app[0]);
    launch_canneal(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1a_alloc2 Finished : canneal finished");
    

    init_app_info(&app[0]);
    launch_dedup(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1a_alloc2 Finished : dedup finished");
    

    init_app_info(&app[0]);
    launch_ferret(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1a_alloc2 Finished : ferret finished");
    

    init_app_info(&app[0]);
    launch_fluidanimate(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1a_alloc2 Finished : fluidanimate finished");
    

    init_app_info(&app[0]);
    launch_raytrace(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1a_alloc2 Finished : raytrace finished");
    

    init_app_info(&app[0]);
    launch_streamcluster(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1a_alloc2 Finished : streamcluster finished");
    

    init_app_info(&app[0]);
    launch_swaptions(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1a_alloc2 Finished : swaptions finished");
    
}

void exp1b_alloc1() {
     PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    app_info_t app[MAX_APPS];
    char *map_file2 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/exp1b_alloc1.csv";
    unsigned int nthreads = 3;

    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    init_app_info(&app[0]);
    launch_blackscholes(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1b_alloc1 Finished : blackscholes finished");
    

    init_app_info(&app[0]);
    launch_bodytrack(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1b_alloc1 Finished : bodytrack finished");
    

    init_app_info(&app[0]);
    launch_canneal(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1b_alloc1 Finished : canneal finished");
    

    init_app_info(&app[0]);
    launch_dedup(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1b_alloc1 Finished : dedup finished");
    

    init_app_info(&app[0]);
    launch_ferret(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1b_alloc1 Finished : ferret finished");
    

    init_app_info(&app[0]);
    launch_fluidanimate(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1b_alloc1 Finished : fluidanimate finished");
    

    init_app_info(&app[0]);
    launch_raytrace(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1b_alloc1 Finished : raytrace finished");
    

    init_app_info(&app[0]);
    launch_streamcluster(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1b_alloc1 Finished : streamcluster finished");
    

    init_app_info(&app[0]);
    launch_swaptions(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1b_alloc1 Finished : swaptions finished");
    
}

void exp1b_alloc2() {
     PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    app_info_t app[MAX_APPS];
    char *map_file2 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/exp1b_alloc2.csv";
    unsigned int nthreads = 3;

    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    init_app_info(&app[0]);
    launch_blackscholes(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1b_alloc2 Finished : blackscholes finished");
    

    init_app_info(&app[0]);
    launch_bodytrack(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1b_alloc2 Finished : bodytrack finished");
    

    init_app_info(&app[0]);
    launch_canneal(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1b_alloc2 Finished : canneal finished");
    

    init_app_info(&app[0]);
    launch_dedup(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1b_alloc2 Finished : dedup finished");
    

    init_app_info(&app[0]);
    launch_ferret(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1b_alloc2 Finished : ferret finished");
    

    init_app_info(&app[0]);
    launch_fluidanimate(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1b_alloc2 Finished : fluidanimate finished");
    

    init_app_info(&app[0]);
    launch_raytrace(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1b_alloc2 Finished : raytrace finished");
    

    init_app_info(&app[0]);
    launch_streamcluster(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1b_alloc2 Finished : streamcluster finished");
    

    init_app_info(&app[0]);
    launch_swaptions(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp1b_alloc2 Finished : swaptions finished");
    
}

void exp2a_alloc1() {
     PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    app_info_t app[MAX_APPS];
    char *map_file2 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/exp2a_alloc1.csv";
    unsigned int nthreads = 1;

    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    init_app_info(&app[0]);
    launch_blackscholes(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc1 Finished : blackscholes finished");

    init_app_info(&app[0]);
    launch_bodytrack(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc1 Finished : bodytrack finished");
    

    init_app_info(&app[0]);
    launch_canneal(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc1 Finished : canneal finished");
    

    init_app_info(&app[0]);
    launch_dedup(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc1 Finished : dedup finished");
    

    init_app_info(&app[0]);
    launch_ferret(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc1 Finished : ferret finished");
    

    init_app_info(&app[0]);
    launch_fluidanimate(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc1 Finished : fluidanimate finished");
    

    init_app_info(&app[0]);
    launch_raytrace(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc1 Finished : raytrace finished");

    init_app_info(&app[0]);
    launch_streamcluster(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc1 Finished : streamcluster finished");

    init_app_info(&app[0]);
    launch_swaptions(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc1 Finished : swaptions finished");
}

/**
 * The benchmarks are encoded trivially
 * in lexicographic order starting from 0
 */
void exp2a_alloc1_simsmall() {
     PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    app_info_t app[MAX_APPS];
    char *map_file2 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/exp2a_alloc1.csv";
    unsigned int nthreads = 1;

    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    init_app_info(&app[0]);
    launch_blackscholes_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc1 Finished : blackscholes finished");
           
    init_app_info(&app[0]);
    launch_bodytrack_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc1 Finished : bodytrack finished");
            
    init_app_info(&app[0]);
    launch_canneal_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc1 Finished : canneal finished");
            
    init_app_info(&app[0]);
    launch_dedup_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc1 Finished : dedup finished");

    init_app_info(&app[0]);
    launch_ferret_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc1 Finished : ferret finished");
    
    init_app_info(&app[0]);
    launch_fluidanimate_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc1 Finished : fluidanimate finished");
    
    init_app_info(&app[0]);
    launch_raytrace_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc1 Finished : raytrace finished");

    init_app_info(&app[0]);
    launch_streamcluster_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc1 Finished : streamcluster finished");

    init_app_info(&app[0]);
    launch_swaptions_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc1 Finished : swaptions finished");
}

void exp2a_alloc2() {
     PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    app_info_t app[MAX_APPS];
    char *map_file2 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/exp2a_alloc2.csv";
    unsigned int nthreads = 1;

    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    init_app_info(&app[0]);
    launch_blackscholes(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc2 Finished : blackscholes finished");
    

    init_app_info(&app[0]);
    launch_bodytrack(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc2 Finished : bodytrack finished");
    

    init_app_info(&app[0]);
    launch_canneal(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc2 Finished : canneal finished");
    

    init_app_info(&app[0]);
    launch_dedup(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc2 Finished : dedup finished");
    

    init_app_info(&app[0]);
    launch_ferret(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc2 Finished : ferret finished");
    

    init_app_info(&app[0]);
    launch_fluidanimate(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc2 Finished : fluidanimate finished");
    

    init_app_info(&app[0]);
    launch_raytrace(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc2 Finished : raytrace finished");
    

    init_app_info(&app[0]);
    launch_streamcluster(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc2 Finished : streamcluster finished");
    

    init_app_info(&app[0]);
    launch_swaptions(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc2 Finished : swaptions finished");
    
}

void exp2a_alloc2_simsmall() {
     PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    app_info_t app[MAX_APPS];
    char *map_file2 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/exp2a_alloc2.csv";
    unsigned int nthreads = 1;

    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    init_app_info(&app[0]);
    launch_blackscholes_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc2 Finished : blackscholes finished");
    

    init_app_info(&app[0]);
    launch_bodytrack_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc2 Finished : bodytrack finished");
    

    init_app_info(&app[0]);
    launch_canneal_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc2 Finished : canneal finished");
    

    init_app_info(&app[0]);
    launch_dedup_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc2 Finished : dedup finished");
    

    init_app_info(&app[0]);
    launch_ferret_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc2 Finished : ferret finished");
    

    init_app_info(&app[0]);
    launch_fluidanimate_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc2 Finished : fluidanimate finished");
    

    init_app_info(&app[0]);
    launch_raytrace_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc2 Finished : raytrace finished");
    

    init_app_info(&app[0]);
    launch_streamcluster_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc2 Finished : streamcluster finished");
    

    init_app_info(&app[0]);
    launch_swaptions_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2a_alloc2 Finished : swaptions finished");
    
}


void exp2b_alloc1() {
     PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    app_info_t app[MAX_APPS];
    char *map_file2 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/exp2b_alloc1.csv";
    unsigned int nthreads = 3;
    
    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    init_app_info(&app[0]);
    launch_blackscholes(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc1 Finished : blackscholes finished");
    

    init_app_info(&app[0]);
    launch_bodytrack(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc1 Finished : bodytrack finished");
    

    init_app_info(&app[0]);
    launch_canneal(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc1 Finished : canneal finished");
    

    init_app_info(&app[0]);
    launch_dedup(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc1 Finished : dedup finished");
    

    init_app_info(&app[0]);
    launch_ferret(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc1 Finished : ferret finished");
    

    init_app_info(&app[0]);
    launch_fluidanimate(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc1 Finished : fluidanimate finished");
    

    init_app_info(&app[0]);
    launch_raytrace(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc1 Finished : raytrace finished");
    

    init_app_info(&app[0]);
    launch_streamcluster(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc1 Finished : streamcluster finished");
    

    init_app_info(&app[0]);
    launch_swaptions(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc1 Finished : swaptions finished");
    
}

void exp2b_alloc1_simsmall() {
     PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    app_info_t app[MAX_APPS];
    char *map_file2 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/exp2b_alloc1.csv";
    unsigned int nthreads = 3;
    
    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    init_app_info(&app[0]);
    launch_blackscholes_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc1 Finished : blackscholes finished");
    

    init_app_info(&app[0]);
    launch_bodytrack_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc1 Finished : bodytrack finished");
    

    init_app_info(&app[0]);
    launch_canneal_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc1 Finished : canneal finished");
    

    init_app_info(&app[0]);
    launch_dedup_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc1 Finished : dedup finished");
    

    init_app_info(&app[0]);
    launch_ferret_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc1 Finished : ferret finished");
    

    init_app_info(&app[0]);
    launch_fluidanimate_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc1 Finished : fluidanimate finished");
    

    init_app_info(&app[0]);
    launch_raytrace_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc1 Finished : raytrace finished");
    

    init_app_info(&app[0]);
    launch_streamcluster_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc1 Finished : streamcluster finished");
    

    init_app_info(&app[0]);
    launch_swaptions_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc1 Finished : swaptions finished");
    
}


void exp2b_alloc2() {
     PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    app_info_t app[MAX_APPS];
    char *map_file2 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/exp2b_alloc2.csv";
    unsigned int nthreads = 3;

    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    init_app_info(&app[0]);
    launch_blackscholes(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc2 Finished : blackscholes finished");
    

    init_app_info(&app[0]);
    launch_bodytrack(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc2 Finished : bodytrack finished");
    

    init_app_info(&app[0]);
    launch_canneal(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc2 Finished : canneal finished");
    

    init_app_info(&app[0]);
    launch_dedup(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc2 Finished : dedup finished");
    

    init_app_info(&app[0]);
    launch_ferret(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc2 Finished : ferret finished");
    

    init_app_info(&app[0]);
    launch_fluidanimate(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc2 Finished : fluidanimate finished");
    

    init_app_info(&app[0]);
    launch_raytrace(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc2 Finished : raytrace finished");
    

    init_app_info(&app[0]);
    launch_streamcluster(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc2 Finished : streamcluster finished");
    

    init_app_info(&app[0]);
    launch_swaptions(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc2 Finished : swaptions finished");
    
}

void exp2b_alloc2_simsmall() {
     PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    app_info_t app[MAX_APPS];
    char *map_file2 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/exp2b_alloc2.csv";
    unsigned int nthreads = 3;

    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    init_app_info(&app[0]);
    launch_blackscholes_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc2 Finished : blackscholes finished");
    

    init_app_info(&app[0]);
    launch_bodytrack_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc2 Finished : bodytrack finished");
    

    init_app_info(&app[0]);
    launch_canneal_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc2 Finished : canneal finished");
    

    init_app_info(&app[0]);
    launch_dedup_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc2 Finished : dedup finished");
    

    init_app_info(&app[0]);
    launch_ferret_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc2 Finished : ferret finished");
    

    init_app_info(&app[0]);
    launch_fluidanimate_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc2 Finished : fluidanimate finished");
    

    init_app_info(&app[0]);
    launch_raytrace_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc2 Finished : raytrace finished");
    

    init_app_info(&app[0]);
    launch_streamcluster_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc2 Finished : streamcluster finished");
    

    init_app_info(&app[0]);
    launch_swaptions_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp2b_alloc2 Finished : swaptions finished");
    
}

void exp12c() {
     PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    app_info_t app[MAX_APPS];
    char *map_file2 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/exp12c.csv";
    unsigned int nthreads = 3;

    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    init_app_info(&app[0]);
    launch_blackscholes(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp12c Finished : blackscholes finished");
    

    init_app_info(&app[0]);
    launch_bodytrack(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp12c Finished : bodytrack finished");
    

    init_app_info(&app[0]);
    launch_canneal(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp12c Finished : canneal finished");
    

    init_app_info(&app[0]);
    launch_dedup(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp12c Finished : dedup finished");
    

    init_app_info(&app[0]);
    launch_ferret(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp12c Finished : ferret finished");
    

    init_app_info(&app[0]);
    launch_fluidanimate(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp12c Finished : fluidanimate finished");
    

    init_app_info(&app[0]);
    launch_raytrace(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp12c Finished : raytrace finished");
    

    init_app_info(&app[0]);
    launch_streamcluster(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp12c Finished : streamcluster finished");
    

    init_app_info(&app[0]);
    launch_swaptions(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp12c Finished : swaptions finished");
    
}

void exp12c_simsmall() {
     PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    app_info_t app[MAX_APPS];
    char *map_file2 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/exp12c.csv";
    unsigned int nthreads = 3;

    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    init_app_info(&app[0]);
    launch_blackscholes_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp12c Finished : blackscholes finished");
    

    init_app_info(&app[0]);
    launch_bodytrack_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp12c Finished : bodytrack finished");
    

    init_app_info(&app[0]);
    launch_canneal_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp12c Finished : canneal finished");
    

    init_app_info(&app[0]);
    launch_dedup_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp12c Finished : dedup finished");
    

    init_app_info(&app[0]);
    launch_ferret_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp12c Finished : ferret finished");
    

    init_app_info(&app[0]);
    launch_fluidanimate_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp12c Finished : fluidanimate finished");
    

    init_app_info(&app[0]);
    launch_raytrace_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp12c Finished : raytrace finished");
    

    init_app_info(&app[0]);
    launch_streamcluster_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp12c Finished : streamcluster finished");
    

    init_app_info(&app[0]);
    launch_swaptions_simsmall(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp12c Finished : swaptions finished");
    
}


void main(int argc, char *argv[]) {
    // alloc1();
    // alloc2();
    //alloc3();
    //alloc4();
    // unbalanced_alloc();

    
    // exp1a_alloc1();
    // exp1a_alloc2();
    // exp1b_alloc1();
    // exp1b_alloc2();
    // exp2a_alloc1();
    // exp2a_alloc2();
    // exp2b_alloc1();
    // exp2b_alloc2();
    // exp12c();

    // exp1a_alloc1();
    // exp1a_alloc2();
    // exp1b_alloc1();
    exp1b_alloc2_simsmall();
    // exp2a_alloc1_simsmall();
    // exp2a_alloc2_simsmall();
    // exp2b_alloc1_simsmall();
    // exp2b_alloc2_simsmall();
    // exp12c_simsmall();



    //test_fluidanimate();
}