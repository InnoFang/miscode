# coding:utf-8
"""
secant: 正割法
"""

import numpy as np
import matplotlib.pyplot as plt


# f(x) = xe^(x) - 1
def f(x):
    y = x * np.exp(x) - 1
    return y


# f(x)' = e^(x) + xe^(x)
def f1(x):
    y = np.exp(x) + x * np.exp(x)
    return y


"""
               f(X_k)(X_k-1 - X_k)
X_k+1 = X_k -  -------------------
                f(X_k-1) - f(X_k)
"""


def secant(x0, x1):
    find = []
    times = 1
    limit = 1000
    find.append(x0)
    find.append(x1)

    while times != limit:
        x = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0))
        find.append(x)
        # 当误差小于 10^(-6) 次方时，视为根
        if np.abs(x - x1) < 1e-6:
            find.append(x)
            break

        times += 1
        x0 = x1
        x1 = x

    if times == limit:
        print('失败，找不到根')

    return find


def plot(x_list):
    xs = np.arange(0, 1, 0.01)
    ys = f(xs)

    x = np.array(x_list)
    y = f(x)

    plt.plot(xs, ys, label='y=x*e^(x) - 1')

    ax = plt.gca()
    ax.spines['right'].set_color('none')
    ax.spines['top'].set_color('none')
    ax.spines['bottom'].set_position(('data', 0))
    ax.spines['left'].set_position(('data', 0))

    plt.scatter(x, np.zeros_like(x), c='b')

    for i, x0 in enumerate(x):
        plt.plot([x0, x0], [0, y[i]])
        if i + 2 < len(x):
            plt.plot([x0, x[i + 2]], [y[i], 0])

    text = 'secant\np' + str(len(x_list)) + ' = ' + str(x[-1])
    plt.text(0.1, 1, text)
    plt.legend()
    plt.show()


plot(secant(1.1, 1))
