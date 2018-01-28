from collections import deque

# # Only can operate the last element
user_list = ["user1", "user2", "user3"]
user_name = user_list.pop()
print(user_name, user_list)

# BTW, deque is thread safety, but list is non thread safety

# # use deque
user_deque = deque(user_list)
print(user_deque)
user_deque.appendleft("user0")
print(user_deque)
user_deque.append("user3")
print(user_deque)

# use deque shallow copy
user_deque1 = user_deque.copy()
print(id(user_deque), id(user_deque1), "are the same id? ", id(user_deque) == id(user_deque1))

# if you want to use deep copy, you can use 'copy' library
import copy

user_deque2 = copy.deepcopy(user_deque)
#############################################################

# extend content
user_deque.extend(user_deque2)
print(user_deque)

# insert new element
user_deque.insert(3, "new_user")
print(user_deque)

# reverse deque
user_deque.reverse()
print(user_deque)