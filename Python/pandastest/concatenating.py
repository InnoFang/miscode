import pandas as pd
import numpy as np

# concatenating
df1 = pd.DataFrame(np.ones((3, 4)) * 0, columns=['a', 'b', 'c', 'd'])
df2 = pd.DataFrame(np.ones((3, 4)) * 1, columns=['a', 'b', 'c', 'd'])
df3 = pd.DataFrame(np.ones((3, 4)) * 2, columns=['a', 'b', 'c', 'd'])
# print(df1, '\n', df2, '\n', df3)

# ignore_index=True 忽略 index 的影响
res = pd.concat([df1, df2, df3], axis=0, ignore_index=True)
print(res)

##############

# join, ['inner', 'outer']
df1 = pd.DataFrame(np.ones((3, 4)) * 0, columns=['a', 'b', 'c', 'd'], index=[1, 2, 3])
df2 = pd.DataFrame(np.ones((3, 4)) * 1, columns=['b', 'c', 'd', 'e'], index=[2, 3, 4])
# print(df1, '\n', df2)

# print(pd.concat([df1, df2])) # 默认的 join 为 outer，没有的数据用 NAN 填充
print(pd.concat([df1, df2]))  # 用 inner 会把没有数据的列裁剪掉，只保留共有列

##############

# join, ['inner', 'outer']
df1 = pd.DataFrame(np.ones((3, 4)) * 0, columns=['a', 'b', 'c', 'd'], index=[1, 2, 3])
df2 = pd.DataFrame(np.ones((3, 4)) * 1, columns=['b', 'c', 'd', 'e'], index=[2, 3, 4])
# print(df1, '\n', df2)
# 左右合并，即行的方向
# res = pd.concat([df1, df2], axis=1)
# 指定 join_axes 指定按照哪个 df 的下标为准
res = pd.concat([df1, df2], axis=1, join_axes=[df1.index])
print(res)

##############

# append

df1 = pd.DataFrame(np.ones((3, 4)) * 0, columns=['a', 'b', 'c', 'd'])
df2 = pd.DataFrame(np.ones((3, 4)) * 1, columns=['a', 'b', 'c', 'd'])
df3 = pd.DataFrame(np.ones((3, 4)) * 1, columns=['b', 'c', 'd', 'e'], index=[2, 3, 4])
# res = df1.append(df2, ignore_index=True)
# res = df1.append([df2, df3])

s1 = pd.Series([1, 2, 3, 4], index=['a', 'b', 'c', 'd'])
# 追加一行数据
res = df1.append(s1, ignore_index=True)
print(res)
