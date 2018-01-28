from collections import ChainMap

user_dict1 = {"a": "user1", "b": "user2"}
user_dict2 = {"c": "user3", "d": "user4"}
for key, value in user_dict1.items():
    print(key, value)

for key, value in user_dict2.items():
    print(key, value)

print("-----------splitter-----------")

# If there are many map, the operation above is too much trouble
# In this case, you can use ChainMap

# use ChainMap to connect two map
new_dict = ChainMap(user_dict1, user_dict2)
for key, value in new_dict.items():
    print(key, value)

print("-----------splitter-----------")

# If there are the same key between two dicts,
# use ChainMap to traversal it, the previous will be outputted, the behind will be ignored.
user_dict3 = {"a": "user1", "b": "user2"}
user_dict4 = {"b": "user3", "d": "user4"}
new_dict1 = ChainMap(user_dict3, user_dict4)
for key, value in new_dict1.items():
    print(key, value)

# dynamic add sub-dict
new_dict1.new_child({"c": "user5"})

print("-----------splitter-----------")
# change map to list
print(new_dict1.maps)
