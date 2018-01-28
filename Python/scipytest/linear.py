from scipy import linalg as lg
import numpy as np

arr = np.array([
    [1, 2],
    [3, 4]
])

# Matrix arr's determinant
print('Det: ', lg.det(arr))
# Matrix arr's inverse
print('Inv: ', lg.inv(arr))

# Solve linear equations
"""
|1,2||x1|_|6 |
|3,4||x2|-|14|

the solution is x1 = 2, x2 = 2
"""
b = np.array([6, 14])
print('Sol: ', lg.solve(arr, b))

# Matrix arr's eigenvalue ['aɪdʒənˌvælju:]
print('Eig: ', lg.eig(arr))

# Matrix LU factorisation
print('LU decomposition')
P, L, U = lg.lu(arr)
print("L:  \n", L)
print("U:  \n", U)
