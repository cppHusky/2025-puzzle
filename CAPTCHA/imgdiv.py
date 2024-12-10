#!.venv/bin/python3
import sys
from PIL import Image
import os
input_path=sys.argv[1]
output_dir=sys.argv[2]
with Image.open(input_path)as img:
	img=img.convert("RGB")
	width,height=img.size
	part_width=width//4
	part_height=height//4
	for row in range(4):
		for col in range(4):
			left=col*part_width
			upper=row*part_height
			right=left+part_width
			lower=upper+part_height
			cropped_part=img.crop((left,upper,right,lower))
			output_filename=f"part_{row+1}_{col+1}.png"
			output_path=os.path.join(output_dir,output_filename)
			cropped_part.save(output_path)
			print(f"Saved: {output_path}")
