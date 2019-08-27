#!/usr/bin/python3

import os


fa = open("exp_4nth_a.csv","w")
fb = open("exp_4nth_b.csv","w")
fc = open("exp_4nth_c.csv","w")
fd = open("exp_4nth_d.csv","w")
fe = open("exp_4nth_e.csv","w")

for i in range(0,255,4):
	# 4nth_alloc_a
	fa.write(str(i)+",0\n")
	fa.write(str(i+1)+",64\n")
	fa.write(str(i+2)+",128\n")
	fa.write(str(i+3)+",192\n")

	# 4nth_alloc_b
	fb.write(str(i)+",0\n")
	fb.write(str(i+1)+",1\n")
	fb.write(str(i+2)+",64\n")
	fb.write(str(i+3)+",65\n")

	# 4nth_alloc_c
	fc.write(str(i)+",0\n")
	fc.write(str(i+1)+",1\n")
	fc.write(str(i+2)+",2\n")
	fc.write(str(i+3)+",3\n")
	

	# 4nth_alloc_d
	fd.write(str(i)+",0\n")
	fd.write(str(i+1)+",2\n")
	fd.write(str(i+2)+",4\n")
	fd.write(str(i+3)+",6\n")

	# 4nth_alloc_e
	fe.write(str(i)+",0\n")
	fe.write(str(i+1)+",16\n")
	fe.write(str(i+2)+",32\n")
	fe.write(str(i+3)+",48\n")

fa.close()
fb.close()
fc.close()
fd.close()
fe.close()
