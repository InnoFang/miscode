l = [1, 2, 3, 4, 5]
d = l.copy()

l.reverse()
print(l)

print(d[::-1])

for x in reversed(d):
    print(x)