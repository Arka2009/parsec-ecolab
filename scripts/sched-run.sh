#!/bin/bash

#./clean-build.sh
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${PARSECROOT}/pkgs/libs/hooks/inst/amd64-linux.gcc-hooks/lib
mkdir -p dump
numactl -m 0 ./scheduler/build/sched > dump/experiments_simsmall_$(date -I).txt
#perf stat -e mem_uops_retired.l2_miss_loads:u -p $(pgrep blackscholes)
#wait
