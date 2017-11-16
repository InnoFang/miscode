#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
二次样条插值
'''

import matplotlib.pyplot as plt
import numpy as np
from sympy import *


# 样本点
def sample():
    global Xi, Yi, a1, b1, c1, a2, b2, c2, a3, b3, c3
    Xi = np.array([3, 4.5, 7, 9])
    Yi = np.array([2.5, 1, 2.5, 0.5])
    n = len(Xi)
    li = []
    a1 = 0
    b1 = Symbol('b1')
    c1 = Symbol('c1')
    a2 = Symbol('a2')
    b2 = Symbol('b2')
    c2 = Symbol('c2')
    a3 = Symbol('a3')
    b3 = Symbol('b3')
    c3 = Symbol('c3')
    li = [Xi[1] ** 2 * a1 + Xi[1] * b1 + c1 - 1,
          Xi[1] ** 2 * a2 + Xi[1] * b2 + c2 - 1,
          Xi[2] ** 2 * a2 + Xi[2] * b2 + c2 - 2.5,
          Xi[2] ** 2 * a3 + Xi[2] * b3 + c3 - 2.5,
          Xi[0] ** 2 * a1 + Xi[0] * b1 + c1 - 2.5,
          Xi[3] ** 2 * a3 + Xi[3] * b3 + c3 - 0.5,
          2 * Xi[1] * a1 + b1 - 2 * Xi[1] * a2 - b2,
          2 * Xi[2] * a2 + b2 - 2 * Xi[2] * a3 - b3]
    xs = solve(li, [b1, c1, a2, b2, c2, a3, b3, c3])
    print(xs)
    b1 = xs.get(b1)
    c1 = xs.get(c1)
    a2 = xs.get(a2)
    b2 = xs.get(b2)
    c2 = xs.get(c2)
    a3 = xs.get(a3)
    b3 = xs.get(b3)
    c3 = xs.get(c3)


def qsi(x):
    if Xi[0] <= x >= x:
        y = a1 * x ** 2 + b1 * x + c1
    if Xi[1] <= x <= Xi[2]:
        y = a2 * x ** 2 + b2 * x + c2
    if Xi[2] <= x <= Xi[3]:
        y = a3 * x ** 2 + b3 * x + c3

    return y


# 画样本点
def plot():
    plt.figure(figsize=(8, 6))  # 指定图像比例： 8：6
    plt.scatter(Xi, Yi, color="green", label="point", linewidth=2)
    # 画线
    x = np.linspace(Xi[0], Xi[1], 200)
    y = a1 * x ** 2 + b1 * x + c1
    plt.plot(x, y, color="red", label="line", linewidth=1)
    x = np.linspace(Xi[1], Xi[2], 200)
    y = a2 * x ** 2 + b2 * x + c2
    plt.plot(x, y, color="red", label="line", linewidth=1)
    x = np.linspace(Xi[2], Xi[3], 200)
    y = a3 * x ** 2 + b3 * x + c3
    plt.plot(x, y, color="red", label="line", linewidth=1)
    plt.legend()  # 绘制图例
    plt.show()
    print(qsi(5))


if __name__ == '__main__':
    sample()
    plot()
