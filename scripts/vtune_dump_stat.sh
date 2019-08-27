#!/bin/bash

source /opt/intel/vtune_amplifier_2018/amplxe-vars.sh
benchmarks="\
blackscholes_rpt2 \
canneal_rpt2 \
streamcluster_rpt2 \
"

allocs="vtune_alloc_c vtune_alloc_d vtune_alloc_e"

for alloc in ${allocs}; do
	for bench in ${benchmarks}; do
		amplxe-cl -R summary -result-dir=${alloc}/${bench} -report-output ${alloc}_${bench}.csv -format csv -csv-delimiter comma
	done
done
