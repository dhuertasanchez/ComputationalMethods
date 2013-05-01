'''
Created on Apr 20, 2013

@author: DanielFelipe
'''
import pylab
import sys
import numpy as np
r_datos = sys.path[1]+'\data\hw5_data\monthrg.dat' 
datos = open(r_datos,'r')
#Punto 1
t = []
rg = []
for line in datos:
    t.append(float(line[1:5])+(1.0/12.0)*float(line[6:8].replace(' ','')))
    rg.append(float(line[11:24].replace(' ','')))
pylab.figure(1)
pylab.plot(t, rg)
pylab.xlabel('time (y)')
pylab.ylabel('Mean rg')
pylab.title('Punto 1')
pylab.grid(True)
pylab.savefig('Punto 1')

#Punto 2
n = len(rg)
fourier = np.fft.fft(rg)/n
timestep = 1.0/12.0
freq = np.fft.fftfreq(n, d=timestep)
#Punto 3
def sqrt_norm(x):
    return abs(x)**2
P_fourier = map(sqrt_norm,fourier)
pylab.figure(2)
pylab.xlim(-1,1)
pylab.plot(freq,P_fourier)
pylab.xlabel('frecuency(y^-1)')
pylab.ylabel('Square Mean of fft(rg)')
pylab.title('Punto 3')
pylab.grid(True)
pylab.savefig('Punto 3')
#Punto 4
def freq_to_T(n_freq):
    return 1/n_freq
T = map(freq_to_T,freq)
pylab.figure(3)
pylab.xlim(1,20)
pylab.plot(T,P_fourier)
pylab.xlabel('Period(years)')
pylab.ylabel('Square Mean of fft(rg)')
pylab.title('Punto 4')
pylab.grid(True)
pylab.savefig('Punto 4')
#Punto 5
def frec_filter(frec,spectrum):
    if abs(frec)>(1.0/20.0):
        return 0
    else:
        return spectrum

Filt_fourier = map(frec_filter,freq,fourier)
Filt_rg = np.fft.ifft(Filt_fourier)*n
pylab.figure(4)
pylab.plot(t,Filt_rg)
pylab.xlabel('time (y)')
pylab.ylabel('Mean rg filtered')
pylab.title('Punto 5')
pylab.grid(True)
pylab.savefig('Punto 5')

#Punto 6
def frec_filter2(frec,spectrum):
    if abs(frec)<(1.0/20.0):
        return 0
    else:
        return spectrum
Filt_fourier2 = map(frec_filter2,freq,fourier)
P_Filt_fourier2 = map(sqrt_norm,Filt_fourier2)
T_max_rg = 1/abs(freq[P_Filt_fourier2.index(max(P_Filt_fourier2))])
print T_max_rg
start_index = len(rg) - int(T_max_rg*12)
max_rg = -1
max_pos = -1
for i in range(start_index,len(rg)):
    rg_temp  = rg[i]
    if abs(rg_temp)>max_rg:
        max_rg = abs(rg_temp)
        max_pos = i
print max_rg
print max_pos
date_year = int(t[max_pos]+T_max_rg)
date_month = int(t[max_pos]+T_max_rg)%12
print 'El siguiente maximo solar tendra lugar en : '+str(date_year)+' En el mes: '+ str(date_month)
pylab.show()