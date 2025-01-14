#!/usr/bin/python
#example: argv[0] 6 0 10
import sys,numpy
init_x=float(sys.argv[1])
init_y=float(sys.argv[2])
precision=int(sys.argv[3])#recommended <=20
init_r=numpy.sqrt(init_x**2+init_y**2)
init_theta=numpy.atan2(init_y,init_x)
origin_r=init_r/numpy.sqrt(3)
origin_theta=init_theta-numpy.pi/2
origin_x=origin_r*numpy.cos(origin_theta)
origin_y=origin_r*numpy.sin(origin_theta)
you_r=origin_r*2
for theta in range(0,360,precision):
	x=origin_x+you_r*numpy.cos(theta/180*numpy.pi+init_theta+numpy.pi/6)
	y=origin_y+you_r*numpy.sin(theta/180*numpy.pi+init_theta+numpy.pi/6)
	print(f"{x:7f} {y:7f}")
