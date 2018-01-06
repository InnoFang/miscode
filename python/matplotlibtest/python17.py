"""
17.animation 动画
"""
import matplotlib.pyplot as plt
from matplotlib import pyplot as plt
from matplotlib import animation
import numpy as np

fig,ax = plt.subplots()

x = np.arange(0, 2*np.pi, 0.01)
# 因为返回的是列表，而我们只要第一个元素，所以line后要加一个,
line, = ax.plot(x,np.sin(x))

def animate(i):
    line.set_ydata(np.sin(x+i/100))
    return line,

def init():
    line.set_ydata(np.sin(x))
    return line,

# 第一个参数figure
# 第二个参数动画函数
# 第三个参数帧率
# 第四个参数初始函数
# 第五个参数更新频率
# blit: True 只变化变了的部分，false整张图片全部更新
ani = animation.FuncAnimation(fig=fig, func=animate, frames=100,init_func=init,interval=20, blit=True)

plt.show()
