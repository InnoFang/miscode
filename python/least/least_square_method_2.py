# coding: utf-8
"""
最小二乘法:多项式
"""
import matplotlib.pyplot as plt
import numpy as np

"""
拟合曲线方程
"""


def func(x, a0, a1, a2):
    y = a0 + a1 * x + a2 * x ** 2
    return y


"""
克莱默法则，求解
"""


def least_square_method(xi, yi):
    x = np.matrix([[len(xi), sum(xi), sum(xi ** 2)],
                   [sum(xi), sum(xi ** 2), sum(xi ** 3)],
                   [sum(xi ** 2), sum(xi ** 3), sum(xi ** 4)]])
    y = np.matrix([sum(yi), sum(yi * xi), sum(yi * xi ** 2)])

    return np.array(y * x.I)


"""
绘图
"""


def plot(x, y, a0, a1, a2):
    plt.scatter(x, y)  # 画样本点
    f = func(x, a0, a1, a2)
    plt.plot(x, f, linewidth=2, linestyle='--', color="red")  # 画拟合直线
    plt.show()


Xi = np.array([0, 1, 2, 3, 4, 5])
Yi = np.array([2.1, 7.7, 13.6, 27.2, 40.9, 61.1])
a = least_square_method(Xi, Yi)
plot(Xi, Yi, a[0][0], a[0][1], a[0][2])
