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

void exp_alloc_a() {
     PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    app_info_t app[MAX_APPS];
    char *map_file2 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/exp_alloc_a.csv";
    unsigned int nthreads = 3;

    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    init_app_info(&app[0]);
    launch_blackscholes(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_a Finished : blackscholes finished");
    

    init_app_info(&app[0]);
    launch_bodytrack(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_a Finished : bodytrack finished");
    

    init_app_info(&app[0]);
    launch_canneal(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_a Finished : canneal finished");
    

    init_app_info(&app[0]);
    launch_dedup(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_a Finished : dedup finished");
    

    init_app_info(&app[0]);
    launch_ferret(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_a Finished : ferret finished");
    

    init_app_info(&app[0]);
    launch_fluidanimate(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_a Finished : fluidanimate finished");
    

    init_app_info(&app[0]);
    launch_raytrace(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_a Finished : raytrace finished");
    

    init_app_info(&app[0]);
    launch_streamcluster(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_a Finished : streamcluster finished");
    

    init_app_info(&app[0]);
    launch_swaptions(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_a Finished : swaptions finished");
    
}

void exp_alloc_b() {
     PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    app_info_t app[MAX_APPS];
    char *map_file2 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/exp_alloc_b.csv";
    unsigned int nthreads = 3;

    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    init_app_info(&app[0]);
    launch_blackscholes(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_b Finished : blackscholes finished");
    

    init_app_info(&app[0]);
    launch_bodytrack(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_b Finished : bodytrack finished");
    

    init_app_info(&app[0]);
    launch_canneal(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_b Finished : canneal finished");
    

    init_app_info(&app[0]);
    launch_dedup(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_b Finished : dedup finished");
    

    init_app_info(&app[0]);
    launch_ferret(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_b Finished : ferret finished");
    

    init_app_info(&app[0]);
    launch_fluidanimate(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_b Finished : fluidanimate finished");
    

    init_app_info(&app[0]);
    launch_raytrace(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_b Finished : raytrace finished");
    

    init_app_info(&app[0]);
    launch_streamcluster(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_b Finished : streamcluster finished");
    

    init_app_info(&app[0]);
    launch_swaptions(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_b Finished : swaptions finished");
    
}

void exp_alloc_c() {
     PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    app_info_t app[MAX_APPS];
    char *map_file2 = "/home/amaity/Desktop/parsec-3.0/scripts/static_maps/exp_alloc_c.csv";
    unsigned int nthreads = 3;

    /* Launch applications (This can be done concurrently by a separate thread that generates the application) */
    init_app_info(&app[0]);
    launch_blackscholes(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_c Finished : blackscholes finished");
    

    init_app_info(&app[0]);
    launch_bodytrack(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_c Finished : bodytrack finished");
    

    init_app_info(&app[0]);
    launch_canneal(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_c Finished : canneal finished");
    

    init_app_info(&app[0]);
    launch_dedup(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_c Finished : dedup finished");
    

    init_app_info(&app[0]);
    launch_ferret(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_c Finished : ferret finished");
    

    init_app_info(&app[0]);
    launch_fluidanimate(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_c Finished : fluidanimate finished");
    

    init_app_info(&app[0]);
    launch_raytrace(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_c Finished : raytrace finished");
    

    init_app_info(&app[0]);
    launch_streamcluster(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_c Finished : streamcluster finished");
    

    init_app_info(&app[0]);
    launch_swaptions(nthreads,&app[0],map_file2);
    schedule_affine_map(app,1);
    PRINTSCHED("exp_alloc_c Finished : swaptions finished");
    
}

void main(int argc, char *argv[]) {
    exp_alloc_a();
    exp_alloc_b();
    exp_alloc_c();
}