#!/bin/bash

while :
do
	for i in $(pgrep blackscholes); do ps -mo pid,tid,fname,user,psr -p $i && numastat -p $i;done
	for i in $(pgrep bodytrack); do ps -mo pid,tid,fname,user,psr -p $i && numastat -p $i;done
	for i in $(pgrep canneal); do ps -mo pid,tid,fname,user,psr -p $i && numastat -p $i;done
	for i in $(pgrep ferret); do ps -mo pid,tid,fname,user,psr -p $i && numastat -p $i;done
	for i in $(pgrep fluidanimate); do ps -mo pid,tid,fname,user,psr -p $i && numastat -p $i;done
	for i in $(pgrep dedup); do ps -mo pid,tid,fname,user,psr -p $i && numastat -p $i;done
	for i in $(pgrep rtview); do ps -mo pid,tid,fname,user,psr -p $i && numastat -p $i;done
	for i in $(pgrep swaptions); do ps -mo pid,tid,fname,user,psr -p $i && numastat -p $i;done
	for i in $(pgrep streamcluster); do ps -mo pid,tid,fname,user,psr -p $i && numastat -p $i;done
	#for i in $(pgrep sched); do ps -mo pid,tid,fname,user,psr -p $i && numastat -p $i;done

	sleep 1
done
