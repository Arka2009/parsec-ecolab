#!/bin/bash

# binary only run
parsec_dir=/home/amaity/Desktop/parsec-3.0
benchmarks="\
blackscholes \
bodytrack \
canneal \
dedup \
ferret \
fluidanimate \
streamcluster \
raytrace \
swaptions \
"
nthreads="3"

lib=${parsec_dir}/pkgs/libs/hooks/inst/amd64-linux.gcc-hooks/lib
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${lib}

# Benchmark binaries
blackscholes_bin=${parsec_dir}/pkgs/apps/blackscholes/inst/amd64-linux.gcc-hooks/bin/blackscholes
bodytrack_bin=${parsec_dir}/pkgs/apps/bodytrack/inst/amd64-linux.gcc-hooks/bin/bodytrack
canneal_bin=${parsec_dir}/pkgs/kernels/canneal/inst/amd64-linux.gcc-hooks/bin/canneal
dedup_bin=${parsec_dir}/pkgs/kernels/dedup/inst/amd64-linux.gcc-hooks/bin/dedup
ferret_bin=${parsec_dir}/pkgs/apps/ferret/inst/amd64-linux.gcc-hooks/bin/ferret
fluidanimate_bin=${parsec_dir}/pkgs/apps/fluidanimate/inst/amd64-linux.gcc-hooks/bin/fluidanimate
swaptions_bin=${parsec_dir}/pkgs/apps/swaptions/inst/amd64-linux.gcc-hooks/bin/swaptions
streamcluster_bin=${parsec_dir}/pkgs/kernels/streamcluster/inst/amd64-linux.gcc-hooks/bin/streamcluster

# Benchmark Inputs (Native)
blackscholes_input="${nthreads} ${parsec_dir}/pkgs/apps/blackscholes/inputs/in_10M.txt dump/prices.txt"
bodytrack_input="${parsec_dir}/pkgs/apps/bodytrack/inputs/sequenceB_261 4 261 4000 5 0 ${nthreads}"
canneal_input="${nthreads} 15000 2000 ${parsec_dir}/pkgs/kernels/canneal/inputs/2500000.nets 6000"
dedup_input="-c -p -v -t ${nthreads} -i ${parsec_dir}/pkgs/kernels/dedup/inputs/FC-6-x86_64-disc1.iso -o dump/output.dat.ddp"
ferret_input="${parsec_dir}/pkgs/apps/ferret/inputs/corel lsh ${parsec_dir}/pkgs/apps/ferret/inputs/queries 50 20 ${nthreads} dump/output.txt"
fluidanimate_input="${nthreads} 500 ${parsec_dir}/pkgs/apps/fluidanimate/inputs/in_500K.fluid dump/out.fluid"
swaptions_input="-ns 128 -sm 1000000 -nt ${nthreads}"
streamcluster_input="10 20 128 1000000 200000 5000 none dump/output.txt ${nthreads}"

# Benchmark Inputs (Test)
blackscholes_input_test="${nthreads} ${parsec_dir}/pkgs/apps/blackscholes/inputs/in_4.txt dump/prices.txt"
bodytrack_input_test="${parsec_dir}/pkgs/apps/bodytrack/inputs/sequenceB_1 4 1 5 1 0 ${nthreads}"
canneal_input_test="${nthreads} 10000 2000 ${parsec_dir}/pkgs/kernels/canneal/inputs/100000.nets 32"
dedup_input_test="-c -p -v -t ${nthreads} -i ${parsec_dir}/pkgs/kernels/dedup/inputs/media.dat -o dump/output.dat.ddp"
#ferret_input_test="corel lsh queries 10 20 ${nthreads} dump/output.txt"
fluidanimate_input_test="${nthreads} 5 ${parsec_dir}/pkgs/apps/fluidanimate/inputs/in_35K.fluid dump/out.fluid"
swaptions_input_test="-ns 16 -sm 10000 -nt ${nthreads}"

# Benchmark Inputs (simsmall)
blackscholes_input_simsmall="${nthreads} ${parsec_dir}/pkgs/apps/blackscholes/inputs/in_4K.txt dump/prices.txt"
canneal_input_simsmall="${nthreads} 10000 2000 ${parsec_dir}/pkgs/kernels/canneal/inputs/100000.nets 32"
dedup_input_simsmall="-c -p -v -t ${nthreads} -i ${parsec_dir}/pkgs/kernels/dedup/inputs/media.dat -o dump/output.dat.ddp"
streamcluster_input_simsmall="10 20 32 4096 4096 1000 none dump/output.txt ${nthreads}"

