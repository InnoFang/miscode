# solution 1
s = '   abc   123   '

print(s.strip())
print(s.lstrip())
print(s.rstrip())

s = '---abc+++'
print(s.strip('-+'))

# solution 2

s = 'abc:123'
print(s[:3] + s[4:])

# solution 3
s = '\tabc\t123\txyz'
print(s.replace('\t', ''))

s = '\tabc\t123\rxyz\r'
import re

print(re.sub('[\t\r]', '', s))

# solution 4
s = 'abc\refg\n2342\t'
print(s.translate('\r\n\t'))

u = u'ni\u0301 ha\u030co, chi\u0304 fa\u0300n'
print(u)
print(u.translate(dict.fromkeys([0x0301, 0x030c, 0x0304, 0x300])))