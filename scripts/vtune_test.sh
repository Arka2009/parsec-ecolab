#!/bin/bash

source /opt/intel/vtune_amplifier_2018/amplxe-vars.sh
parsec_dir=/home/amaity/Desktop/parsec-3.0
lib=${parsec_dir}/pkgs/libs/hooks/inst/amd64-linux.gcc-hooks/lib
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${lib}
mkdir -p log
nthreads="3"

exe_native=(\
 "${parsec_dir}/pkgs/apps/blackscholes/inst/amd64-linux.gcc-hooks/bin/blackscholes ${nthreads} ${parsec_dir}/pkgs/apps/blackscholes/inputs/in_10M.txt dump/prices.txt")
 #"${parsec_dir}/pkgs/apps/bodytrack/inst/amd64-linux.gcc-hooks/bin/bodytrack ${parsec_dir}/pkgs/apps/bodytrack/inputs/sequenceB_261 4 261 4000 5 0 ${nthreads}"\
 #"${parsec_dir}/pkgs/kernels/canneal/inst/amd64-linux.gcc-hooks/bin/canneal ${nthreads} 15000 2000 ${parsec_dir}/pkgs/kernels/canneal/inputs/2500000.nets 6000"\
 #"${parsec_dir}/pkgs/kernels/dedup/inst/amd64-linux.gcc-hooks/bin/dedup -c -p -v -t ${nthreads} -i ${parsec_dir}/pkgs/kernels/dedup/inputs/FC-6-x86_64-disc1.iso -o dump/output.dat.ddp"\
 #"${parsec_dir}/pkgs/apps/ferret/inst/amd64-linux.gcc-hooks/bin/ferret ${parsec_dir}/pkgs/apps/ferret/inputs/corel lsh ${parsec_dir}/pkgs/apps/ferret/inputs/queries 50 20 ${nthreads} dump/output.txt"\
 #"${parsec_dir}/pkgs/apps/fluidanimate/inst/amd64-linux.gcc-hooks/bin/fluidanimate ${nthreads} 500 ${parsec_dir}/pkgs/apps/fluidanimate/inputs/in_500K.fluid dump/out.fluid"\
 #"/home/amaity/Desktop/parsec-3.0/pkgs/apps/raytrace/inst/amd64-linux.gcc-hooks/bin/rtview /home/amaity/Desktop/parsec-3.0/pkgs/apps/raytrace/inputs/thai_statue.obj -automove -nthreads ${nthreads} -frames 200 -res 1920 1080"\
 #"${parsec_dir}/pkgs/kernels/streamcluster/inst/amd64-linux.gcc-hooks/bin/streamcluster 10 20 128 1000000 200000 5000 none dump/output.txt ${nthreads}"\
 #"${parsec_dir}/pkgs/apps/swaptions/inst/amd64-linux.gcc-hooks/bin/swaptions -ns 128 -sm 1000000 -nt ${nthreads}")




affinity="0,1,2,3"
aff_prefix="numactl -m 0 taskset -c ${affinity}"
#amplxe-cl -r log/amplrpt2 -collect-with runsa -knob event-config=CPU_CLK_UNHALTED.THREAD,INST_RETIRED.ANY,MEM_UOPS_RETIRED.ALL_LOADS,MEM_UOPS_RETIRED.L1_MISS_LOADS,MEM_UOPS_RETIRED.L2_HIT_LOADS,MEM_UOPS_RETIRED.L2_MISS_LOADS,UNC_M_CAS_COUNT.ALL -target-pid ${pid}
#amplxe-cl -r log/amplrpt2 -collect-with runsa -knob event-config=CPU_CLK_UNHALTED.THREAD,INST_RETIRED.ANY,MEM_UOPS_RETIRED.ALL_LOADS,OFFCORE_RESPONSE:request=DEMAND_DATA_RD:response=ANY_RESPONSE -target-pid ${pid}

