"""
13. sub plot 多个显示
"""
import matplotlib.pyplot as plt

plt.figure()
#把图分成２行２列，图像显示在第一个位置
plt.subplot(2,1,1)
# 画一条线，前面一个列表是两个点的ｘ坐标，后面一个列表是两个点的ｙ坐标
plt.plot([0,1], [0,1])

plt.subplot(2,3,4)
plt.plot([0,1], [0,2])

plt.subplot(235)
plt.plot([0,1], [0,3])

plt.subplot(236)
plt.plot([0,1], [0,4])
plt.show()
