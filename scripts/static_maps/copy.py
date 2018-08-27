#!/usr/bin/python3

import os


f1a1 = open("exp1a_alloc1.csv","w")
f1a2 = open("exp1a_alloc2.csv","w")
f1b1 = open("exp1b_alloc1.csv","w")
f1b2 = open("exp1b_alloc2.csv","w")
f2a1 = open("exp2a_alloc1.csv","w")
f2a2 = open("exp2a_alloc2.csv","w")
f2b1 = open("exp2b_alloc1.csv","w")
f2b2 = open("exp2b_alloc2.csv","w")
f12c = open("exp12c.csv","w")

for i in range(0,255,2):
	f1a1.write(str(i)+",0\n")
	f1a1.write(str(i+1)+",64\n")
	f1a2.write(str(i)+",0\n")
	f1a2.write(str(i+1)+",1\n")
	f2a1.write(str(i)+",0\n")
	f2a1.write(str(i+1)+",1\n")
	f2a2.write(str(i)+",0\n")
	f2a2.write(str(i+1)+",2\n")

for i in range(0,255,4):
	f1b1.write(str(i)+",0\n")
	f1b1.write(str(i+1)+",64\n")
	f1b1.write(str(i+2)+",128\n")
	f1b1.write(str(i+3)+",192\n")
	f1b2.write(str(i)+",0\n")
	f1b2.write(str(i+1)+",1\n")
	f1b2.write(str(i+2)+",64\n")
	f1b2.write(str(i+3)+",65\n")
	f2b1.write(str(i)+",0\n")
	f2b1.write(str(i+1)+",1\n")
	f2b1.write(str(i+2)+",64\n")
	f2b1.write(str(i+3)+",65\n")
	f2b2.write(str(i)+",0\n")
	f2b2.write(str(i+1)+",2\n")
	f2b2.write(str(i+2)+",4\n")
	f2b2.write(str(i+3)+",6\n")

for i in range(0,255,4):
	f12c.write(str(i)+",0\n")
	f12c.write(str(i+1)+",1\n")
	f12c.write(str(i+2)+",2\n")
	f12c.write(str(i+3)+",3\n")


f1a1.close()
f1a2.close()
f2a1.close()
f2a2.close()
f1b1.close()
f1b2.close()
f2b1.close()
f2b2.close()
f12c.close()
