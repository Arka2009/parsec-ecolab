#!/bin/bash

# Set up the necessary variables
parsec_dir=/home/amaity/Desktop/parsec-3.0
nthreads="7"
lib=${parsec_dir}/pkgs/libs/hooks/inst/amd64-linux.gcc-hooks/lib
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${lib}
exe_native="${parsec_dir}/pkgs/apps/blackscholes/inst/amd64-linux.gcc-hooks/bin/blackscholes ${nthreads} ${parsec_dir}/pkgs/apps/blackscholes/inputs/in_10M.txt dump/prices.txt"


# Launch the processes in suspended state
#( bench=$BASHPID; kill -SIGSTOP $BASHPID; exec ${exe_native} ) &
#echo ${bench}
#echo $BASHPID
${exe_native} &
pid=$!
sleep 0.02
kill -SIGSTOP ${pid}
wait
