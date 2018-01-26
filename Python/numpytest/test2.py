"""
2.2 array的创建
"""

import numpy as np

a = np.array([2,23,4], dtype=np.int)
print(a)

a = np.array([[2,23,4],[2,23,4]])
print(a)

a = np.zeros((3,4))
print(a)

a = np.arange(10,20,2)
print(a)


a = np.arange(12).reshape((3,4))
print(a)

a = np.linspace(1,10,6).reshape((2,3))
print(a)


