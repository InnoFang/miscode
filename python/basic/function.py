# function test

# test 1
def println ( str ) :
	print ( str )
	return 

println ( "Hello World" )


# test 2
def printStu ( name, age ):
	print ("%s, %d" % (name, age))
	return

printStu (age = 19, name = "Inno")


# test 3
def printInfo ( who, sex = 'male' ):
     print ("%s/%s" % (who, sex))
     return

printInfo ("Inno") 


# test 4
def countSum ( *var_arg ):
	sum = 0
	for i in var_arg:
		sum += i
	else:
		print ( sum )
	return

countSum ( 1, 2, 3 )
countSum ( 10, 20, 30, 40, 50 )

# Lambda test

sum = lambda arg1, arg2: arg1 + arg2

print ("1 + 2 = ", sum(1, 2))
print ("10 + 20 = ", sum(10, 20))