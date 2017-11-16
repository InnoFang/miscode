如何去掉字符串中不需要的字符？
1.过滤掉用户输入中前后多余的空白字符：
'   nick2008@gmail.com'

2.过滤掉windows下编辑文本周彦宏的'\r':
'hello world\r\n'

3.去掉文本中的Unicode组合符号(音调):
u'ni hao, chi fan'

Solution:
方法一:字符串strip(),lstrip(), rstrip()方法去掉字符串两端字符.
方法二:删除单个固定位置的字符,可以使用切片+拼接的方式
方法三:字符串的replace()方法或正则表达式re.sub()删除任意位置字符.
方法四:字符串translate()方法,可以同时删除多种不同字符