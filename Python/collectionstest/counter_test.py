from collections import Counter

# count element appear times
users = ["user1", "user2", "user3", "user1", "user2", "user1"]
user_counter = Counter(users)
print(user_counter)

# count char appear times
char_counter = Counter("laksdfopqawinkl;ashdfkajsl;dkfjasl;dkjfasl;dkjf")
print(char_counter)
# top 2 
print(char_counter.most_common(2))


