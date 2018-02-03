(ns iteration)


;宏 dotimes 会执行给定的表达式一定次数, 一个本地binding会被给定值：从0到一个给定的数值.
; 如果这个本地binding是不需要的 (下面例子里面的 card-number ), 可以用下划线来代替，
(dotimes [card-number 3]
  ; 为了使输出的值从 1 到 3 ，而不是从 0 到 2
  (println "deal card numebr" (inc card-number)))


;宏 while 会一直执行一个表达式只要指定的条件为true. 下面例子里面的 while 会一直执行，只要这个线程没有停:
(defn my-fun [ms]
  (println "entered my-fun")
  (Thread/sleep ms)
  (println "leaving my-fun"))

(let [thread (Thread. #(my-fun 1))]
  (.start thread)
  (println "started thread")
  (while (.isAlive thread)
    (print ".")
    (flush))
  (println "thread stopped"))