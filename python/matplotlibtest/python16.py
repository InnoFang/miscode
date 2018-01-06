"""
16.secondary axis 次坐标
"""
import matplotlib.pyplot as plt
import numpy as np

x = np.arange(0, 10, 0.1)
y1 = 0.05 * x**2
y2 = -1*y1

fig,ax1 = plt.subplots()

# ax2 是ax1的颠倒
ax2 = ax1.twinx()

plt.plot(x, y1, 'g-')
plt.plot(x, y2, 'b--')

ax1.set_xlabel('X data')
ax1.set_ylabel('y1', color='g')
ax2.set_ylabel('y2', color='b')
plt.show()
