"""
5.legend 图例
"""
import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(-3, 3, 50)
y1 = 2 * x + 1
y2 = x ** 2

plt.figure()

plt.xlim((-1,2))
plt.ylim((-2,3))
plt.xlabel('I am x')
plt.ylabel('I am y')

new_ticks = np.linspace(-1, 2, 5)
plt.xticks(new_ticks)
plt.yticks([-2,-1.8,-1,1.22,3],
            ['really bad', 'bad', 'normal', 'good', 'really good'])

# 画 legend
l1, = plt.plot(x, y2, label='up')
l2, = plt.plot(x, y1, label='down', color='red', linewidth=1.0, linestyle='--')

# handles= 需要拿到 plot 返回的对象，比如 plot了一条线，返回值付给 l1,[注意] 规定，'l1,' 这里要加上个 ',' 才可以,否则虽然不会报错，但是不会显示 
# labels= 对拿到的对象，比如 l1,l2, 等取一个别名
# loc= 表示legend 的位置'best‘最佳位置，'upper right'右上, 'lower left'左下 ....
plt.legend(handles=[l1,l2,], labels=['aaa', 'bbb'], loc='best')

plt.show()
