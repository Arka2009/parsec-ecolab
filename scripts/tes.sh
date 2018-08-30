#!/bin/bash

# binary only run
# Measures the IPC of the bencmarks 
# This doesn't profile the ROI, rather
# it profiles the entire application,
# While the execcution time estimates are
# for the ROI only. So this an
# approximate ball-park numbers

parsec_dir=/home/amaity/Desktop/parsec-3.0
nthreads="3"
dump2="group_test"
mkdir -p ${dump2}

lib=${parsec_dir}/pkgs/libs/hooks/inst/amd64-linux.gcc-hooks/lib
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${lib}

exe_native=(\
 "${parsec_dir}/pkgs/apps/blackscholes/inst/amd64-linux.gcc-hooks/bin/blackscholes ${nthreads} ${parsec_dir}/pkgs/apps/blackscholes/inputs/in_10M.txt dump/prices.txt"\
 "${parsec_dir}/pkgs/apps/bodytrack/inst/amd64-linux.gcc-hooks/bin/bodytrack ${parsec_dir}/pkgs/apps/bodytrack/inputs/sequenceB_261 4 261 4000 5 0 ${nthreads}"\
 "${parsec_dir}/pkgs/kernels/canneal/inst/amd64-linux.gcc-hooks/bin/canneal ${nthreads} 15000 2000 ${parsec_dir}/pkgs/kernels/canneal/inputs/2500000.nets 6000"\
 "${parsec_dir}/pkgs/kernels/dedup/inst/amd64-linux.gcc-hooks/bin/dedup -c -p -v -t ${nthreads} -i ${parsec_dir}/pkgs/kernels/dedup/inputs/FC-6-x86_64-disc1.iso -o dump/output.dat.ddp"\
 "${parsec_dir}/pkgs/apps/ferret/inst/amd64-linux.gcc-hooks/bin/ferret ${parsec_dir}/pkgs/apps/ferret/inputs/corel lsh ${parsec_dir}/pkgs/apps/ferret/inputs/queries 50 20 ${nthreads} dump/output.txt"\
 "${parsec_dir}/pkgs/apps/fluidanimate/inst/amd64-linux.gcc-hooks/bin/fluidanimate ${nthreads} 500 ${parsec_dir}/pkgs/apps/fluidanimate/inputs/in_500K.fluid dump/out.fluid"\
 "/home/amaity/Desktop/parsec-3.0/pkgs/apps/raytrace/inst/amd64-linux.gcc-hooks/bin/rtview /home/amaity/Desktop/parsec-3.0/pkgs/apps/raytrace/inputs/thai_statue.obj -automove -nthreads ${nthreads} -frames 200 -res 1920 1080"\
 "${parsec_dir}/pkgs/kernels/streamcluster/inst/amd64-linux.gcc-hooks/bin/streamcluster 10 20 128 1000000 200000 5000 none dump/output.txt ${nthreads}"\
 "${parsec_dir}/pkgs/apps/swaptions/inst/amd64-linux.gcc-hooks/bin/swaptions -ns 128 -sm 1000000 -nt ${nthreads}")



measure="L2CACHE"
for exe_test in "${exe_native[@]}"; do
	echo ${exe_test}
	affinity="0,64,128,192"
	affinity_pr="0-64-128-192"
	perf_prefix1="likwid-perfctr -f -c ${affinity} -g ${measure}"
	aff_prefix="numactl -m 0 taskset -c ${affinity}"
	${perf_prefix1} ${aff_prefix} ${exe_test} >> ${dump2}/cache_events_native_4nth_${affinity_pr}.txt 
	echo "------------------FINISHED-${affinity}-------------------"
	sleep 10
	
	# Process prefix (alloc-c)
	affinity="0,1,64,65"
	affinity_pr="0-1-64-65"
	perf_prefix1="likwid-perfctr -f -c ${affinity} -g ${measure}"
	aff_prefix="numactl -m 0 taskset -c ${affinity}"
	${perf_prefix1} ${aff_prefix} ${exe_test} >> ${dump2}/cache_events_native_4nth_${affinity_pr}.txt 
	echo "------------------FINISHED-${affinity}-------------------"
	sleep 10
done
#rm -rf ${dump2}
