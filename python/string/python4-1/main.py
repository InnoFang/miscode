# solution 1
def mySplit(s, ds):
    res = [s]
    for d in ds:
        t = []
        map(lambda x: t.extend(x.split(d)), res)
        res = t
    return res


str = 'ab;cd|efg|hi,jkl|mmn\topq;rst,uvw\txyz'

print(mySplit(str, ';|,\t'))

# solution 2
import re

'''
re.split(pattern, string, maxsplit=0, flags=0)
'''
str = 'ab;cd|efg|hi,jkl|mmn\topq;rst,uvw\txyz'
print(re.split(r'[,;\t|]+', str))
