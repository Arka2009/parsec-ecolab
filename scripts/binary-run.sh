#!/bin/bash

parsec_dir=${PARSECROOT}
benchmark="parsec.blackscholes"
nthreads=2

lib=${PARSECROOT}/pkgs/libs/hooks/inst/amd64-linux.gcc-hooks/lib
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${lib}

# Clean Build the binary (Optional)
#${parsec_dir}/bin/parsecmgmt -a fulluninstall -p ${benchmark} parsec.hooks
#${parsec_dir}/bin/parsecmgmt -a build -p ${benchmark} -c gcc-hooks

# Benchmark binaries
blackscholes_bin=${parsec_dir}/pkgs/apps/blackscholes/inst/amd64-linux.gcc-hooks/bin/blackscholes
bodytrack_bin=${parsec_dir}/pkgs/apps/bodytrack/inst/amd64-linux.gcc-hooks/bin/bodytrack
canneal_bin=${parsec_dir}/pkgs/kernels/canneal/inst/amd64-linux.gcc-hooks/bin/canneal
dedup_bin=${parsec_dir}/pkgs/kernels/dedup/inst/amd64-linux.gcc-hooks/bin/dedup
ferret_bin=${parsec_dir}/pkgs/apps/ferret/inst/amd64-linux.gcc-hooks/bin/ferret
fluidanimate_bin=${parsec_dir}/pkgs/apps/fluidanimate/inst/amd64-linux.gcc-hooks/bin/fluidanimate
swaptions_bin=${parsec_dir}/pkgs/apps/swaptions/inst/amd64-linux.gcc-hooks/bin/swaptions
streamcluster_bin=${parsec_dir}/pkgs/kernels/streamcluster/inst/amd64-linux.gcc-hooks/bin/streamcluster

# Benchmark Inputs
blackscholes_input="${nthreads} ${parsec_dir}/pkgs/apps/blackscholes/inputs/in_10M.txt dump/prices.txt"
blackscholes_input_test="${nthreads} ${parsec_dir}/pkgs/apps/blackscholes/inputs/in_4.txt dump/prices.txt"
bodytrack_input="${parsec_dir}/pkgs/apps/bodytrack/inputs/sequenceB_261 4 261 4000 5 0 ${nthreads}"
bodytrack_input_test="${parsec_dir}/pkgs/apps/bodytrack/inputs/sequenceB_1 4 1 5 1 0 ${nthreads}"
canneal_input="${nthreads} 15000 2000 ${parsec_dir}/pkgs/kernels/canneal/inputs/2500000.nets 6000"
canneal_input_test="${nthreads} 10000 2000 ${parsec_dir}/pkgs/kernels/canneal/inputs/100000.nets 32"
dedup_input="-c -p -v -t ${nthreads} -i ${parsec_dir}/pkgs/kernels/dedup/inputs/FC-6-x86_64-disc1.iso -o dump/output.dat.ddp"
dedup_input_test="-c -p -v -t ${nthreads} -i ${parsec_dir}/pkgs/kernels/dedup/inputs/media.dat -o dump/output.dat.ddp"
ferret_input="${parsec_dir}/pkgs/apps/ferret/inputs/corel lsh ${parsec_dir}/pkgs/apps/ferret/inputs/queries 50 20 ${nthreads} dump/output.txt"
#ferret_input_test="corel lsh queries 10 20 ${nthreads} dump/output.txt"
fluidanimate_input="${nthreads} 500 ${parsec_dir}/pkgs/apps/fluidanimate/inputs/in_500K.fluid dump/out.fluid"
fluidanimate_input_test="${nthreads} 5 ${parsec_dir}/pkgs/apps/fluidanimate/inputs/in_35K.fluid dump/out.fluid"
swaptions_input="-ns 128 -sm 1000000 -nt ${nthreads}"
swaptions_input_test="-ns 16 -sm 10000 -nt ${nthreads}"
streamcluster_input="10 20 128 1000000 200000 5000 none dump/output.txt ${nthreads}"
#streamcluster_input_test=""




# Launch the processes and save their PIDs
START=${SECONDS}
echo "[DATE2019]: Running The naked binaries...."
taskset -c 2,3,4 ${canneal_bin} ${canneal_input} & 
#benchpid1=$!
taskset -c 6,7,68 ${canneal_bin} ${canneal_input} &
#benchpid1=$!
wait
END=${SECONDS}
echo "Response Time-1 $(( ${END} - ${START} ))"
START=${SECONDS}
echo "[DATE2019]: Running The naked binaries...."
taskset -c 2,3,4 ${canneal_bin} ${canneal_input} & 
#benchpid1=$!
taskset -c 6,7,8 ${canneal_bin} ${canneal_input} &
#benchpid1=$!
wait
END=${SECONDS}

#echo "${canneal_input}"
echo "Response Time-2 $(( ${END} - ${START} ))"
# Manage The Running Processing
