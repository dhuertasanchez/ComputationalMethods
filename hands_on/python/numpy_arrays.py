import numpy as np

n_points = 10

# creates an arrays full of ones
a = np.ones(n_points)
print a

# creates an arrays full of zeroes
a = np.zeros(n_points)
print a

#creates arrays of random numbers with a flat distribution
a = np.random.random(n_points)
b = np.random.random(n_points)

print a
print b

#multiplication is elementwise
print a*b

#creates a range of integers
a = np.arange(n_points)
b = np.arange(4,n_points)
print a, b


#scalar multiplication is also posible
print a*2
print a*3

# select subsamples
a = np.random.random(n_points)
index = np.where(a<0.5)
print index
index = index[0]
print index
print a[index]

#simple statistics in numpy
a = np.random.random(n_points)
print np.size(a)
print np.std(a)
print np.mean(a)

#create an empty array and append new items
a = np.empty(0)
print a
for i in range(n_points):
    a = np.append(a, np.random.random())
    print a
