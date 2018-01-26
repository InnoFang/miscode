f = open('communist.txt')
lines = f.readlines()
print(lines[100:300])

f.seek(0)

for line in f:
    print(line)

from itertools import islice

"""
islice(iterable, [start,] stop [, step=1])

[0, 500]
islice(f, 500);


[300, +∞]
islice(f, 100, None)
"""
for line in islice(f, 100, 300):
    print(line)


l = range(20)
t = iter(l)
for x in islice(t, 5, 10):
    print(x)

print('-'*20)
for x in t:
    print(x)

"""
经过上一次迭代，t 已经到了 10 这个位置了，要继续使用切记重新定义 t
"""