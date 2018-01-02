"""
2.4 numpy 基础运算2
"""

import numpy as np

A = np.arange(2,14).reshape((3,4))

print('A矩阵\n',A)

print('最小值索引(argument minimum)\n',np.argmin(A))
print('最大值索引(argument maximum)\n',np.argmax(A))
print('整个矩阵的平均值\n',np.mean(A))
print('整个矩阵的平均值\n',A.mean())
print('整个矩阵的平均值\n',np.average(A))
print('A的中位数\n',np.median(A))
print(A)
print('A的累加和,即当前位置的值为前面所有元素的和（包括自身）\n',np.cumsum(A))
print('A的每两个元素的差\n', np.diff(A))
print('A中非0元素,返回两个array，第一个array是非0元素的行，第二个array是非0元素的列\n',np.nonzero(A))

B = np.arange(14,2,-1).reshape((3,4))
print('B矩阵\n',B)
print('对B中每行元素排序，默认从小到大\n', np.sort(B))

print('矩阵A\n', A)
print('矩阵A的转置\n',np.transpose(A))
print('矩阵A的转置\n',A.T)

print('矩阵A的转置乘以矩阵A\n',(A.T).dot(A))

print('让矩阵A中所有小于5的数等于5，所有大于9的数等于9\n', np.clip(A,5,9))

"""
numpy 的很多函数都提供了指定列或者行进行操作的功能
指定参数 axis 
         =0 表示对列进行操作
         =1 表示对行进行操作
"""
