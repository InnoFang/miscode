import pandas as pd
import numpy as np

dates = pd.date_range('20160101', periods=6)
df = pd.DataFrame(np.arange(24).reshape(6, 4), index=dates, columns=['A', 'B', 'C', 'D'])
print(df)

# 输出某一列值的方式
print(df['A'])
print(df.A)

# 输出从 0 到 3 行的序列
print(df[0:3])
print(df['20160101':'20160103'])

# select by label: loc
print(df.loc['20160102'])
print(df.loc[:, ['A', 'B']])  # 对所有行，筛选 A 和 B 列的数据
print(df.loc['20160102', ['A', 'B']])  # 对某一行，筛选 A 和 B 列的数据

# select by position: iloc
print(df.iloc[3])  # 输出第三行的数据
print(df.iloc[3, 1])  # 输出第三行第一列的数据
print(df.iloc[2:4, 1:3])  # 切片选取数据
print(df.iloc[[1, 3, 4], 1:3])  # 逐步指定选取数据

# mixed selections: ix
print(df.ix[:3, ['A', 'C']]) # 综合筛选，0到3行，第 'A', 'C' 列

# Boolean indexing
print(df[df.A > 8])
