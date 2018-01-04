import time, functools

def performance(unit):
    def perf_decorator(f):
        @functools.wraps(f)
        def wrapper(*args, **kwargs):
            start = time.time()
            res = f(*args, **kwargs)
            end = time.time()
            t = (start - end) * 1000 if unit == 'ms'else (start - end)
            print 'call %s() in %f %s'%(f.__name__, t, unit)
            return res
        return wrapper
    return perf_decorator

@performance('ms')
def factorial(n):
    return reduce(lambda x, y : x * y, range(1, n + 1))

print factorial(10)
print factorial.__name__
