实现一个可迭代对象的类，它能迭代出给定范围内所有素数：

pn = PrimeNumbers(1, 30):
for k in pn:
    print(k)

输出结果：2 3 5 7 11 13 17 19 23 29


Solution:
将该类的 __iter__ 方法实现成生成器函数，每次 yield 返回一个素数