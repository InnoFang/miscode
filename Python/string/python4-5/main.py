s = 'abc'

print(s.ljust(20))
print(s.rjust(20))
print(s.center(20))

print(format(s, '<20'))
print(format(s, '>20'))
print(format(s, '^20'))

d = {
    "lodDist": 100.0,
    "Smallculr": 0.0,
    "DistCull": 500.0,
    "trilinear": 40,
    "farcip": 477
}

# 获取d中的key，对每一个key取得长度，然后得到最大的长度，保存在 w 中
w = max(map(len, d.keys()))

for k in d:
    print(k.ljust(w), ':', d[k])
