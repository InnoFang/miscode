# Outputs 100 to 1000 prime numbers
import math
for i in range(2, 100):
	for j in range(2, int(math.sqrt(i)) + 1):
		if ( i % j == 0 ):
			break
	else:
		print (i, end=',')