# coding:utf8
import sympy as sy
import numpy as np
from sympy.functions import sin, cos
import matplotlib.pyplot as plt

plt.style.use("ggplot")

# 定义变量和函数
x = sy.Symbol('x')
f = (-0.1 * x ** 4) + (-0.15 * x ** 3) + (-0.5 * x ** 2) + (-0.25 * x) + 1.2


# 求阶乘
def factorial(n):
    if n <= 0:
        return 1
    else:
        return n * factorial(n - 1)


# 在 x0 处的泰勒近似
def taylor(function, x0, n):
    i = 0
    p = 0
    while i <= n:
        p = p + (function.diff(x, i) / factorial(i)) * (x - x0) ** i
        i += 1
    return p


# 可视化
def plot():
    x_lims = [-5, 5]
    x1 = np.linspace(x_lims[0], x_lims[1], 800)
    y1 = []

    for j in range(0, 5, 1):
        func = taylor(f, 0, j)
        print('%s阶泰勒展开式：%s' % (str(j), func))
        for k in x1:
            y1.append(func.subs(x, k))
        plt.plot(x1, y1, label='order' + str(j))
        y1 = []

    plt.xlim([-5, 5])
    plt.xlabel('x')
    plt.ylabel('y')
    plt.legend()
    # plt.grid(True)
    plt.title('Taylor Series Approximation')
    plt.show()


plot()
