"""
6.annotation 注解
"""

import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(-3, 3, 50)
y = 2 * x + 1

plt.figure(num=1, figsize=(8,5))
plt.plot(x, y)

ax = plt.gca()
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')
ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')
ax.spines['bottom'].set_position(('data',0))
ax.spines['left'].set_position(('data', 0))

x0 = 1
y0 = 2 * x0 + 1
# 画一个点,s表示size大小，color表示颜色
plt.scatter(x0, y0,s=50, color='b')

# 画一条黑色虚线 k:表示black黑色,--表示虚线,前面两个元组，第一个表示两个点的ｘ坐标，后一个表示两个点的ｙ坐标
plt.plot([x0, x0], [y0,0], 'k--', lw=2.5)


# 标注
# xy= 表示标注点的坐标
# xycoords=　表示点坐标 data　表示在数据上
# xytext=　表示文本坐标，如果后面　textcoords 设置为offset points　则xytext可以设置为相对于xy 的偏移地址
# textcoords= 文本坐标
# fontsize=　表示字体大小
# arrowprops= 表示箭头样式，传入一个字典，arrowstyle表示字体样式，connectionstyle表示连接样式，arc3 表示弧度3,rad=.2 表示角度0.2 
plt.annotate(r'$2x+1=%s$' % y0, xy=(x0,y0), xycoords='data', xytext=(+30,-30), textcoords='offset points',
            fontsize=16, arrowprops=dict(arrowstyle='->', connectionstyle='arc3,rad=.2'))

# 设置文本标志
# 前面两个参数分别是文本开始的ｘ、ｙ坐标
# 第三个参数是文本,对特殊字符处理需要转义，若要处理则需统一处理，空格也需要转义并且前后要加上'$'符号
# 第四个参数是字体样式，传入一个字典，包含字体大小，颜色
plt.text(-3.7, 3, r'$This\ is\ the\ some\ text.\ \mu\ \sigma_i\ \alpha_t$',fontdict={'size':16,'color':'r'})
plt.show()
