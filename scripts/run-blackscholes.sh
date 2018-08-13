#!/bin/bash

# Runs the Blackscholes benchmarks on KNL 
parsec_dir=${PARSECROOT}
benchmark="parsec.blackscholes"
nthreads=2
input=test


# Run the benchmark natively
echo "[DATE2019-Exp]: Linux Kernel Version $(uname -r)..."
echo "[DATE2019-Exp]: Cleaning and (Re)Building ${benchmark}"
echo ""
${parsec_dir}/bin/parsecmgmt -a fulluninstall -p ${benchmark} parsec.hooks
${parsec_dir}/bin/parsecmgmt -a build -p ${benchmark} -c gcc-hooks
echo "[DATE2019-Exp]: ${benchmark} built"
#gcc -O3 ${parsec_dir}/scripts/busy_spin.c -o coapp
#echo "[DATE2019-Exp]: Starting a co-application"
#taskset -c 2 ./coapp coapp1 &
#taskset -c 3 ./coapp coapp2 &
#taskset -c 5 ./coapp coapp3 &
${parsec_dir}/bin/parsecmgmt -a run -p ${benchmark} -c gcc-hooks -i ${input} -n ${nthreads}
echo ""
echo ""
echo "[DATE2019-Exp]: ${benchmark} complete..."
#killall coapp
rm coapp
