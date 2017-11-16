import numpy as np
import matplotlib.pyplot as plt

Denominator = []
Molecule = []


def getDenominator(x):
    for i in x:
        num = 1
        for j in x:
            if i != j:
                num = num * (i - j)

        Denominator.append(num)


def getMolecule(x, y):
    for i in x:
        num = 1
        for j in x:
            if i != j:
                num = num * (y - j)

        Molecule.append(num)


def getResult(fx):
    results = 0
    for i in range(len(Denominator)):
        results += Molecule[i] / Denominator[i] * fx[i]
    return results


Lx = np.linspace(0, 10, 100)
nums = [1, 4, 6]
fx = [0, 1.3863, 1.7918]

getDenominator(nums)
getMolecule(nums, 2)

print('result', getResult(fx))
Ly = []
for i in Lx:
    Molecule = []
    getMolecule(nums, i)
    a = getResult(fx)
    print(i, a)
    Ly.append(a)
print(Ly)

fig = plt.figure()
ax1 = fig.add_subplot(1, 1, 1, xlim=(-1, 10), ylim=(-1.08, 1.9))

ax1.xaxis.set_ticks_position('bottom')
ax1.spines['bottom'].set_position(('data', 0))
ax1.yaxis.set_ticks_position('left')
ax1.spines['left'].set_position(('data', 0))
ax1.plot(Lx, Ly, label="$f(x)$", color="red", linewidth=2.5)

ax1.legend()

plt.xlabel("x")  # X轴标签
plt.ylabel("f(x)")  # Y轴标签

plt.show()
