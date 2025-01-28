#!/usr/bin/python
import sys
rate=.5
delta=.001
d0=float(sys.argv[1])
d1=float(sys.argv[2])
d2=float(sys.argv[3])
d3=float(sys.argv[4])
x=2*d3*((d0+rate*delta)**2-delta**2-d1**2)/(2*delta*d1)+delta
y=2*d3*((d1+rate*delta)**2-delta**2-d2**2)/(2*delta*d2)+delta
z=2*d3*((d2+rate*delta)**2-delta**2-d3**2)/(2*delta*d3)+delta
print(f'{x} {y} {z}')
