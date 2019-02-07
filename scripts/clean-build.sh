#!/bin/bash

parsec_dir=${PARSECROOT}
benchmarks="\
parsec.blackscholes \
parsec.canneal \
parsec.streamcluster \
"

#benchmarks="parsec.blackscholes"
${parsec_dir}/bin/parsecmgmt -a fulluninstall -p ${benchmarks} parsec.hooks
${parsec_dir}/bin/parsecmgmt -a build -p ${benchmarks} -c gcc-hooks
