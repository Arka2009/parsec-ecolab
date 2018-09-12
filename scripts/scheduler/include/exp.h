#ifndef _exp_H
#define _exp_H

/* BENCHMARK HASHCODES */
#define BLACKSCHOLES  0
#define BODYTRACK     1
#define CANNEAL       2
#define DEDUP         3
#define FERRET        4
#define FLUIDANIMATE  5
#define STREAMCLUSTER 6
#define SWAPTIONS     7

/* ALLOCATION HASHCODES */
#define ALLOC_A       'a'
#define ALLOC_B       'b'
#define ALLOC_C       'c'
#define ALLOC_D       'd'
#define ALLOC_E       'e'

/* NTH (number of threads) HASHCODES */
#define NTH4          4
#define NTH8          8
#define NTH16         16
#define NTH32         32

/* Single Benchmak run */
void exp_1bench(unsigned int bench_hash, char alloc_hash, unsigned int nth_hash);
void exp_allbench(char alloc_hash,unsigned int nth_hash);
void exp_all();

void exp_1bench_simsmall(unsigned int bench_hash, char alloc_hash, unsigned int nth_hash);
void exp_allbench_simsmall(char alloc_hash,unsigned int nth_hash);
void exp_all_simsmall();

#endif /* _exp_H */