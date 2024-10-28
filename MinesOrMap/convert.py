#!/bin/python3
import array
import numpy
import qrcode
import random
import sys
qr=qrcode.QRCode(version=None,box_size=1,border=0,error_correction=qrcode.constants.ERROR_CORRECT_L)
qr.add_data("https://qm.qq.com/cgi-bin/qm/qr?k=lCvyGfaFoSqZX3ijP5NzHWUtwC_feD0s")
img=qr.make_image(fill_color="black",back_color="white")
img.save("origin.png")
matrix=qr.get_matrix()
Maps=3
Cells=len(matrix)
origin='\n'.join([''.join([('1' if cell else '0') for cell in row]) for row in matrix])
f=open("origin.txt","w")
print(origin,file=f)
numof1=sum((row.count(True)) for row in matrix)
beta=numof1/Cells**2
alpha=1-(1-beta)**(1/Maps)
def get_p(k,met):
    if(k==0):
        return alpha/beta
    else:
        return alpha if(met) else alpha/(1-(1-alpha)**(Maps-k))
def bayes():
    arr=[None]*Maps
    met=False
    for i in range(Maps):
        if(random.random()<get_p(i,met)):
            arr[i]=met=True
        else:
            arr[i]=False
    return arr
matarr=[[None for _ in range(Cells)] for _ in range(Cells)]
for i in range(Cells):
    for j in range(Cells):
        matarr[i][j]=bayes() if(matrix[i][j]) else [False]*Maps
matarr=list(map(list,zip(*[list(map(list,zip(*mat))) for mat in matarr])))
for i in range(Maps):
    minestr='\n'.join([''.join([('1' if cell else '0') for cell in row]) for row in matarr[i]])
    f=open(f"map{i}.txt","w")
    print(minestr,file=f)
    print(f"{sum((row.count(True)) for row in matarr[i])} 1s in map{i}.txt.")