exe_native=(\
"${parsec_dir}/pkgs/apps/blackscholes/inst/amd64-linux.gcc-hooks/bin/blackscholes ${nthreads} ${parsec_dir}/pkgs/apps/blackscholes/inputs/in_10M.txt dump/prices.txt"\
"${parsec_dir}/pkgs/apps/bodytrack/inst/amd64-linux.gcc-hooks/bin/bodytrack ${parsec_dir}/pkgs/apps/bodytrack/inputs/sequenceB_261 4 261 4000 5 0 ${nthreads}"\
"${parsec_dir}/pkgs/kernels/canneal/inst/amd64-linux.gcc-hooks/bin/canneal ${nthreads} 15000 2000 ${parsec_dir}/pkgs/kernels/canneal/inputs/2500000.nets 6000"\
"${parsec_dir}/pkgs/kernels/dedup/inst/amd64-linux.gcc-hooks/bin/dedup -c -p -v -t ${nthreads} -i ${parsec_dir}/pkgs/kernels/dedup/inputs/FC-6-x86_64-disc1.iso -o dump/output.dat.ddp"\
"{parsec_dir}/pkgs/apps/ferret/inst/amd64-linux.gcc-hooks/bin/ferret ${parsec_dir}/pkgs/apps/ferret/inputs/corel lsh ${parsec_dir}/pkgs/apps/ferret/inputs/queries 50 20 ${nthreads} dump/output.txt"\
"${parsec_dir}/pkgs/apps/fluidanimate/inst/amd64-linux.gcc-hooks/bin/fluidanimate ${nthreads} 500 ${parsec_dir}/pkgs/apps/fluidanimate/inputs/in_500K.fluid dump/out.fluid"\
"/home/amaity/Desktop/parsec-3.0/pkgs/apps/raytrace/inst/amd64-linux.gcc-hooks/bin/rtview /home/amaity/Desktop/parsec-3.0/pkgs/apps/raytrace/inputs/thai_statue.obj -automove -nthreads ${nthreads} -frames 200 -res 1920 1080"\
"${parsec_dir}/pkgs/kernels/streamcluster/inst/amd64-linux.gcc-hooks/bin/streamcluster 10 20 128 1000000 200000 5000 none dump/output.txt ${nthreads}"\
"${parsec_dir}/pkgs/apps/swaptions/inst/amd64-linux.gcc-hooks/bin/swaptions -ns 128 -sm 1000000 -nt ${nthreads}")

exe_simsmall=(\
 "/home/amaity/Desktop/parsec-3.0/pkgs/apps/blackscholes/inst/amd64-linux.gcc-hooks/bin/blackscholes ${nthreads} ${parsec_dir}/pkgs/apps/blackscholes/inputs/in_4K.txt dump/prices.txt"\
 "/home/amaity/Desktop/parsec-3.0/pkgs/apps/bodytrack/inst/amd64-linux.gcc-hooks/bin/bodytrack ${parsec_dir}/pkgs/apps/bodytrack/inputs/sequenceB_1 4 1 1000 5 0 ${nthreads}"\
 "/home/amaity/Desktop/parsec-3.0/pkgs/kernels/canneal/inst/amd64-linux.gcc-hooks/bin/canneal ${nthreads} 10000 2000 ${parsec_dir}/pkgs/kernels/canneal/inputs/100000.nets 32"\
 "/home/amaity/Desktop/parsec-3.0/pkgs/kernels/dedup/inst/amd64-linux.gcc-hooks/bin/dedup -c -p -v -t ${nthreads} -i ${parsec_dir}/pkgs/kernels/dedup/inputs/media.dat -o output.dat.ddp"\
 "/home/amaity/Desktop/parsec-3.0/pkgs/apps/ferret/inst/amd64-linux.gcc-hooks/bin/ferret ${parsec_dir}/pkgs/apps/ferret/inputs/corel lsh ${parsec_dir}/pkgs/apps/ferret/inputs/queries_simsmall 10 20 ${nthreads} dump/output.txt"\
 "/home/amaity/Desktop/parsec-3.0/pkgs/apps/fluidanimate/inst/amd64-linux.gcc-hooks/bin/fluidanimate ${nthreads} 5 ${parsec_dir}/pkgs/apps/fluidanimate/inputs/in_35K.fluid dump/out.fluid"\
 "/home/amaity/Desktop/parsec-3.0/pkgs/apps/raytrace/inst/amd64-linux.gcc-hooks/bin/rtview /home/amaity/Desktop/parsec-3.0/pkgs/apps/raytrace/inputs/happy_buddha.obj -automove -nthreads ${nthreads} -frames 3 -res 480 270"\
 "/home/amaity/Desktop/parsec-3.0/pkgs/kernels/streamcluster/inst/amd64-linux.gcc-hooks/bin/streamcluster 10 20 32 4096 4096 1000 none dump/output.txt ${nthreads}"\
 "/home/amaity/Desktop/parsec-3.0/pkgs/apps/swaptions/inst/amd64-linux.gcc-hooks/bin/swaptions -ns 16 -sm 10000 -nt ${nthreads}")


