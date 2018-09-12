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
#include "exp.h"

/* Runs only a single benchmark */
void exp_1bench(unsigned int bench_hash, char alloc_hash, unsigned int nth_hash) {
    PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    app_info_t app[MAX_APPS];

    /* Determine the number of slave threads and allocation */
    char map_file2[BUFSIZ];
    sprintf(map_file2,"/home/amaity/Desktop/parsec-3.0/scripts/static_maps/exp_%dnth_%c.csv",nth_hash,alloc_hash);
    // sprintf(log,"%s\n",map_file2);
    // PRINTERROR(log);
    unsigned int nthreads = nth_hash - 1;

    /* Run the appropriate benchmark */
    switch(bench_hash) {
        case BLACKSCHOLES : {
            init_app_info(&app[0]);
            launch_blackscholes(nthreads,&app[0],map_file2);
            schedule_affine_map(app,1);
            sprintf(log,"exp_%dnth_%c Finished : blackscholes Finished",nth_hash,alloc_hash);
            PRINTSCHED(log);
            break;
        }

        case BODYTRACK : {
            init_app_info(&app[0]);
            launch_bodytrack(nthreads,&app[0],map_file2);
            schedule_affine_map(app,1);
            sprintf(log,"exp_%dnth_%c Finished : bodytrack Finished",nth_hash,alloc_hash);
            PRINTSCHED(log);
            break;
        }

        case CANNEAL : {
            init_app_info(&app[0]);
            launch_canneal(nthreads,&app[0],map_file2);
            schedule_affine_map(app,1);
            sprintf(log,"exp_%dnth_%c Finished : canneal Finished",nth_hash,alloc_hash);
            PRINTSCHED(log);
            break;
        }

        case DEDUP : {
            init_app_info(&app[0]);
            launch_dedup(nthreads,&app[0],map_file2);
            schedule_affine_map(app,1);
            sprintf(log,"exp_%dnth_%c Finished : dedup Finished",nth_hash,alloc_hash);
            PRINTSCHED(log);
            break;
        }

        case FERRET : {
            init_app_info(&app[0]);
            launch_ferret(nthreads,&app[0],map_file2);
            schedule_affine_map(app,1);
            sprintf(log,"exp_%dnth_%c Finished : ferret Finished",nth_hash,alloc_hash);
            PRINTSCHED(log);
            break;
        }

        case STREAMCLUSTER : {
            init_app_info(&app[0]);
            launch_streamcluster(nthreads,&app[0],map_file2);
            schedule_affine_map(app,1);
            sprintf(log,"exp_%dnth_%c Finished : streamcluster Finished",nth_hash,alloc_hash);
            PRINTSCHED(log);
            break;
        }

        case SWAPTIONS : {
            init_app_info(&app[0]);
            launch_swaptions(nthreads,&app[0],map_file2);
            schedule_affine_map(app,1);
            sprintf(log,"exp_%dnth_%c Finished : swaptions Finished",nth_hash,alloc_hash);
            PRINTSCHED(log);
            break;
        }

        default : PRINTERROR("Benchmark not supported");
    }
}

/* simsmall inputs */
void exp_1bench_simsmall(unsigned int bench_hash, char alloc_hash, unsigned int nth_hash) {
    PRINTSCHED("Welcome");
    char log[BUFSIZ];
    cpu_topology_t cpu_top;
    detect_topology(&cpu_top);

    unsigned int i;
    int status; /* Child status */
    app_info_t app[MAX_APPS];

    /* Determine the number of slave threads and allocation */
    char map_file2[BUFSIZ];
    sprintf(map_file2,"/home/amaity/Desktop/parsec-3.0/scripts/static_maps/exp_%dnth_%c.csv",nth_hash,alloc_hash);
    // sprintf(log,"%s\n",map_file2);
    // PRINTERROR(log);
    unsigned int nthreads = nth_hash - 1;

    /* Run the appropriate benchmark */
    switch(bench_hash) {
        case BLACKSCHOLES : {
            init_app_info(&app[0]);
            launch_blackscholes_simsmall(nthreads,&app[0],map_file2);
            schedule_affine_map(app,1);
            sprintf(log,"exp_%dnth_%c Finished : blackscholes (simsmall) finished",nth_hash,alloc_hash);
            PRINTSCHED(log);
            break;
        }

        case BODYTRACK : {
            init_app_info(&app[0]);
            launch_bodytrack_simsmall(nthreads,&app[0],map_file2);
            schedule_affine_map(app,1);
            sprintf(log,"exp_%dnth_%c Finished : bodytrack (simsmall) finished",nth_hash,alloc_hash);
            PRINTSCHED(log);
            break;
        }

        case CANNEAL : {
            init_app_info(&app[0]);
            launch_canneal_simsmall(nthreads,&app[0],map_file2);
            schedule_affine_map(app,1);
            sprintf(log,"exp_%dnth_%c Finished : canneal (simsmall) finished",nth_hash,alloc_hash);
            PRINTSCHED(log);
            break;
        }

        case DEDUP : {
            init_app_info(&app[0]);
            launch_dedup_simsmall(nthreads,&app[0],map_file2);
            schedule_affine_map(app,1);
            sprintf(log,"exp_%dnth_%c Finished : dedup (simsmall) finished",nth_hash,alloc_hash);
            PRINTSCHED(log);
            break;
        }

        case FERRET : {
            init_app_info(&app[0]);
            launch_ferret_simsmall(nthreads,&app[0],map_file2);
            schedule_affine_map(app,1);
            sprintf(log,"exp_%dnth_%c Finished : ferret (simsmall) finished",nth_hash,alloc_hash);
            PRINTSCHED(log);
            break;
        }

        case STREAMCLUSTER : {
            init_app_info(&app[0]);
            launch_streamcluster_simsmall(nthreads,&app[0],map_file2);
            schedule_affine_map(app,1);
            sprintf(log,"exp_%dnth_%c Finished : streamcluster (simsmall) finished",nth_hash,alloc_hash);
            PRINTSCHED(log);
            break;
        }

        case SWAPTIONS : {
            init_app_info(&app[0]);
            launch_swaptions_simsmall(nthreads,&app[0],map_file2);
            schedule_affine_map(app,1);
            sprintf(log,"exp_%dnth_%c Finished : swaptions (simsmall) finished",nth_hash,alloc_hash);
            PRINTSCHED(log);
            break;
        }

        default : PRINTERROR("Benchmark not supported");
    }
}

