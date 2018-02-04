(ns recursive)


; loop / recur 组合把一个看似递归的调用变成一个迭代 — 迭代不需要占用栈空间
; oop special form 跟 let special form 类似的地方是它们都会建立一个本地binding，
; 但是同时它也建立一个递归点， 而这个递归点就是recur的参数里面的那个函数
; 给recur传递的参数一定要和loop所创建的binding的个数一样
; recur只能出现在loop这个special form的最后一行
(defn factorial-1 [number]
  "computes teh factorial of a positive integer
  in a way that doesn't consume stack space"
  (loop [n number
         factorial 1]
    (if (zero? n)
      factorial
      (recur (dec n) (* factorial n)))))

(println (time (factorial-1 5)))
; "Elapsed time: 0.094815 msecs"
; 120


; use reduce to compute factorial
(defn factorial-2 [number]
  (reduce * (range 2 (inc number))))

(println (time (factorial-2 5)))
; "Elapsed time: 0.123654 msecs"
; 120