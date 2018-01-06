"""
15. plot in plot 图中图
"""
import matplotlib.pyplot as plt
import matplotlib.gridspec as girdspec

fig = plt.figure()
x = [1,2,3,4,5,6,7]
y = [1,3,4,2,5,8,6]

# 图中图在坐标中的左、下、宽、高
left, bottom, width, height = 0.1, 0.1, 0.8, 0.8
ax1 = fig.add_axes([left, bottom, width, height])
ax1.plot(x,y, 'r')
ax1.set_xlabel('x')
ax1.set_ylabel('y')
ax1.set_title('title')

# method 1
left, bottom, width, height = 0.2, 0.6, 0.25,0.25
ax2 = fig.add_axes([left, bottom, width, height])
ax2.plot(y,x, 'b')
ax2.set_xlabel('x')
ax2.set_ylabel('y')
ax2.set_title('title inside 1')

# method 2
plt.axes([0.6, 0.2, 0.25, 0.25])
plt.plot(y[::-1], x, 'g')
ax2.set_xlabel('x')
ax2.set_ylabel('y')
ax2.set_title('title inside 2')

plt.show()
