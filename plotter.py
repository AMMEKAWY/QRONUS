from numpy import genfromtxt
import numpy as np
from matplotlib import pyplot as plt

#y = genfromtxt('soln.csv', delimiter=',')
#y2 = genfromtxt('soln2.csv', delimiter=',')

y=np.loadtxt("sigma.txt")

#y2=np.loadtxt("bessel.txt")

#y2=np.loadtxt("sch2.txt")

#y4=np.loadtxt("sch4.txt")

x = np.linspace(0, 4, len(y))

#plt.plot(y)

plt.plot(y)

#plt.plot(y, label='shifted wv fn')
#plt.plot(y2, label='unshifted wv fn')
#plt.plot(y4, label='l=4')

#plt.plot(y[1])

#plt.plot(y[2])

#plt.plot(y[5])
#plt.plot(y[1,:])
#plt.plot(y[3,:])
#plt.plot(y)

#plt.plot(y[5,:])

#plt.plot(y[:, 4])

#plt.plot(y[:, 5])

#plt.legend()

plt.show()
