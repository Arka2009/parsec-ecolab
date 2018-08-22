#ifndef _LAUNCH_APP_H
#define _LAUNCH_APP_H
#include <sys/types.h>
#include <stdbool.h>
#include <unistd.h>
#include "sched_params.h"

/*
 * App info structure containing
 * information like pid of the associated
 * process, number of (slave) threads, 
 * static thread to cpu map;
 */
typedef struct __app_struct {
    pid_t pid;
    unsigned int numthreads;
    unsigned int thr2cpuMap[MAX_THREADS];
} app_info_t;
void init_app_info(app_info_t *app);
void display_app_info(const app_info_t *app);

/* Launch the application */
pid_t launch_blackscholes(unsigned int nt, app_info_t *app, const char *map_file);
pid_t launch_bodytrack(unsigned int nt, app_info_t *app, const char *map_file);
pid_t launch_canneal(unsigned int nt, app_info_t *app, const char *map_file);
pid_t launch_dedup(unsigned int nt, app_info_t *app, const char *map_file);
pid_t launch_ferret(unsigned int nt, app_info_t *app, const char *map_file);
pid_t launch_fluidanimate(unsigned int nt, app_info_t *app, const char *map_file);
pid_t launch_raytrace(unsigned int nt, app_info_t *app, const char *map_file);
pid_t launch_swaptions(unsigned int nt, app_info_t *app, const char *map_file);
pid_t launch_streamcluster(unsigned int nt, app_info_t *app, const char *map_file);

/* (Non-blocking) wait for the applications */
bool waitapp(const app_info_t *, int num_apps);
#endif /* _LAUNCH_APP_H */