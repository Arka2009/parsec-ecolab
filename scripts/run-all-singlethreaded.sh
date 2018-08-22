#!/bin/bash

parsec_dir=${PARSECROOT}
benchmarks="\
parsec.blackscholes \
parsec.bodytrack \
parsec.canneal \
parsec.dedup \
parsec.ferret \
parsec.fluidanimate \
parsec.streamcluster \
parsec.swaptions \
"

#benchmarks="parsec.blackscholes"
input="native"
nthreads=3
affinity="0-255"
mkdir -p dump

#${parsec_dir}/bin/parsecmgmt -a fulluninstall -p ${benchmarks} parsec.hooks
${parsec_dir}/bin/parsecmgmt -a build -p ${benchmarks} -c gcc-serial

for bench in ${benchmarks}; do
	echo "[DATE2019-Exp]: running serial ${bench} "
	taskset -c ${affinity} ${parsec_dir}/bin/parsecmgmt -a run -p ${bench} -c gcc-serial -i ${input} | tee dump/${bench}-serial.log
done
