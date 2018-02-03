(ns listComprehension)

; 宏 for 和 doseq 可以用来做list comprehension. 它们支持遍历多个集合 (最右边的最快) ，
; 同时还可以用 `:when` 和 `:while` 做一些过滤

;; 下面的例子会打印一个矩阵里面 所有的元素出来。 它们会跳过 “B” 列 并且只输出小于3的那些行
(def cols "ABCD")
(def rows (range 1 4))                                      ; purposely larger than needed to demonstrate :while

; 宏 for 只接受一个表达式 , 它返回一个懒惰集合作为结果
; dorun , 它会强制提取 for 所返回的懒惰集合
(println "for demo")
(dorun
  (for [col cols :when (not= col \B)                        ; 过滤不等于 B 列的列
        row rows :while (< row 3)]                          ; 过滤大于 3 的行数，保留行数小于 3 的行
    (println (str col row))))


; 宏 doseq 接受任意数量的表达式, 以有副作用的方式执行它们, 并且返回 nil
(println "\ndoseq demo")
(doseq [col cols :when (not= col \B)
        row rows :while (< row 3)]
  (println (str col row)))


