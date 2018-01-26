"""
8. scatter 散点数据
"""
import matplotlib.pyplot as plt
import numpy as np

n = 1024
# 中位数是０，方差是１,一共ｎ个数
X = np.random.normal(0, 1, n)
Y = np.random.normal(0, 1, n)
T = np.arctan2(Y,X) # for color value

plt.scatter(X, Y, s=75, c=T, alpha=0.5)

plt.xlim((-1.5, 1.5))
plt.ylim((-1.5, 1.5))
plt.xticks(())
plt.yticks(())
plt.show()
