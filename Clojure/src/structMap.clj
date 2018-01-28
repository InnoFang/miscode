(ns structMap)

;; StructMap is similar to common map, and its function is actually used to simulate the JavaBean in Java

; Here are two ways to create StructMap
(def vehicle-struct (create-struct :make :mode :year :color)) ;long way
(defstruct vehicle-struct :make :mode :year :color)         ;short way

;; `struct` instantiate an object of StructMap, it's equivalent to the 'new` keyword in Java
; the order of argument must be the same as in the order of keywords you define
; the argument can be ignored, if you do it, the value of the corresponding keyword is nil.
(def vehicle (struct vehicle-struct "Toyota" "Prius" 2009))
(println (vehicle :make))


; use `accessor` to get value,
(def make (accessor vehicle-struct :make))
(println (make vehicle))                                    ;faster than (vehicle :make)
(println (vehicle :make))                                   ;same but slower
(println (:make vehicle))                                   ;same but slower