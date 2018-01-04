print ('\n-- Assign multiple variables --')
# Assign multiple variables
counter, miles, name = 100, 1000.0, "runoob"
print (counter)
print (miles)
print (name)

# output variables type
a, b, c, d = 20, 5.5, True, 4 + 3j
print (type(a), type(b), type(c), type(d))

#######################
print ('\n-- type judegement --')

# type judgement
print (isinstance(a, int))

# the differe between type() and isinstance()
class A(object):
	pass

class B(A):
	pass

print (isinstance(A(), A))
print (type(A()) == A)
print (isinstance(B(), B))
print (type(B()) == A)

#######################
print ('\n-- String test --')
# String test
str = 'InnoFang'

print (str)           # output the string
print (str[0])        # output the character in index 0
print (str[1:6])      # output the string from 2 to 6 （ Not include 6 ）
print (str[1:-1])     # output the string from 2 to last one ( Not include the last one )
print (str[1:])       # output the string  from 2 to the end


print (str * 5)       # output string 5 times
print ("Hello" + str) # concatenate strings

#######################
print ('\n-- String test2 --')

# String test2
print ('In\no')		# In and o will be divided, and in two lines respectively
print ('In\\no')	# output In\no
print (r'In\no') 	# output In\no

#######################
print ('\n-- List test --')

# List test
list = [ 'abcd', 123, 3.21, 'Inno', 1.01]
otherlist = [233, 'fang']

print (list)
print (list[0])
print (list[1:3]) 
print (list[2:])
print (otherlist * 3)
print (list + otherlist)

#######################
print ('\n-- Tuple test --')

# Tuple test

tuple = ( 'abcd', 123, 3.21, 'Inno', 1.01 )
othertuple = ( 233, 'fang' )

print (tuple)
print (tuple[0])
print (tuple[1:3]) 
print (tuple[2:])
print (othertuple * 3)
print (tuple + othertuple)

#######################
print ('\n-- Set test --')

# Set test

student = ({'Jacob', 'Inno', 'Mike', 'Tom', 'Amy'})

print (student)
# member test
if ('Inno' in student) :
	print ('Inno is in the student set')
else :
	print ('Inno is not in the student set')

# set can be operations
a = set('abracadabra')
b = set('alacazam')

print(a)
print(a - b)     # a和b的差集
print(a | b)     # a和b的并集
print(a & b)     # a和b的交集
print(a ^ b)     # a和b中不同时存在的元素

#######################
print ('\n-- Dictionary test --')

# Dictionary test

dict = {}
dict['firstname'] = "Inno"
dict[1] = 'Fang'

otherdict = {'fistname': 'Inno', 'lastname': 'Fang', 'age': 19}

print (dict['firstname'])
print (dict[1])
print (otherdict)
print (otherdict.keys())
print (otherdict.values())

# dict([('Runoob', 1), ('Google', 2), ('Taobao', 3)])
# dict( [('firstname', 'Inno'), ('lastname', 'Fang'), ('age', 19)] )
print({x: x**2 for x in (2, 4, 6)})
# dict(Runoob=1, Google=2, Taobao=3)