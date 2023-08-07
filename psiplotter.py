import numpy as np
from matplotlib import pyplot as plt



#real=open("real.txt", "r")

#realdata=np.loadtxt("reborn.txt")
#imdata=np.loadtxt("repsi.txt")
#imdata=np.loadtxt("schrodinger.txt")
imdata2=np.genfromtxt("DCS_Ar_50_eV.csv", delimiter=',')
imdata=np.loadtxt("sigma.txt")
#print(imdata)

i=0
abserror=[]
#print(np.size(imdata2[:,1]))
while (i<=np.size(imdata)-1):

	abserror.append(abs(imdata2[i, 1]-imdata[i]))

	i=i+1
	
print(max(abserror))
print(min(abserror))

#rr=np.linspace(-1, 1, len(imdata))

#plt.plot(rr, realdata)
#plt.show()

x=np.linspace(0, 180, np.size(imdata))
plt.plot(x, imdata, label='QRONUS')
plt.plot(x, imdata2[:,1], label='NIST')
plt.legend()
#plt.yscale('log')
plt.show()
