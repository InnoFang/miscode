from random import randint
from collections import deque
import pickle

history = deque([], 5)

N = randint(0, 100)


def guess(k):
    if k == N:
        print('right')
        return True
    if k < N:
        print('%s is less-than N' % k)
    else:
        print('%s is greater-than N' % k)
    return False


while True:
    line = input("please input a number:")
    if line.isdigit():
        k = int(line)
        history.append(k)
        if guess(k):
            break
    elif line == 'history' or line == 'h?':
        print(list(history))

# pickle.dump(history, open('history.txt', 'w'))
#
# q2 = pickle.load(open('history.txt'))
# print(p2)