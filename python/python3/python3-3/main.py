def f():
    print('in f(), 1')
    yield 1

    print('in f(), 2')
    yield 2

    print('in f(), 3')
    yield 3

g = f()
print(g.__next__())
print(g.__next__())
print(g.__next__())