import numpy as np
import matplotlib.pyplot as plt
import sys

if(len(sys.argv) != 2):
    print("Error, use: python dotplot.py <dotplot.txt>")
    exit()

input = np.loadtxt(sys.argv[1], dtype='i', delimiter=' ')

mshape = input.shape

print(' > Input shape: {}'.format(mshape))

# Add a border to the plot

bordermat = np.zeros((mshape[0]+2, mshape[1]+2))
bordermat[0, :] = 1
bordermat[-1, :] = 1
bordermat[:, 0] = 1
bordermat[:, -1] = 1

# And copy the other matrix within

bordermat[1:-1, 1:-1] = input[:, :]

plt.imsave(sys.argv[1]+".png", bordermat, cmap='gray_r')
