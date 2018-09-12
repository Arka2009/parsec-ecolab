#!/usr/bin/python3

import os


fa = open("exp_8nth_a.csv","w")
fb = open("exp_8nth_b.csv","w")
fc = open("exp_8nth_c.csv","w")
fd = open("exp_8nth_d.csv","w")
fe = open("exp_8nth_e.csv","w")

for i in range(0,255,8):
	# 8nth_alloc_a
	fa.write(str(i)+",0\n")
	fa.write(str(i+1)+",1\n")
	fa.write(str(i+2)+",2\n")
	fa.write(str(i+3)+",3\n")
	fa.write(str(i+4)+",4\n")
	fa.write(str(i+5)+",5\n")
	fa.write(str(i+6)+",6\n")
	fa.write(str(i+7)+",7\n")

	# 8nth_alloc_b
	fb.write(str(i)+",0\n")
	fb.write(str(i+1)+",2\n")
	fb.write(str(i+2)+",4\n")
	fb.write(str(i+3)+",6\n")
	fb.write(str(i+4)+",8\n")
	fb.write(str(i+5)+",10\n")
	fb.write(str(i+6)+",12\n")
	fb.write(str(i+7)+",14\n")
	
	# 8nth_alloc_c
	fc.write(str(i)+",0\n")
	fc.write(str(i+1)+",1\n")
	fc.write(str(i+2)+",2\n")
	fc.write(str(i+3)+",3\n")
	fc.write(str(i+4)+",32\n")
	fc.write(str(i+5)+",33\n")
	fc.write(str(i+6)+",34\n")
	fc.write(str(i+7)+",35\n")
	
	# 8nth_alloc_d
	fd.write(str(i)+",0\n")
	fd.write(str(i+1)+",2\n")
	fd.write(str(i+2)+",4\n")
	fd.write(str(i+3)+",6\n")
	fd.write(str(i+4)+",32\n")
	fd.write(str(i+5)+",34\n")
	fd.write(str(i+6)+",36\n")
	fd.write(str(i+7)+",38\n")

	# 8nth_alloc_e
	fe.write(str(i)+",0\n")
	fe.write(str(i+1)+",2\n")
	fe.write(str(i+2)+",16\n")
	fe.write(str(i+3)+",18\n")
	fe.write(str(i+4)+",32\n")
	fe.write(str(i+5)+",34\n")
	fe.write(str(i+6)+",48\n")
	fe.write(str(i+7)+",50\n")

fa.close()
fb.close()
fc.close()
fd.close()
fe.close()
