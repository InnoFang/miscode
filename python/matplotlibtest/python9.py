"""
9.bar 柱状图
"""

import matplotlib.pyplot as plt
import numpy as np

n = 12
X = np.arange(n)
#产生ｎ个从0.5到1.0的数
Y1 = (1 - X/float(n))*np.random.uniform(0.5, 1.0, n)
Y2 = (1 - X/float(n))*np.random.uniform(0.5, 1.0, n)

plt.bar(X,+Y1, facecolor='#9999ff', edgecolor='white')
plt.bar(X,-Y2, facecolor='#ff9999', edgecolor='white')

# zip 把Ｘ，Y1联合起来，每次遍历同时获取
for x,y in zip(X, Y1):
    # ha: horizontal aligment 水平对其方式,va:vertical aligment垂直对其方式
    plt.text(x + 0.4, y + 0.05, '%.2f' % y, ha='center', va='bottom')


for x,y in zip(X, Y2):
    plt.text(x + 0.4, -y - 0.05, '-%.2f' % y, ha='center', va='top')

    
plt.xlim(-5, n)
plt.xticks(())
plt.ylim(-1.25, 1.25)
plt.yticks(())

plt.show()

