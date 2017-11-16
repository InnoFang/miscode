# coding: utf-8

"""
最小二乘法:线性
"""

import matplotlib.pyplot as plt
import numpy as np

"""
拟合直线方程
"""


def func(x, a0, a1):
    y = a0 + a1 * x
    return y


"""
克莱默法则，求解
"""


def least_square_method(xi, yi):
    x = np.matrix([[len(xi), sum(xi)],
                   [sum(xi), sum(xi ** 2)]
                   ])
    y = np.matrix([sum(yi), sum(yi * xi)])

    return np.array(y * x.I)


"""
绘图
"""


def plot(x, y, a0, a1):
    plt.scatter(x, y)  # 画样本点
    f = func(Xi, a0, a1)
    plt.plot(x, f, linewidth=2, linestyle='--', color="red")  # 画拟合直线
    plt.show()


Xi = np.array([1, 2, 3, 4, 5, 6, 7])
Yi = np.array([0.5, 2.5, 2, 4, 3.5, 6, 5.5])
a = least_square_method(Xi, Yi)
plot(Xi, Yi, a[0][0], a[0][1])
