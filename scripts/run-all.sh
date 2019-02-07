#!/bin/bash

mkdir -p dump

parsec_dir=${PARSECROOT}
nthreads=64
input="simsmall"

benchmarks="\
parsec.blackscholes \
parsec.bodytrack \
parsec.canneal \
parsec.dedup \
parsec.ferret \
parsec.fluidanimate \
parsec.streamcluster \
parsec.raytrace \
parsec.swaptions \
"
#benchmarks="parsec.canneal"
dump="dump/run-all-${input}.txt"

for bench in ${benchmarks}; do
	echo "[DATE2019-Exp]: running ${bench} "
	${parsec_dir}/bin/parsecmgmt -a run -p ${bench} -c gcc-hooks -i ${input} -n ${nthreads}
	echo "------------------------------------------------------"
done