# Process prefix
affinity="0,1,2,3"
perf_prefix1="likwid-perfctr -f -c ${affinity},32 -g MEM_UOPS_RETIRED_ALL_LOADS:PMC0"
perf_prefix2="likwid-perfctr -f -c ${affinity},32 -g MEM_UOPS_RETIRED_L1_MISS_LOADS:PMC0"
perf_prefix3="likwid-perfctr -f -c ${affinity},32 -g MEM_UOPS_RETIRED_L2_HIT_LOADS:PMC0,MEM_UOPS_RETIRED_L2_MISS_LOADS:PMC1"
perf_prefix4="likwid-perfctr -f -c ${affinity},32 -g MEM_UOPS_RETIRED_HITM:PMC0"
aff_prefix="numactl -m 0 taskset -c ${affinity}"

for i in "${exe_simsmall[@]}" ; do
	#echo $i
	#echo ${perf_prefix1}
	#echo ${aff_prefix}
	#echo "${perf_prefix1} ${aff_prefix} $i"
	${perf_prefix1} ${aff_prefix} $i >> dump/cache_perf_simsmall_aff_0-1-2-3.txt 
	${perf_prefix2} ${aff_prefix} $i >> dump/cache_perf_simsmall_aff_0-1-2-3.txt
	${perf_prefix3} ${aff_prefix} $i >> dump/cache_perf_simsmall_aff_0-1-2-3.txt
	${perf_prefix4} ${aff_prefix} $i >> dump/cache_perf_simsmall_aff_0-1-2-3.txt
	echo "$i"
	echo "------------------FINISHED---------------------"
done

affinity="0,2,4,6"
perf_prefix1="likwid-perfctr -f -c ${affinity},32 -g MEM_UOPS_RETIRED_ALL_LOADS:PMC0"
perf_prefix2="likwid-perfctr -f -c ${affinity},32 -g MEM_UOPS_RETIRED_L1_MISS_LOADS:PMC0"
perf_prefix3="likwid-perfctr -f -c ${affinity},32 -g MEM_UOPS_RETIRED_L2_HIT_LOADS:PMC0,MEM_UOPS_RETIRED_L2_MISS_LOADS:PMC1"
perf_prefix4="likwid-perfctr -f -c ${affinity},32 -g MEM_UOPS_RETIRED_HITM:PMC0"
aff_prefix="numactl -m 0 taskset -c ${affinity}"

for i in "${exe_simsmall[@]}" ; do
	#echo $i
	#echo ${perf_prefix1}
	#echo ${aff_prefix}
	#echo "${perf_prefix1} ${aff_prefix} $i"
	${perf_prefix1} ${aff_prefix} $i >> dump/cache_perf_simsmall_aff_0-2-4-6.txt 
	${perf_prefix2} ${aff_prefix} $i >> dump/cache_perf_simsmall_aff_0-2-4-6.txt
	${perf_prefix3} ${aff_prefix} $i >> dump/cache_perf_simsmall_aff_0-2-4-6.txt
	${perf_prefix4} ${aff_prefix} $i >> dump/cache_perf_simsmall_aff_0-2-4-6.txt
	echo "$i"
	echo "------------------FINISHED---------------------"
done
