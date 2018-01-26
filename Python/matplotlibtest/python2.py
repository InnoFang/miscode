"""
2. figure 图像
"""
import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(-3, 3, 50)

y1 = 2 * x + 1
y2 = x ** 2

plt.figure()
plt.plot(x,y1)

# 设置 figure 序号为 3, 边框大小为(8,5)
plt.figure(num=3, figsize=(8,5))
# 把两条曲线画到一个 figure 中
plt.plot(x, y2)
# 设置线的颜色color=, 线的宽度 linewidth=, 线的样式 linestyle=
plt.plot(x, y1, color='red', linewidth=1.0, linestyle='--')
plt.show()
