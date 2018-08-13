#!/bin/bash

# Runs the Blackscholes benchmarks on KNL 
parsec_dir=/home/amaity/Desktop/parsec-3.0
benchmark="parsec.swaptions"
nthreads=4
input=native


# Run the benchmark natively
echo "[DATE2019-Exp]: Linux Kernel Version $(uname -r)..."
echo "[DATE2019-Exp]: Building ${benchmark}"
echo ""
${parsec_dir}/bin/parsecmgmt -a fulluninstall -p ${benchmark} parsec.hooks
${parsec_dir}/bin/parsecmgmt -a build -p ${benchmark} -c gcc-hooks
${parsec_dir}/bin/parsecmgmt -a run -p ${benchmark} -c gcc-hooks -i ${input} -n ${nthreads}
echo ""
echo ""
echo "[DATE2019-Exp]: ${benchmark} complete..."
