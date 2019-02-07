#!/bin/bash

# Set up the necessary variables
parsec_dir="${PWD}/.."
lib=${parsec_dir}/pkgs/libs/hooks/inst/amd64-linux.gcc-hooks/lib
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${lib}

input1="${parsec_dir}/pkgs/apps/blackscholes/inputs/in_16K.txt" #(Blackscholes)
nthreads1="4" # Number of Slave Threads
exe1="${parsec_dir}/pkgs/apps/blackscholes/inst/amd64-linux.gcc-hooks/bin/blackscholes ${nthreads1}  ${input1} dump/prices.txt"

#(Streamcluster - simsmall)
nthreads2="8" # Number of Slave Threads
exe2="${parsec_dir}/pkgs/kernels/streamcluster/inst/amd64-linux.gcc-hooks/bin/streamcluster 10 20 32 4096 4096 1000 none dump/output.txt ${nthreads2}"

#(Canneal - simdev)
nthreads3="32" # Number of Slave Threads
exe3="${parsec_dir}/pkgs/kernels/canneal/inst/amd64-linux.gcc-hooks/bin/canneal ${nthreads3} 10000 2000 ${parsec_dir}/pkgs/kernels/canneal/inputs/100000.nets 32"

# Process prefix
affinity="1-5"
aff_prefix="numactl -m 0 taskset -c ${affinity}"

# Create the Process and Run
rm -rf synth_sp_blackscholes
mkdir -p synth_sp_blackscholes
echo "phase,time">>synth_sp_blackscholes/dataset_ph1.csv
echo "phase,time">>synth_sp_blackscholes/dataset_ph2.csv
echo "phase,time">>synth_sp_blackscholes/dataset_ph3.csv
echo "total,time" >> synth_sp_blackscholes/dataset_sf.csv
for iter in $(seq 1 500); do
	# Measure Each Phase
	start2=$(date +%s.%N)
	${exe3} > /dev/null
	dur=$(echo "$(date +%s.%N) - $start2" | bc)
	echo "iter-${iter},${dur}" >> synth_sp_blackscholes/dataset_ph1.csv
	start2=$(date +%s.%N)
	${exe3} > /dev/null
	dur=$(echo "$(date +%s.%N) - $start2" | bc)
	echo "iter-${iter},${dur}" >> synth_sp_blackscholes/dataset_ph2.csv
	start2=$(date +%s.%N)
	${exe3} > /dev/null
	dur=$(echo "$(date +%s.%N) - $start2" | bc)
	echo "iter-${iter},${dur}" >> synth_sp_blackscholes/dataset_ph3.csv
	
	# Measure Everything (including the epilogue and prologue)
	start2=$(date +%s.%N)
	${exe3} > /dev/null
	${exe3} > /dev/null
	${exe3} > /dev/null
	dur=$(echo "$(date +%s.%N) - $start2" | bc) 
	echo "iter-${iter},${dur}" >> synth_sp_blackscholes/dataset_sf.csv

	echo "Finished Iteration-${iter}"
done
