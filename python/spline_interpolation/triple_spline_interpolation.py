#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
三次样条插值
'''

import matplotlib.pyplot as plt
import numpy as np
from sympy import *


# 样本点
def sample():
    global Xi, Yi, a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3
    Xi = np.array([3, 4.5, 7, 9])
    Yi = np.array([2.5, 1, 2.5, 0.5])
    List = []
    a1 = Symbol('a1')
    b1 = Symbol('b1')
    c1 = Symbol('c1')
    d1 = Symbol('d1')
    a2 = Symbol('a2')
    b2 = Symbol('b2')
    c2 = Symbol('c2')
    d2 = Symbol('d2')
    a3 = Symbol('a3')
    b3 = Symbol('b3')
    c3 = Symbol('c3')
    d3 = Symbol('d3')
    List = [a1 * Xi[1] ** 3 + b1 * Xi[1] ** 2 + c1 * Xi[1] + d1 - 1,
            a2 * Xi[1] ** 3 + b2 * Xi[1] ** 2 + c2 * Xi[1] + d2 - 1,
            a2 * Xi[2] ** 3 + b2 * Xi[2] ** 2 + c2 * Xi[2] + d2 - 2.5,
            a3 * Xi[2] ** 3 + b3 * Xi[2] ** 2 + c3 * Xi[2] + d3 - 2.5,
            a1 * Xi[0] ** 3 + b1 * Xi[0] ** 2 + c1 * Xi[0] + d1 - 2.5,
            a3 * Xi[3] ** 3 + b3 * Xi[3] ** 2 + c3 * Xi[3] + d3 - 0.5,
            3 * a1 * Xi[1] ** 2 + 2 * b1 * Xi[1] + c1 - 3 * a2 * Xi[2] ** 2 + 2 * b2 * Xi[2] + c2,
            3 * a2 * Xi[2] ** 2 + 2 * b2 * Xi[2] + c2 - 3 * a3 * Xi[3] ** 2 + 2 * b3 * Xi[3] + c3,
            6 * a1 * Xi[1] + 2 * b1 - 6 * a2 * Xi[2] + 2 * b2,
            6 * a2 * Xi[2] + 2 * b2 - 6 * a3 * Xi[3] + 2 * b3,

            6 * Xi[0] * a1 + 2 * b1,
            6 * Xi[3] * a3 - 2 * b3,
            ]
    xs = solve(List, [a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3])
    print(xs)
    a1 = xs.get(a1)
    b1 = xs.get(b1)
    c1 = xs.get(c1)
    d1 = xs.get(d1)
    a2 = xs.get(a2)
    b2 = xs.get(b2)
    c2 = xs.get(c2)
    d2 = xs.get(d2)
    a3 = xs.get(a3)
    b3 = xs.get(b3)
    c3 = xs.get(c3)
    d3 = xs.get(d3)


def tsp(x):
    if Xi[0] <= x <= Xi[1]:
        y = a1 * x ** 3 + b1 * x ** 2 + c1 * x + d1
    if Xi[1] <= x <= Xi[2]:
        y = a2 * x ** 3 + b2 * x ** 2 + c2 * x + d2
    if Xi[2] <= x <= Xi[3]:
        y = a3 * x ** 2 + b3 * x ** 2 + c3 * x + d3

    return y


# 画样本点
def plot():
    plt.figure(figsize=(8, 6))  # 指定图像比例： 8：6
    plt.scatter(Xi, Yi, color="green", label="point", linewidth=2)
    # 画线
    x = np.linspace(Xi[0], Xi[1], 200)
    y = a1 * x ** 3 + b1 * x ** 2 + c1 * x + d1
    plt.plot(x, y, color="red", label="line", linewidth=1)
    x = np.linspace(Xi[1], Xi[2], 200)
    y = a2 * x ** 3 + b2 * x ** 2 + c2 * x + d2
    plt.plot(x, y, color="red", label="line", linewidth=1)
    x = np.linspace(Xi[2], Xi[3], 200)
    y = a3 * x ** 2 + b3 * x ** 2 + c3 * x + d3
    plt.plot(x, y, color="red", label="line", linewidth=1)
    plt.legend()  # 绘制图例
    plt.show()
    print(tsp(5))


if __name__ == '__main__':
    sample()
    plot()
