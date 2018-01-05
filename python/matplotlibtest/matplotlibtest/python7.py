"""
7. axis tick 坐标轴刻度
"""
import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(-3, 3, 50)
y = 0.1 * x

plt.figure()
plt.plot(x, y, linewidth=10)
plt.ylim(-2,2)
ax = plt.gca()
ax.spines['top'].set_color('none')
ax.spines['right'].set_color('none')
ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')
ax.spines['bottom'].set_position(('data', 0))
ax.spines['left'].set_position(('data', 0))

for label in ax.get_xticklabels() + ax.get_yticklabels():
    #　设置坐标字体
    label.set_fontsize(12)
    # 设置background，即坐标值所在的那个边框
    # facecolor 边框前面的颜色
    # edgecolor 边框颜色，none 为不显示（默认黑色）
    # alpha 透明度
    label.set_bbox(dict(facecolor='white', edgecolor='None', alpha=0.7))

plt.show()
