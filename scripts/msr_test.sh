#!/bin/bash


# start a process under "perf stat" that stalls waiting on stdin and put it in the background
# bind the process to core 1 so I know where to look for the counter programming
taskset -c 1 perf stat -e L1-dcache-load-misses cat >/dev/null &
 
# Now read the counters manually -- since the process context has changed, the
# counters will be disabled, but "perf stat" typically does not modify the other bits
# of the PERF_EVT_SEL MSRs

rdmsr -p 1 0x186
rdmsr -p 1 0x187
rdmsr -p 1 0x188
rdmsr -p 1 0x189
rdmsr -p 1 0x18a
rdmsr -p 1 0x18b
rdmsr -p 1 0x18c
rdmsr -p 1 0x18d

wait
