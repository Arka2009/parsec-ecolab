#!/bin/bash

mkdir -p dump
cp thrd_cpu_map.csv dump/
source run-blackscholes.sh
source run-bodytrack.sh
source run-canneal.sh
source run-dedup.sh
#source run-facesim.sh
source run-ferret.sh
source run-fluidanimate.sh
#source run-freqmine.sh
#source run-raytrace.sh
source run-streamcluster.sh
source run-swaptions.sh
#source run-vips.sh
#source run-x264.sh
