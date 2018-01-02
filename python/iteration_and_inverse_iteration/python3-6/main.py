# example 1
from random import randint

chinese = [randint(60, 100) for _ in range(40)]
math = [randint(60, 100) for _ in range(40)]
english = [randint(60, 100) for _ in range(40)]

total = []
for c, m, e in zip(chinese, math, english):
    total.append(c + m + e)

print(total)

# example 2
from itertools import chain

for x in chain([1, 2, 3, 4], ['a', 'b', 'c', 'd']):
    print(x)

c1 = [randint(60, 100) for _ in range(40)]
c2 = [randint(60, 100) for _ in range(40)]
c3 = [randint(60, 100) for _ in range(40)]
c4 = [randint(60, 100) for _ in range(40)]

counter = 0
for s in chain(c1, c2, c3, c4):
    if s > 90:
        counter += 1

print(counter)