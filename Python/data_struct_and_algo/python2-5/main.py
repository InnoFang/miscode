from random import randint, sample
from functools import reduce # if want to use function reduce in python3, you should do this

player = sample('abcdefg', randint(3, 6))

s1 = {p: randint(1, 4) for p in sample('abcdefg', randint(3, 6))}
print("s1 = ", s1)

s2 = {p: randint(1, 4) for p in sample('abcdefg', randint(3, 6))}
print("s2 = ", s2)

s3 = {p: randint(1, 3) for p in sample('abcdefg', randint(3, 6))}
print("s3 = ", s3)

# solution 1
res = []
for k in s1:
    if k in s2 and k in s3:
        res.append(k)

print(res)


# solution 2
print(s1.keys() & s2.keys() & s3.keys())


# solution 3
print(reduce(lambda a, b: a & b, map(dict.keys, [s1, s2, s3])))