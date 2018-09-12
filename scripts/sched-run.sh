#!/bin/bash

#./clean-build.sh
source /opt/intel/vtune_amplifier_2018/amplxe-vars.sh
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${PARSECROOT}/pkgs/libs/hooks/inst/amd64-linux.gcc-hooks/lib
mkdir -p dump/experiments
input=simsmall

for iter in $(seq 1 1 1000); do
	numactl -m 0 ./scheduler/build/sched > dump/experiments/exp_$(hostname)_$(date -I)_${input}_revised-roi_${iter}.txt
	#echo "Iteration-${iter} finished"
done
wait
