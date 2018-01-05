"""
3.坐标轴设置
"""
import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(-3, 3, 50)
y1 = 2 * x + 1
y2 = x ** 2

plt.figure()
plt.plot(x,y2)
plt.plot(x, y1, color='red', linewidth=1.0, linestyle='--')

# x 轴取值范围
plt.xlim((-1,2))
# y 轴取值范围
plt.ylim((-2,3))

# x 轴的描述
plt.xlabel('I am x')
# y 轴的描述
plt.ylabel('I am y')

# 更换 x 轴的间距，用 numpy 的 linspace 更改范围并设置给 xtick
new_ticks = np.linspace(-1, 2, 5)
print(new_ticks)
plt.xticks(new_ticks)

# 更换 y 轴的值，把对应位置的值更改为文字，将文字改成斜体 r'$ab$',空格需要转# 义 r'$\ $' , 一些数学符号 比如 alpha ，也可以转义 r'$\alpha$'
plt.yticks([-2, -1.8, -1, 1.22, 3],
            [r'$really\ bad$', r'$bad\ \alpha$', 'normal', r'$good$', 'really good'])

plt.show()
