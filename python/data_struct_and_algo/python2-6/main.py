d = {}

d['Jim'] = (1, 35)
d['Leo'] = (2, 37)
d['Bob'] = (3, 40)

print("disordered:")
for k in d:
    print(k)

from collections import OrderedDict

d = OrderedDict()
d['Jim'] = (1, 35)
d['Leo'] = (2, 37)
d['Bob'] = (3, 40)

print("\n\nOrdered")
for k in d:
    print(k)

from random import randint
from time import time

players = list('ABCDEFGH')
start = time()

d = OrderedDict()

for i in range(8):
    input()
    end = time()
    p = players.pop(randint(0, 7 - i))
    print(i + 1, p, end - start)
    d[p] = (i + 1, end - start)

print()
print('-'*20)

for k in d:
    print(k, d[k])