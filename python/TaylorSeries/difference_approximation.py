# coding:utf8
import sympy as sy
import numpy as np
from sympy.functions import sin, cos
import matplotlib.pyplot as plt

plt.style.use("ggplot")

# 定义变量和函数
x = sy.Symbol('x')
f = (-0.1 * x ** 4) + (-0.15 * x ** 3) + (-0.5 * x ** 2) + (-0.25 * x) + 1.2
h = 0.5


# 求阶乘
def factorial(n):
    if n <= 0:
        return 1
    else:
        return n * factorial(n - 1)


# 在 xi 处的估计 xi+1
def taylor_forward(function, n):
    i = 0
    p = 0
    while i <= n:
        p = p + (function.diff(x, i) / factorial(i)) * (h ** i)
        i += 1
    return p


# 在 xi 处的估计 xi-1
def taylor_backward(function, n):
    i = 0
    p = 0
    while i <= n:
        if i % 2 == 0:
            p = p + (function.diff(x, i) / factorial(i)) * (h ** i)
        else:
            p = p - (function.diff(x, i) / factorial(i)) * (h ** i)
        i += 1
    return p


def plot():
    x_lims = [-5, 5]
    x1 = np.linspace(x_lims[0], x_lims[1], 800)

    forward = (taylor_forward(f, 1) - f) / h
    print("前向差商逼近:", forward)
    # plt.plot(x1, x1, label='forward')

    backward = (f - taylor_backward(f, 1)) / h
    print("前向差商逼近:", backward)
    # plt.plot(x1, x1, label='backward')

    central = (taylor_forward(f, 1) - taylor_backward(f, 1)) / (2 * h)
    print("中心差商逼近:", central)

    plt.xlim([-5, 5])
    plt.xlabel('x')
    plt.ylabel('y')
    plt.legend()
    # plt.grid(True)
    plt.title('Taylor Series Approximation')
    plt.show()


plot()
