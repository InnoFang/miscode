import numpy as np
import matplotlib.pyplot as plt
import random 

# # normal method 
# position = 0
# walk = [position]
# steps = 1000
# for i in range(steps):
#     step = 1 if random.randint(0, 1) else -1
#     position += step
#     walk.append(position)
# x = np.linspace(0, 1000, 1001)
# plt.figure()
# plt.ylim((-15, 15))
# plt.xlim((0, 100))
# plt.title('Random walk with +1/-1 steps')
# plt.plot(x, walk)
# plt.show()

# Use NumPy
nsteps = 1000
draws = np.random.randint(0, 2, size=nsteps)
steps = np.where(draws > 0, 1, -1)
walk = steps.cumsum() # cumulative sum of the steps

print('the minium of steps : ', walk.min())
print('the maxinum of steps : ', walk.max())

x = np.linspace(0, nsteps, nsteps)
plt.xlim((0, 100))
plt.ylim((-15, 15))
plt.title('Random walk with +1/-1 steps')
plt.plot(x, walk)
plt.show()