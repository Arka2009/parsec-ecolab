#!/bin/bash

# Runs the blackscholes benchmarks on KNL 
parsec_dir=${PARSECROOT}
benchmark="parsec.blackscholes"
nthreads=1
input="test"


# Run the benchmark natively
mkdir -p dump
echo "[DATE2019-Exp]: Linux Kernel Version $(uname -r)..."
echo "[DATE2019-Exp]: Cleaning and (Re)Building ${benchmark}"
echo ""
${parsec_dir}/bin/parsecmgmt -a fulluninstall -p ${benchmark} parsec.hooks
${parsec_dir}/bin/parsecmgmt -a build -p ${benchmark} -c gcc-hooks
echo "[DATE2019-Exp]: ${benchmark} built"
${parsec_dir}/bin/parsecmgmt -a run -p ${benchmark} -c gcc-hooks -i ${input} -n ${nthreads} | tee dump/${benchmark}-${nthreads}.log
echo ""
echo ""
echo "[DATE2019-Exp]: ${benchmark} complete..."
#killall coapp
#rm coapp
