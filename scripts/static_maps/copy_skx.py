#!/usr/bin/python3

import os


falloc_a = open("exp_alloc_a.csv","w")
falloc_b = open("exp_alloc_b.csv","w")
falloc_c = open("exp_alloc_c.csv","w")

for i in range(0,255,4):
	falloc_a.write(str(i)+",0\n")
	falloc_a.write(str(i)+",1\n")
	falloc_a.write(str(i)+",24\n")
	falloc_a.write(str(i)+",25\n")

	falloc_b.write(str(i)+",0\n")
	falloc_b.write(str(i)+",1\n")
	falloc_b.write(str(i)+",2\n")
	falloc_b.write(str(i)+",3\n")

	falloc_c.write(str(i)+",0\n")
	falloc_c.write(str(i)+",1\n")
	falloc_c.write(str(i)+",12\n")
	falloc_c.write(str(i)+",13\n")

falloc_a.close()
falloc_b.close()
falloc_c.close()
