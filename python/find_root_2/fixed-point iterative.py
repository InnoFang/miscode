# coding:utf-8
"""
fixed-point iterative ： 定点迭代法
"""

import numpy as np
import matplotlib.pyplot as plt


# f(x) = √(2x)
def f(x):
    y = np.sqrt(2) * np.sqrt(x)
    return y


def iterative(x):
    find = []
    times = 1
    limit = 1000

    while times != limit:
        find.append(x)
        x1 = f(x)

        # 当误差小于 10^(-6) 次方时，视为根
        if np.abs(x - x1) < 1e-6:
            find.append(x1)
            break
        times += 1
        x = x1

    if times == limit:
        print('失败，找不到根')

    return find


def plot(x_list):
    xs = np.arange(0, 4, 0.1)
    ys1 = xs
    ys2 = f(xs)

    x = np.array(x_list)
    y1 = x
    y2 = f(x)

    plt.plot(xs, ys1, label=' ')
    plt.plot(xs, ys2, label='y=sqrt(2x)')

    ax = plt.gca()
    ax.spines['right'].set_color('none')
    ax.spines['top'].set_color('none')
    ax.spines['bottom'].set_position(('data', 0))
    ax.spines['left'].set_position(('data', 0))

    # 找到每个估计点的 x 值
    plt.scatter(x, np.zeros_like(x), c='b')

    for i, x0 in enumerate(x):
        plt.plot([x0, y1[i]], [x0, y2[i]])
        if i != len(x) - 1:  # 防止越界
            plt.plot([x0, y2[i]], [x[i + 1], y1[i + 1]])

    text = 'fixed-point iterative \np' + str(len(x_list)) + ' = ' + str(x[-1])
    plt.text(3, 1, text)
    plt.legend(loc='best')
    plt.show()


plot(iterative(0.01))
