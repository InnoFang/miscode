import numpy as np
from scipy.integrate import quad, dblquad, nquad

# quad 积分
# dblquad 二重积分

# integral for y = e^(-x), x's domain is [0, +∞)
print(quad(lambda x: np.exp(-x), 0, np.inf))

# double integral for z = e^(-x*y) / y^3, x's domain is [0, +∞),
# the range of y is equivalent to the function of x, so use function to express it
print(dblquad(lambda x, y: np.exp(-y * x) / x ** 3, 0, np.inf, lambda x: 1, lambda x: np.inf))


# multiple integral
def f(x, y):
    """
    function, z = x * y
    :param x: 
    :param y: 
    :return: 
    """
    return x * y


def bound_y():
    return [0, 0.5]


def bound_x(y):
    return [0, 1 - 2 * y]


print(nquad(f, [bound_x, bound_y]))
