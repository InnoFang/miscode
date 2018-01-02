"""
2.3 numpy 基础运算
"""

import numpy as np

a = np.array([10,20,30,40])
b = np.arange(4)

print('矩阵a\n',a,'\n矩阵b\n',b)

# 减法
c = a - b
print('矩阵相减:a-b\n',c)

# 加法
c = a + b
print('矩阵相加:a+b\n',c)

# 乘方
c = b ** 2
print('对矩阵b每个元素求平方\n',c)

# sin
c = 10 * np.sin(a)
print('对矩阵a的每个元素求sin并乘以10\n',c)


# cos
c = 10 * np.cos(a)
print('对矩阵a的每个元素求cos并乘以10\n',c)

# 输出小于3的列表
print('矩阵b\n',b)
print('矩阵b中元素小于3的情况\n',b<3)
print('矩阵b中元素等于3的情况\n',b==3) # 等于3的情况


"""
矩阵运算
"""
a = np.array([[1,1],[0,1]])
b = np.arange(4).reshape((2,2))

print('矩阵a\n',a)
print('矩阵b\n',b)

# 元素逐个相乘
c = a*b
print('矩阵元素对应位置逐个相乘\n',c)

# 矩阵相乘
c = np.dot(a,b)
print('矩阵相乘\n',c)

c = a.dot(b)
print('矩阵相乘\n',c)


"""
生成随机矩阵
"""
a = np.random.random((2,4))
print('随机矩阵',a)

# 输出随机数组的和
print('随机矩阵的和',np.sum(a))
# 输出随机数组的最小值
print('随机矩阵的最小值',np.min(a))
# 输出随机数组的最大值
print('随机矩阵的最大值',np.max(a))

print('对随机矩阵的每列求和',np.sum(a,axis=1))
print('对随机矩阵的每行求最小值',np.min(a,axis=0))
print('对随机矩阵的每行求最大值',np.max(a,axis=1))


