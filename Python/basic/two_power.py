def fun(tp, i):
	print ('power.put(%d, \"2(%d)\");' % (tp, i))

if __name__ == "__main__":
	list = [2**x for x in range(16)]
	for i, tp in enumerate(list):
		fun(tp, i)