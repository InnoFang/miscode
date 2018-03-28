import pandas as pd
import numpy as np

s = pd.Series([1, 3, 6, np.nan, 44, 1])
print(s)

dates = pd.date_range('20160101', periods=6)
print(dates)

df = pd.DataFrame(np.random.randn(6, 4), index=dates, columns=['a', 'b', 'c', 'd'])
print(df)

df2 = pd.DataFrame({
    'A': 1.,
    'B': pd.Timestamp('20130102'),
    'C': pd.Series(1, index=list(range(4)), dtype='float32'),
    'D': np.array([3] * 4, dtype='int32'),
    'E': pd.Categorical(["test", "train", "test", "train"]),
    'F': 'foo'})
print(df2)
print(df2.dtypes)       # 每列类型
print(df2.columns)      # 列
print(df2.values)       # 每行数据
print(df2.describe())   # 描述每列的数据情况，如果不是数值类型该列会被省略

print(df2.T)  # 把表转置，列变成行，行变成列

print(df2.sort_index(axis=1, ascending=False))  # 对列倒序排序
print(df2.sort_index(axis=0, ascending=False))  # 对行倒序排序
print(df2.sort_values(by='E'))                  # 对某一列的值进行排序
