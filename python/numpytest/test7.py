"""
2.7 numpy array 的分割
"""
import numpy as np
A = np.arange(12).reshape((3,4))
print('矩阵A\n',A)

# 以下分割需进行等量分割，若不能等量分割，则会报错
print('把矩阵a按水平方向（行）分割成2部分\n',np.split(A, 2, axis=1))
print('把矩阵a按垂直方向（列）分割成3部分\n',np.split(A, 3, axis=0))

# 对矩阵进行不等量分割
print('把矩阵A的4列分割成3列（也就是水平方向进行分割）\n',np.array_split(A,3,axis=1))

# 更简单的分割
print('对A垂直方向分割成3份\n',np.vsplit(A,3))
print('对A水平方向分割成2份\n',np.hsplit(A,2))
