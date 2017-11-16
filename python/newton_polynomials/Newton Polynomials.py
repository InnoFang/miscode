#  coding: utf-8
"""
Newton
"""

import matplotlib.pyplot as plt
import numpy as np


def newton(x, y):
    b = []
    b.append(y[0])
    d2 = y

    for i in range(1, len(x)):
        d1 = x[i:] - x[:len(x) - i]
        d2 = np.diff(d2, 1)
        d3 = d2 / d1
        d2 = d3
        print(d3)
        b.append(d3[0])

    return b


def fun(x, X, b):
    y = b[0]
    for i in range(1, len(b) - 1):
        s = 1
        for j in range(i):
            s = s * (x - X[j])
        y = y + b[i] * s

    return y


# 绘图
def plot(x, y, b):
    temp_x = np.arange(x[0] - 0.1, x[-1] + 0.1, 0.1)
    temp_y = []
    for i in temp_x:
        temp_y.append(fun(i, x, b))
    plt.scatter(x, y, s=50, color='b')
    plt.plot(temp_x, temp_y, color='r', linewidth=1.0, linestyle='--')
    plt.show()


x = np.array([0.4, 0.55, 0.65, 0.8, 0.9, 1.05])
y = [0.41075, 0.57815, 0.69675, 0.88811, 1.02652, 1.25382]
b = newton(x, y)
plot(x, y, b)
