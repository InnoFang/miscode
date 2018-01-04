```python
 import numpy as np
 class Perceptron(object):
    """
    eta:    学习率
    n_iter: 权重向量的训练次数
    w_:     神经分叉权重向量
    errors_:用于记录神经元判断出错次数
    """
    def __init__(self, eta=0.01, n_iter=10):
        self.eta = eta
        self.n_iter = n_iter
        pass
    
    def fit(self, X, y):
        """
        输入训练数据，培训神经元，X 输入样本向量，y 对应样本分类
        
        X:shape[n_samples, n_features]
        X:[[1, 2, 3], [4, 5, 6]]
        n_samples: 2     X 中输入的样本量
        n_features: 3    X 中分叉的电信号总共有多少个
        
        y:[1, -1]
        """
        """
        初始化权重向量为 0
        加一是因为前面算法提到的w0，也就是步调函数阈值
        """
        self.w_ = np.zero(1 + X.shape[1])
        self.errors_ = []
        
        for _ in range(self.n_iter):
            errors = 0
            """
            X:[[1, 2, 3], [4, 5, 6]]
            y:[1, -1]
            zip(X, y) = [[1, 2, 3, 1], [4, 5, 6, -1]]
            xi : 1,2,3
            target : 1
            """
            for xi, target in zip(X, y):
                """
                update = η * (y - y')
                """
                update = self.eta * (target - self.predict(xi))
                """
                xi 是一个向量
                update * xi 等价
                [▽W[1] = X[1] * update, ▽W(2) = X[2] * udpate, ▽W(3) = X[3] * udpate]
                """
                self.w_[1:] += update * xi
                self.w_[0] += update
                
                errors += int(udpate != 0.0)
                self.errors_.append(errors)
                pass
            pass
        
        def net_input(self, X):
            """
            z = W0*1 + W1*X1 + ... + Wn*Xn
            """
            return np.dot(X, self.w_[1:] + self.w_[0])
            pass
        
        def predict(self, X):
            return np.where(self.net_input(X) >= 0.0 , 1, -1)
        
        pass
```

---------------------------

```python
file = "F:/iris.data.csv"
import pandas as pd
df = pd.read_csv(file, header=None)
df.head(10)

```

--------------------------

```python

import matplotlib.pyplot as plt
import numpy as np

y = df.loc[0:100, 4].values
y = np.where(y == 'Iris-setosa', -1, 1)

X = df.iloc[0:100, [0, 2]].values

plt.scatter(X[:50, 0], X[:50, 1], color='red', marker='o', label='setosa')
plt.scatter(X[50:100, 0], X[50:100, 1], color='blue', marker='x', label='versicolor')
plt.xlabel('花瓣长度')
plt.ylabel('花茎长度')
plt.legend(loc='upper left')
plt.show()
```


-----------------

```python
ppn = Perceptron(eta=0.1, n_iter=10)
ppn.fit(X,y)
plt.plot(range(1, len(ppn.errors_) + 1), ppn.errors_, marker='o')
plt.xlabel('Epochs')
plt.ylabel('错误分类次数')
plt.show()
```