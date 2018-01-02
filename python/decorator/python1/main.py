def memo(func):
    cache = {}

    def wrap(*args):
        if args not in cache:
            cache[args] = func(*args)
        return cache[args]

    return wrap


@memo
def fibonacci(n):
    """
    斐波那契数列：1，1，2，3，5，8，...
    :param n: 要求第 n 个斐波那契数
    :return: 第 n 个斐波那契数
    """
    if n <= 1:
        return 1
    return fibonacci(n - 1) + fibonacci(n - 2)


print(fibonacci(50))


@memo
def climb(n, steps):
    """
    一个共有 10 个台阶的楼梯，从下面走到上面，一次只能迈 1-3 个台阶，
    并且不能后退，走完这个楼梯共有多少种方法
    :param n: 第 n 个台阶
    :param steps: 可以走的步数
    :return: 第 n 个台阶有多少种走法
    """
    count = 0
    if n == 0:
        count = 1
    elif n > 0:
        for step in steps:
            count += climb(n - step, steps)
    return count


print(climb(10, (1, 2, 3)))
