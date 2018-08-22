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


void unbalanced_alloc() {
    PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    int rc;
    app_info_t app[MAX_APPS];

    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    char *map_file2 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/alloc_u/app_0_map.csv";
    init_app_info(&app[0]);
    launch_blackscholes(7,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("blackscholes finished - uAlloc1");

    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    char *map_file3 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/alloc_u/app_1_map.csv";
    init_app_info(&app[0]);
    launch_blackscholes(7,&app[0],map_file3);
    schedule_affine_map(app,1);
    PRINTSCHED("blackscholes finished - uAlloc2");

    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    char *map_file4 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/alloc_u/app_2_map.csv";
    init_app_info(&app[0]);
    launch_blackscholes(7,&app[0],map_file4);
    schedule_affine_map(app,1);
    PRINTSCHED("blackscholes finished - uAlloc4");
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

void test_fluidanimate() {
    PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    app_info_t app[MAX_APPS];
    char *map_file2 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/exp2b_alloc2.csv";
    unsigned int nthreads = 3;
    sprintf(log,"%s","exp2b_alloc2 Finished : ");

    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    init_app_info(&app[0]);
    launch_fluidanimate(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("fluidanimate finished");
    
}

void test_raytrace() {
    PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    app_info_t app[MAX_APPS];
    char *map_file2 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/exp2b_alloc2.csv";
    unsigned int nthreads = 3;
    sprintf(log,"%s","exp2b_alloc2 Finished : ");

    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    init_app_info(&app[0]);
    launch_raytrace(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("raytrace finished");
    
}

void main(int argc, char *argv[]) {
    // alloc1();
    // alloc2();
    //alloc3();
    //alloc4();
    // unbalanced_alloc();

    
    exp1a_alloc1();
    exp1a_alloc2();
    exp1b_alloc1();
    exp1b_alloc2();
    exp2a_alloc1();
    exp2a_alloc2();
    exp2b_alloc1();
    exp2b_alloc2();

    //test_fluidanimate();
}