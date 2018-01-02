# coding:utf8
"""
2.6 numpy的array合并
"""
import numpy as np

A = np.array([1,1,1])
B = np.array([2,2,2])

print('vertical stack\n', np.vstack((A, B)))
print('vertical stack\n', np.hstack((A, B)))

print('一维向量无法转置\n', A.T)
print('对一维向量转置的方式是增加维度\n',A[np.newaxis,:])
print('对一维向量转置的方式是增加维度\n',A[:, np.newaxis])

print('纵向合并A的转置和B的转置\n', np.hstack((A[:,np.newaxis], B[:,np.newaxis])))

print('多个array合并\n',np.concatenate((A,A,B,B),axis=0))
