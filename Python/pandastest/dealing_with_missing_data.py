import pandas as pd
import numpy as np

dates = pd.date_range('20160101', periods=6)
df = pd.DataFrame(np.arange(24).reshape((6, 4)), index=dates, columns=['A', 'B', 'C', 'D'])

df.iloc[0, 1] = np.nan
df.iloc[1, 2] = np.nan

print(df)

# df 含有两个丢失数据


# 处理方式1，丢掉含有 nan 的行，any 含有任一个 nan 就抛弃，all 是全部才抛弃
# axis：0 行，1 列
print(df.dropna(axis=0, how='any'))  # how=['any', 'all']

# 处理方式2：填充 nan 的数据
print(df.fillna(value=0))

# 查看是否丢失数据，在丢失数据的位置为True，其他地方为 False
print(df.isnull())
# 如果表太大，不好查看，可以用下面的方式
print(np.any(df.isnull()))
