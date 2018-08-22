#!/bin/bash

# Runs the canneal benchmarks on KNL 
parsec_dir=${PARSECROOT}
benchmark="parsec.canneal"
nthreads=1
input=native


# Run the benchmark natively
mkdir -p dump
echo "[DATE2019-Exp]: Linux Kernel Version $(uname -r)..."
echo "[DATE2019-Exp]: Cleaning and (Re)Building ${benchmark}"
echo ""
#${parsec_dir}/bin/parsecmgmt -a fulluninstall -p ${benchmark} parsec.hooks
#${parsec_dir}/bin/parsecmgmt -a build -p ${benchmark} -c gcc-hooks
echo "[DATE2019-Exp]: ${benchmark} built"
${parsec_dir}/bin/parsecmgmt -a run -p ${benchmark} -c gcc-hooks -i ${input} -n ${nthreads} | tee dump/${benchmark}.log
echo ""
echo ""
echo "[DATE2019-Exp]: ${benchmark} complete..."
#killall coapp
#rm coapp
