#!/usr/bin/python3

import os


fa = open("exp_32nth_a.csv","w")
fb = open("exp_32nth_b.csv","w")

for i in range(0,255,16):
	# 32nth_alloc_a
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
	fa.write(str(i+16)+",32\n")
	fa.write(str(i+17)+",33\n")
	fa.write(str(i+18)+",34\n")
	fa.write(str(i+19)+",35\n")
	fa.write(str(i+20)+",36\n")
	fa.write(str(i+21)+",37\n")
	fa.write(str(i+22)+",38\n")
	fa.write(str(i+23)+",39\n")
	fa.write(str(i+24)+",40\n")
	fa.write(str(i+25)+",41\n")
	fa.write(str(i+26)+",42\n")
	fa.write(str(i+27)+",43\n")
	fa.write(str(i+28)+",44\n")
	fa.write(str(i+29)+",45\n")
	fa.write(str(i+30)+",46\n")
	fa.write(str(i+31)+",47\n")

	# 32nth_alloc_b
	fb.write(str(i)+",0\n")
	fb.write(str(i+1)+",2\n")
	fb.write(str(i+2)+",4\n")
	fb.write(str(i+3)+",6\n")
	fb.write(str(i+4)+",8\n")
	fb.write(str(i+5)+",10\n")
	fb.write(str(i+6)+",12\n")
	fb.write(str(i+7)+",14\n")
	fb.write(str(i+8)+",16\n")
	fb.write(str(i+9)+",18\n")
	fb.write(str(i+10)+",20\n")
	fb.write(str(i+11)+",22\n")
	fb.write(str(i+12)+",24\n")
	fb.write(str(i+13)+",26\n")
	fb.write(str(i+14)+",28\n")
	fb.write(str(i+15)+",30\n")
	fb.write(str(i+16)+",32\n")
	fb.write(str(i+17)+",34\n")
	fb.write(str(i+18)+",36\n")
	fb.write(str(i+19)+",38\n")
	fb.write(str(i+20)+",40\n")
	fb.write(str(i+21)+",42\n")
	fb.write(str(i+22)+",44\n")
	fb.write(str(i+23)+",46\n")
	fb.write(str(i+24)+",48\n")
	fb.write(str(i+25)+",50\n")
	fb.write(str(i+26)+",52\n")
	fb.write(str(i+27)+",54\n")
	fb.write(str(i+28)+",56\n")
	fb.write(str(i+29)+",58\n")
	fb.write(str(i+30)+",60\n")
	fb.write(str(i+31)+",62\n")
	
	
fa.close()
fb.close()