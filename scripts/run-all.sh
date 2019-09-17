#!/bin/bash

mkdir -p dump

parsec_dir=${PARSECROOT}
nthreads=64
input="simsmall"

#benchmarks="\
#parsec.blackscholes \
#parsec.bodytrack \
#parsec.canneal \
#parsec.dedup \
#parsec.ferret \
#parsec.fluidanimate \
#parsec.streamcluster \
#parsec.raytrace \
#parsec.swaptions \
#"
benchmarks="parsec.streamcluster"
dump2="dump/run-all-${input}.txt"

for nthreads in $(seq 1 16); do
	for bench in ${benchmarks}; do
		echo "[DATE2019-Exp]: running ${bench} with threading Option ${nthreads}"
		${parsec_dir}/bin/parsecmgmt -a run -p ${bench} -c gcc-hooks -i ${input} -n ${nthreads}
		echo "------------------------------------------------------"
		echo ""
		echo ""
	done
done
