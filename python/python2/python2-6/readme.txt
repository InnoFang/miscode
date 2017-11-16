如何让字典保持有序

某编程竞赛系统，对参赛选手编程解题进行计时，选手完成题目后，把该选手解题用时记录到字典中，以便赛后按选手名查询成绩

比赛结束后，需按排名顺序依次打印选手成绩，如何实现？

Solution
使用 collections.OrderedDict
以 OrderedDict 代替内置字典 Dict，依次将选手成绩存入 OrderedDict