void exp_main(int argc, char **argv) {}

/* Run all benchmarks */
void exp_allbench(char alloc_hash,unsigned int nth_hash) {
    exp_1bench(BLACKSCHOLES, alloc_hash, nth_hash);
    //exp_1bench(BODYTRACK, alloc_hash, nth_hash);
    exp_1bench(CANNEAL, alloc_hash, nth_hash);
    // exp_1bench(DEDUP, alloc_hash, nth_hash);
    // exp_1bench(FERRET, alloc_hash, nth_hash);
    // exp_1bench(STREAMCLUSTER, alloc_hash, nth_hash);
    // exp_1bench(SWAPTIONS, alloc_hash, nth_hash);
}

void exp_allbench_simsmall(char alloc_hash,unsigned int nth_hash) {
    exp_1bench_simsmall(BLACKSCHOLES, alloc_hash, nth_hash);
    exp_1bench_simsmall(BODYTRACK, alloc_hash, nth_hash);
    exp_1bench_simsmall(CANNEAL, alloc_hash, nth_hash);
    exp_1bench_simsmall(DEDUP, alloc_hash, nth_hash);
    exp_1bench_simsmall(FERRET, alloc_hash, nth_hash);
    exp_1bench_simsmall(STREAMCLUSTER, alloc_hash, nth_hash);
    if (nth_hash < NTH32) {
        exp_1bench_simsmall(SWAPTIONS, alloc_hash, nth_hash);
    }
}

/* Run all nth and allocation combination */
void exp_all() {
    /* 4 threaded allocations */
    // exp_allbench(ALLOC_A,NTH4);
    // exp_allbench(ALLOC_B,NTH4);
    exp_allbench(ALLOC_C,NTH4);
    exp_allbench(ALLOC_D,NTH4);
    exp_allbench(ALLOC_E,NTH4);

    /* 8 threaded allocations */
    exp_allbench(ALLOC_A,NTH8);
    exp_allbench(ALLOC_B,NTH8);
    exp_allbench(ALLOC_C,NTH8);
    exp_allbench(ALLOC_D,NTH8);
    exp_allbench(ALLOC_E,NTH8);

    /* 16 threaded allocations */
    exp_allbench(ALLOC_A,NTH16);
    exp_allbench(ALLOC_B,NTH16);
    exp_allbench(ALLOC_C,NTH16);

    /* 32 threaded allocations */
    exp_allbench(ALLOC_A,NTH32);
    exp_allbench(ALLOC_B,NTH32);
}

void exp_all_simsmall() {
    /* 4 threaded allocations */
    exp_allbench_simsmall(ALLOC_A,NTH4);
    exp_allbench_simsmall(ALLOC_B,NTH4);
    exp_allbench_simsmall(ALLOC_C,NTH4);
    exp_allbench_simsmall(ALLOC_D,NTH4);
    exp_allbench_simsmall(ALLOC_E,NTH4);

    /* 8 threaded allocations */
    exp_allbench_simsmall(ALLOC_A,NTH8);
    exp_allbench_simsmall(ALLOC_B,NTH8);
    exp_allbench_simsmall(ALLOC_C,NTH8);
    exp_allbench_simsmall(ALLOC_D,NTH8);
    exp_allbench_simsmall(ALLOC_E,NTH8);

    /* 16 threaded allocations */
    exp_allbench_simsmall(ALLOC_A,NTH16);
    exp_allbench_simsmall(ALLOC_B,NTH16);
    exp_allbench_simsmall(ALLOC_C,NTH16);

    /* 32 threaded allocations */
    exp_allbench_simsmall(ALLOC_A,NTH32);
    exp_allbench_simsmall(ALLOC_B,NTH32);
}