#!/usr/bin/python3

import os


fa = open("exp_16nth_a.csv","w")
fb = open("exp_16nth_b.csv","w")
fc = open("exp_16nth_c.csv","w")

for i in range(0,255,16):
	# 16nth_alloc_a
	fa.write(str(i)+",0\n")
	fa.write(str(i+1)+",1\n")
	fa.write(str(i+2)+",2\n")
	fa.write(str(i+3)+",3\n")
	fa.write(str(i+4)+",4\n")
	fa.write(str(i+5)+",5\n")
	fa.write(str(i+6)+",6\n")
	fa.write(str(i+7)+",7\n")
	fa.write(str(i+8)+",8\n")
	fa.write(str(i+9)+",9\n")
	fa.write(str(i+10)+",10\n")
	fa.write(str(i+11)+",11\n")
	fa.write(str(i+12)+",12\n")
	fa.write(str(i+13)+",13\n")
	fa.write(str(i+14)+",14\n")
	fa.write(str(i+15)+",15\n")

	# 16nth_alloc_b
	fb.write(str(i)+",0\n")
	fb.write(str(i+1)+",2\n")
	fb.write(str(i+2)+",4\n")
	fb.write(str(i+3)+",6\n")
	fb.write(str(i+4)+",8\n")
	fb.write(str(i+5)+",10\n")
	fb.write(str(i+6)+",12\n")
	fb.write(str(i+7)+",14\n")
	fb.write(str(i+8)+",32\n")
	fb.write(str(i+9)+",34\n")
	fb.write(str(i+10)+",36\n")
	fb.write(str(i+11)+",38\n")
	fb.write(str(i+12)+",40\n")
	fb.write(str(i+13)+",42\n")
	fb.write(str(i+14)+",44\n")
	fb.write(str(i+15)+",46\n")
	
	# 16nth_alloc_c
	fc.write(str(i)+",0\n")
	fc.write(str(i+1)+",2\n")
	fc.write(str(i+2)+",4\n")
	fc.write(str(i+3)+",6\n")
	fc.write(str(i+4)+",16\n")
	fc.write(str(i+5)+",18\n")
	fc.write(str(i+6)+",20\n")
	fc.write(str(i+7)+",22\n")
	fc.write(str(i+8)+",32\n")
	fc.write(str(i+9)+",34\n")
	fc.write(str(i+10)+",36\n")
	fc.write(str(i+11)+",38\n")
	fc.write(str(i+12)+",48\n")
	fc.write(str(i+13)+",50\n")
	fc.write(str(i+14)+",52\n")
	fc.write(str(i+15)+",54\n")
	
fa.close()
fb.close()
fc.close()