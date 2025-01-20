#!/usr/bin/python
#example: argv[0] 2 0 10
import sys,numpy
init_x=float(sys.argv[1])
init_y=float(sys.argv[2])
precision=int(sys.argv[3])#recommended <=10
speed=.95
alpha=numpy.asin(speed)
init_r=numpy.sqrt(init_x**2+init_y**2)
init_theta=numpy.atan2(init_y,init_x)
circle_r=init_r*numpy.tan(alpha)
circle_theta=init_theta-numpy.pi/2
circle_x=circle_r*numpy.cos(circle_theta)
circle_y=circle_r*numpy.sin(circle_theta)
you_r=circle_r/numpy.sin(alpha)
print(f"the radius of enemy's circle is {circle_r}. Here is recommended moving path:")
for theta in range(0,360,precision):
	x=circle_x+you_r*numpy.cos(theta/180*numpy.pi+init_theta+alpha)
	y=circle_y+you_r*numpy.sin(theta/180*numpy.pi+init_theta+alpha)
	print(f"{x:7f} {y:7f}")
