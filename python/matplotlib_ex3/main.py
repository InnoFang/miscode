import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(-3, 3, 50)
y1 = 2 * x + 1
y2 = x ** 2

# plt.figure()
# plt.plot(x, y1)

plt.figure(num=3, figsize=(8, 5))
# plt.plot(x, y2)
# plt.plot(x, y1, color='red', linewidth=1.0, linestyle='--')

# 设置 x 和 y 轴的取值范围
plt.xlim((-1, 2))
plt.ylim((-5, 5))

# 描述 x 轴
plt.xlabel('I am x')
plt.ylabel('I am y')

# 更换 x 轴的 ticks
new_ticks = np.linspace(-2, 3, 5)
print(new_ticks)
plt.xticks(new_ticks)

# 更换 y 轴的 ticks
plt.yticks([-2, -1.8, -1, 1.22, 3],
           ['$really\ bad$', r'$bad\ \alpha$', 'normal', 'good', 'really good'])

## 更改坐标轴位置
# gca = 'get current axis'
ax = plt.gca()
# 去掉 右边和上边 脊梁的颜色
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')
# 分别拿 下面和左边 的脊梁代替 x 和 y 轴
ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')
# 挪动 x 轴的位置到 y 轴的 0 的位置
ax.spines['bottom'].set_position(('data', 0))
# 挪动 y 轴的位置到 x 轴的 0 的位置
ax.spines['left'].set_position(('data', 0))

l1 = plt.plot(x, y2, label='up')
l2 = plt.plot(x, y1, color='red', linewidth=1.0, linestyle='--', label='down')
# 图例
plt.legend()
# plt.legend(handles=[l1, l2, ], labels=['aaa', 'bbb', ], loc='best')


# 添加标注

x0 = 1
y0 = 2 * x0 + 1
plt.scatter(x0, y0, s=50, color='b')  # s: size, color='b':b=blue

plt.show()
