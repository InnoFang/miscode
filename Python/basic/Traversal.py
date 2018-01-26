
# dictionary
fruit = {'apple': 'red', 'orange': 'orange', 'grape': 'purple'}
for k, v in fruit.items():
	print (k, v)

"""
apple red
orange orange
grape purple
"""


# list
student = ['Jam', 'Tom', 'Amy']
for i, x in enumerate(student):
	print (i, x)

"""
0 Jam
1 Tom
2 Amy
"""


# traversal more than one list
name = ['Jack', 'Mike', 'Inno']
age = [17, 18, 19]
for n, a in zip(name, age):
	print ("My name is {0}, I am {1} years old.".format(n, a))

"""
My name is Jack, I am 17 years old.
My name is Mike, I am 18 years old.
My name is Inno, I am 19 years old.
"""


# reverse traversal
for i in reversed(range(1, 11)):
	print (i, end=" ")

# 10 9 8 7 6 5 4 3 2 1

print ()
# traversal set
basket = ['apple', 'orange', 'apple', 'pear', 'orange', 'banana']
for f in sorted(set(basket)):
	print (f)

"""
apple
banana
orange
pear
"""