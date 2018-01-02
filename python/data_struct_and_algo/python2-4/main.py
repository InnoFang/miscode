from random import randint

stu = {x: randint(60, 100) for x in 'xyzabc'}

print(stu)

# solution 1
z = zip(stu.values(), stu.keys())
print(sorted(z))


# solution 2
print(sorted(stu.items(), key=lambda x: x[1]))







