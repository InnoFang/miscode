from scipy.interpolate import interp1d
import numpy as np
from matplotlib.pyplot import *

x = np.linspace(0, 1, 10)
y = np.sin(2 * np.pi * x)

li = interp1d(x, y, kind="cubic")
x_new = np.linspace(0, 1, 50)
y_new = li(x_new)

figure()
plot(x, y, 'r')
plot(x_new, y_new, 'k')
show()
print(y_new)