#event_list="\
#OFFCORE_RESPONSE:request=DEMAND_DATA_RD:response=ANY_RESPONSE \
#OFFCORE_RESPONSE:request=DEMAND_DATA_RD:response=L2_HIT_NEAR_TILE \
#OFFCORE_RESPONSE:request=DEMAND_DATA_RD:response=L2_HIT_FAR_TILE \
#OFFCORE_RESPONSE:request=DEMAND_DATA_RD:response=DDR \
#OFFCORE_RESPONSE:request=DEMAND_DATA_RD:response=L2_HIT_THIS_TILE_M \
#OFFCORE_RESPONSE:request=DEMAND_DATA_RD:response=L2_HIT_THIS_TILE_E \
#OFFCORE_RESPONSE:request=DEMAND_DATA_RD:response=L2_HIT_THIS_TILE_S \
#OFFCORE_RESPONSE:request=DEMAND_DATA_RD:response=L2_HIT_THIS_TILE_F \
#OFFCORE_RESPONSE:request=DEMAND_DATA_RD:response=L2_MISS \
#"
#for evt in ${event_list}; do 
#	mkdir -p log
#	${aff_prefix} ${parsec_dir}/pkgs/apps/blackscholes/inst/amd64-linux.gcc-hooks/bin/blackscholes ${nthreads} ${parsec_dir}/pkgs/apps/blackscholes/inputs/in_10M.txt dump/prices.txt &
#	pid=$!
#	echo ${pid}
#	amplxe-cl -r log/amplrpt2 -collect-with runsa -knob event-config=CPU_CLK_UNHALTED.THREAD,INST_RETIRED.ANY,MEM_UOPS_RETIRED.ALL_LOADS,${evt} -target-pid ${pid}
#	#amplxe-cl -R summary -result-dir=log/amplrpt2 -report-output log/general-${evt}.csv -format csv -csv-delimiter comma
#	rm -rf log*
#	wait
#done

event_list_all="\
OFFCORE_RESPONSE:request=PF_L1_DATA_RD:response=ANY_RESPONSE,\
OFFCORE_RESPONSE:request=PF_L1_DATA_RD:response=L2_HIT_THIS_TILE_M,\
OFFCORE_RESPONSE:request=PF_L1_DATA_RD:response=L2_HIT_THIS_TILE_E,\
OFFCORE_RESPONSE:request=PF_L1_DATA_RD:response=L2_HIT_THIS_TILE_S,\
OFFCORE_RESPONSE:request=PF_L1_DATA_RD:response=L2_HIT_THIS_TILE_F,\
OFFCORE_RESPONSE:request=PF_L1_DATA_RD:response=L2_HIT_NEAR_TILE,\
OFFCORE_RESPONSE:request=PF_L1_DATA_RD:response=L2_HIT_FAR_TILE,\
OFFCORE_RESPONSE:request=PF_L1_DATA_RD:response=DDR,\
OFFCORE_RESPONSE:request=PF_L1_DATA_RD:response=L2_MISS,\
OFFCORE_RESPONSE:request=DEMAND_DATA_RD:response=ANY_RESPONSE,\
OFFCORE_RESPONSE:request=DEMAND_DATA_RD:response=L2_HIT_THIS_TILE_M,\
OFFCORE_RESPONSE:request=DEMAND_DATA_RD:response=L2_HIT_THIS_TILE_E,\
OFFCORE_RESPONSE:request=DEMAND_DATA_RD:response=L2_HIT_THIS_TILE_S,\
OFFCORE_RESPONSE:request=DEMAND_DATA_RD:response=L2_HIT_THIS_TILE_F,\
OFFCORE_RESPONSE:request=DEMAND_DATA_RD:response=L2_HIT_NEAR_TILE,\
OFFCORE_RESPONSE:request=DEMAND_DATA_RD:response=L2_HIT_FAR_TILE,\
OFFCORE_RESPONSE:request=DEMAND_DATA_RD:response=DDR,\
OFFCORE_RESPONSE:request=DEMAND_DATA_RD:response=L2_MISS,\
"

blackscholes_bin="${parsec_dir}/pkgs/apps/blackscholes/inst/amd64-linux.gcc-hooks/bin/blackscholes"
blackscholes_input="${nthreads} ${parsec_dir}/pkgs/apps/blackscholes/inputs/in_10M.txt dump/prices.txt"
streamcluster_bin="${parsec_dir}/pkgs/kernels/streamcluster/inst/amd64-linux.gcc-hooks/bin/streamcluster"
streamcluster_input="10 20 128 1000000 200000 5000 none dump/output.txt ${nthreads}"
#mkdir -p log
#${aff_prefix} ${blackscholes_bin} ${blackscholes_input} &
#${aff_prefix} ${streamcluster_bin} ${streamcluster_input} &
#pid=$!
#echo ${pid}
#amplxe-cl -r log/amplrpt2 -collect-with runsa -knob event-config=CPU_CLK_UNHALTED.THREAD,INST_RETIRED.ANY,MEM_UOPS_RETIRED.ALL_LOADS,${event_list_all} -target-pid ${pid}
amplxe-cl -R summary -result-dir=log/amplrpt2 -report-output general.csv -format csv -csv-delimiter comma
