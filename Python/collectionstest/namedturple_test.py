from collections import namedtuple

# class User:
#     def __init__(self, name, age):
#         self.name = name
#         self.age = age


# user = User("Inno", 20)
# print(user.name, user.age)


User = namedtuple("User", ["name", "age", "height", "degree"])
user = User(name="inno", age=20, height=175, degree="bachelor")
print(user)
user_tuple = ("inno", 20, 175)
user1 = User(*user_tuple, "bachelor")
print(user1)

user_tuple = ("inno", 20, 175, "bachelor")
user_list = ["inno", 20, 175, "bachelor"]

user2 = User._make(user_tuple)
print(user2)
user2 = User._make(user_list)
print(user2)
