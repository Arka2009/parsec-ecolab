#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define PRINTTOPO(string) \
printf("[x86-TOPO]-%d : %s\n",getpid(),string)

#define PRINTERROR(string) \
fprintf(stderr,"[ERROR]-%d : %s\n",getpid(),string); \
exit(EXIT_FAILURE)

#define PRINTSCHED(arg) printf("[DATE2019-scheduler]-%d : %s\n",getpid(),arg)