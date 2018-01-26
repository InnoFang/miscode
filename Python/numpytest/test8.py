"""
2.8  numpy copy & deep copy 
"""

import numpy as np

a = np.arange(4)
print('array a:\n',a)

b = a
c = a
d = b
# 更改a[0]
a[0] = 11
print('更改a[0]的值为11\n',a[0])

print('b is a?\n', b is a)
print('b的值也会改变\n',b)

print('c is a?\n', c is a)
print('d is a?\n', d is a)

# 如果不想关联这些变量，则需要使用深拷贝(deep copy)
b = a.copy()
print('更改b为a的深拷贝,b is a?\n',b is a)
