#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define SIZE 100

int first[SIZE][SIZE], second[SIZE][SIZE], multiply[SIZE][SIZE];

void dummy_compute() {
  int sum = 0;
  int c,d,k;
 
 
  for (c = 0; c < SIZE; c++) {
    for (d = 0; d < SIZE; d++) {
      	first[c][d] = 1;
        second[c][d] = 1;
        multiply[c][d] = 1;
    }
  }
 
 
    for (c = 0; c < SIZE; c++) {
      for (d = 0; d < SIZE; d++) {
        for (k = 0; k < SIZE; k++) {
          sum = sum + first[c][k]*second[k][d];
        }
        multiply[c][d] = sum;
        sum = 0;
      }
    }
}

void main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr,"Supply the binary name \n");
		exit(EXIT_FAILURE);
	}
	//char *dir = getenv("PARSECROOT");
	//if(!dir) {
	//	fprintf(stderr,"Please set PARSECROOT!!!\n");
	//	exit(EXIT_FAILURE);
	//}
	//strcat(dir,"/scripts/thrd_cpu_map.csv");
	//char command[BUFSIZ];
	//sprintf(command,"cp %s static_thr2cpu_map.csv",dir);
	//printf("%s\n",command);
	unsigned int i = 0;
	while(1) {
		dummy_compute();
		//printf("%s-%d : Finished iteration-%d\n",argv[1],getpid(),i++);
	}
}
