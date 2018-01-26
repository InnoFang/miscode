# Example 1
from random import randint

data = [randint(0, 20) for _ in range(30)]
print(data)

c = dict.fromkeys(data, 0)

for x in data:
    c[x] += 1

print(c)

# def dict2list(dic: dict):
#     """convert dictionary to list"""
#     keys = dic.keys();
#     values = dic.values()
#     lst = [(key, val) for key, val in zip(keys, values)]
#     return lst
#
# print(sorted(c.items(), key=lambda x: x[0], reverse=False))


from collections import Counter

c2 = Counter(data)
print(c2.most_common(3))


# Example 2


import re
txt = open('communist.txt').read()
#print(txt)

c3 = Counter(re.split('\W+', txt))
print(c3.most_common(10))