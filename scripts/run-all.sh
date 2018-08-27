#!/bin/bash

mkdir -p dump

parsec_dir=${PARSECROOT}
nthreads=1
input="test"

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
dump="dump/run-all-${input}.txt"

for bench in ${benchmarks}; do
	echo "[DATE2019-Exp]: running ${bench} " >> ${dump}
	${parsec_dir}/bin/parsecmgmt -a run -p ${bench} -c gcc-hooks -i ${input} -n ${nthreads} >> ${dump}
	echo "------------------------------------------------------" >> ${dump}
done
