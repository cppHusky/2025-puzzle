#!/bin/python3
import qrcode,numpy,sys
qr=qrcode.QRCode(version=None,box_size=1,border=0,error_correction=qrcode.constants.ERROR_CORRECT_L)
qr.add_data("https://qm.qq.com/cgi-bin/qm/qr?k=lCvyGfaFoSqZX3ijP5NzHWUtwC_feD0s")
img=qr.make_image(fill_color="black",back_color="white")
img.save(sys.argv[1])
matrix=qr.get_matrix()
print(len(matrix))
origin='\n'.join([''.join([('1' if cell else '0') for cell in row]) for row in matrix])
f=open("origin.txt","w")
print(origin,file=f)
