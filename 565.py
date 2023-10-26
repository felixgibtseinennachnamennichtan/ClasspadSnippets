from PIL import Image
import numpy as np

image = Image.open("image.png")
image = image.convert("RGBA")
arr = np.asarray(image)
out = []
for row in arr:
	for pixel in row:
		pix565 = (((pixel[0]<<8) & 0b1111100000000000) |((pixel[1]<<3) & 0b0000011111100000) | ((pixel[2]>>3) & 0b0000000000011111))
		print(pix565)
		out.append(pix565>>8)
		out.append(pix565&0xff)
f = open("out.bin", "wb")
f.write(bytearray(out))
f.close()