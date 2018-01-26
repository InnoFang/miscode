pl = ["<0112>", "<32>", "<1024x768>", "<60>", "<1>", "<100.0>", "<500.0>"]

# solution 1
s = ''

for p in pl:
    s += p

print(s)

# solution 2
print(''.join(pl))

print(''.join(str(p) for p in pl))
