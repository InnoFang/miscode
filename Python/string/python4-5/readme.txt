
如何对字符串进行左，右，居中对齐?
某个字典存储了一系列属性值，
{
    "lodDist": 100.0,
    "Smallculr": 0.0,
    "DistCull": 500.0,
    "trilinear": 40,
    "farcip": 477
}

在程序中，我们想以以下工整的格式将其内容输出，如何处理?
Smallcull :0.04
farcip    :477
lodDist   :100.0
DistCull  :500.0
trilinear :40


Solution:
方法一：使用字符串的str.ljust(), str.rjust(), str.center() 进行左，右，居中对齐
方法二：使用format() 方法，传递类似 '<20', '>20' '^20' 参数完成同样任务