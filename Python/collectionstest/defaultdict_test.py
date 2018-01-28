from collections import defaultdict

user_dict = {}
users = ["user1", "user2", "user3", "user1", "user2", "user1"]
for user in users:
    # if user in user_dict:
    #     user_dict[user] += 1
    # else:
    #     user_dict[user] = 1
    user_dict.setdefault(user, 0)
    user_dict[user] += 1

print(user_dict)

###### use default dict

default_dict = defaultdict(int)

for user in users:
    default_dict[user] += 1

print(default_dict)


### more usage
def gen_default():
    """
    generate default
    :return: 
    """
    return {
        "name": "",
        "nums": 0
    }


default_dict1 = defaultdict(gen_default)
default_dict1["group"]
print(default_dict1)
