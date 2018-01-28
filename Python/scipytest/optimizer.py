from scipy.optimize import minimize
import numpy as np


def rosen(x):
    """
    The Rosenbrock function
    ------------------------------------
    N-1
    ∑ 100(Xi - Xi-1^2)^2 + (1 - Xi-1)^2
    i=1
    :param x: 
    :return: 
    """
    return sum(100.0 * (x[1:] - x[:-1] ** 2.0) ** 2.0 + (1 - x[:-1]) ** 2.0)


x0 = np.array([1.3, 0.7, 0.8, 1.9, 1.2])
res = minimize(rosen, x0, method="nelder-mead", options={'xtol': 1e-8, 'disp': True})
print(res.x)
