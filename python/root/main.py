# coding:utf8
import sympy as sy
import numpy as np
from sympy.functions import log

# 定义变量和函数
x = sy.Symbol('x')
func = log(x)  # ln(X)


# the method of bisection
def bisection(x1, x2, use):
    fx1 = func.subs(x, x1)
    fx2 = func.subs(x, x2)
    mid = (x1 + x2) / 2
    fxc = func.subs(x, mid)
    if fx1 * fxc < 0:
        bisection(x1, mid, use + 1)
    elif fxc * fx2 < 0:
        bisection(mid, x2, use + 1)
    elif fxc < 1e-6:  # 误差小于 10 的 -6 次方即视为根
        print("the root of ln(x) is : %s, use %d times." % (str(mid), use))


# method of false position
def false_position(x1, x2, use):
    fx1 = func.subs(x, x1)
    fx2 = func.subs(x, x2)
    fp = x2 - (fx2 * (x1 - x2) / (fx1 - fx2))
    fxc = func.subs(x, fp)
    if fx1 * fxc < 0:
        bisection(x1, fp, use + 1)
    elif fxc * fx2 < 0:
        bisection(fp, x2, use + 1)
    elif fxc < 1e-6:  # 误差小于 10 的 -6 次方即视为根
        print("the root of ln(x) is : %s, use %d times." % (str(fp), use))


bisection(0.1, 10, 0)
false_position(0.1, 10, 0)

'''
output:
the root of ln(x) is : 1.0, use 54 times.
the root of ln(x) is : 1.80000000062864*log(10)/(-log(10) - 2.30258509299405) + 1.90000000062864, use 32 times.


1.80000000062864*log(10)/(-log(10) - 2.30258509299405) + 1.90000000062864 = 1.0000000003143206
'''