#!/bin/bash

for i in $(seq 1 1 7); do
	cp app_0_map.csv app_${i}_map.csv
done
