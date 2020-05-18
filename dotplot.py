import numpy as np
import matplotlib.pyplot as plt

input = np.loadtxt("dotplot.txt", dtype='i', delimiter=' ')

mshape = input.shape

print(mshape)
print(input)

# Add a border to the plot

bordermat = np.zeros((mshape[0]+2, mshape[1]+2))
bordermat[0, :] = 1
bordermat[-1,:] = 1
bordermat[:, 0] = 1
bordermat[:,-1] = 1

# And copy the other matrix within

bordermat[1:-1,1:-1] = input[:,:]

plt.imsave("dotplot.png", bordermat, cmap='gray_r')
