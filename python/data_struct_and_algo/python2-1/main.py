from random import randint
import timeit

"""
过滤掉列表中的负数
"""
data = [randint(-10, 10) for _ in range(10)]

print(data)

print(list(filter(lambda x: x >= 0, data)))

#print(data)

print([x for x in data if x >= 0])

#timeit (list(filter(lambda x: x >= 0, data)))
#print(timeit.Timer(lambda x: x >= 0, data).timeit(1))


"""
筛出字典中值高于 90 的项
"""
dic = {x: randint(60, 100) for x in range(1, 21)}
print(dic)

print({k: v for k, v in dic.items() if v > 90})



"""
筛出集合中能被 3 整除的元素
"""
s = set(data)
print(s)

print({x for x in s if x % 3 == 0})