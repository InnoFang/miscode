# Iterators test

list =  list(range(101))

# test 1
print ('\n--- test1 ---')
it = iter(list)
for x in it:
	# print (next(it)) # wrang
	print (x, end=' ')

# test2
print ('\n\n--- test2 ---')
import sys

it = iter(list)
while True:
	try:
		print (next(it), end=' ')
	except StopIteration:
		sys.exit()