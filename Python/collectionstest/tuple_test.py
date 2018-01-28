user_tuple = ("Inno", 20, 'male')
name, age, gender = user_tuple
print(name, age, gender)

name1, *other = user_tuple
print(name1, other)


name_tuple = ("Inno", [20, 'male'])
name_tuple[1].append(175)
print(name_tuple)
