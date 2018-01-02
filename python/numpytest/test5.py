# coding:utf8
"""
2.5 numpy 的索引
"""

import numpy as np

A = np.arange(3, 15)
print('矩阵A\n',A)
print('输出A[2]\n',A[2])
A = A.reshape(3, 4)
print('shape 过后 （3,4），输出A[2]\n',A[2])
print(A[2][1])
print(A[2,1])
print(A[1, 1:3])
print(A[2,:])

print('print rows')
for row in A:
    print(row)

print('print column')
for col in A.T:
    print(col)


print('matrix A to array\n', A.flatten())
print('print item in matrix A')
for item in A.flat:
    print(item)
