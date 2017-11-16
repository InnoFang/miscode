#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'Lagrange Interpolation'

import numpy as np
import matplotlib.pyplot as plt


class Lagrange:
    mo = []  # 保存分子
    de = []  # 保存分母

    def __init__(self):
        pass

    def calcMolecule(self, xv, x):
        for i in xv:
            val = 1
            for j in xv:
                if i != j:
                    val *= (x - j)

            self.mo.append(val)

    def calcDenominator(self, xv):
        for i in xv:
            val = 1
            for j in xv:
                if i != j:
                    val *= (i - j)

            self.de.append(val)

    def lagrange(self, yv):
        res = 0
        for i in range(len(self.de)):
            res += self.mo[i] / self.de[i] * yv[i]
        return res

    def plot(self, xv, yv):
        lx = np.linspace(0, 10, 100)
        self.calcDenominator(xv)
        self.calcMolecule(xv, 2)
        print('result ', self.lagrange(yv))

        ly = []
        for x in lx:
            self.mo = []  # 清空
            self.calcMolecule(xv, x)
            res = self.lagrange(yv)
            print(x, res)
            ly.append(res)

        print(ly)

        fig = plt.figure()
        ax1 = fig.add_subplot(1, 1, 1, xlim=(-1, 10), ylim=(-1.08, 1.9))

        ax1.xaxis.set_ticks_position('bottom')
        ax1.spines['right'].set_color('none')
        ax1.spines['top'].set_color('none')
        ax1.spines['bottom'].set_position(('data', 0))
        ax1.yaxis.set_ticks_position('left')
        ax1.spines['left'].set_position(('data', 0))
        ax1.plot(lx, ly, label="$f(x)$")

        plt.xlabel("x")  # X轴标签
        plt.ylabel("f(x)")  # Y轴标签

        plt.show()


if __name__ == '__main__':
    lagrange = Lagrange()
    xv = [1, 4, 6]
    yv = [0, 1.3863, 1.7918]
    lagrange.plot(xv, yv)
