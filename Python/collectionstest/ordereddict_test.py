from collections import OrderedDict

user_dict = OrderedDict()
user_dict["a"] = "user1"
user_dict["b"] = "user2"
user_dict["c"] = "user3"
user_dict["d"] = "user4"
user_dict["e"] = "user5"
print(user_dict)

# pop the value of "a"
print('pop the value of "a": ', user_dict.pop("a"))
print(user_dict)

# pop the key-value entry of the last one
print('pop the key-value entry: ', user_dict.popitem())
print(user_dict)

# move "b"'s entry to the end
user_dict.move_to_end("b")
print(user_dict)
