import random
num = int((random.random() * 100) + 1)
guess = -1
chance = 5
while guess != num and chance != 0:
	guess = int(input("please input:"))
	
	if guess == num:
		print ("Bingo~")
	else:
		if guess > num:
			print ("Bigger than answer, please lower ...", end=',')
		elif guess < num:
			print ("Lower than answer, please bigger ...", end=',')
		chance -= 1
		print ("(%d chance left)\n" % (chance))

print ("Game Over. You lose.")