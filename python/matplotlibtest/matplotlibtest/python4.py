"""
4. 坐标轴设置2
"""
import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(-3, 3, 50)
y1 = 2 * x + 1
y2 = x ** 2


plt.figure()
plt.plot(x, y2)
plt.plot(x, y1, color='red', linewidth=1.0, linestyle='--')

plt.xlim((-1,2))
plt.ylim((-2,3))
plt.xlabel('I am x')
plt.ylabel('I am y')

new_ticks = np.linspace(-1,2,5)
print(new_ticks)
plt.xticks(new_ticks)
plt.yticks([-2, -1.8, -1, 1.22, 3],
            ['really good', 'bad', 'normal', 'good', 'really good'])

# 更改坐标轴的位置
# gca = 'get current axis'
ax = plt.gca()
# 把上面和右面的边框去掉
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')

# 设置默认 x、y 轴
ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')

# 设置x、y轴的位置
ax.spines['bottom'].set_position(('data', -1))
ax.spines['left'].set_position(('data', 0))
plt.show()
