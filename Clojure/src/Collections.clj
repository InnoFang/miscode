(ns Collections)

(println (count [20 "hello" true]))                         ;the number of elements in the list, result is 3

(println (reverse [2 4 7]))                                 ;reverse the list, output -> (7 4 2)


(println (map #(+ % 3) [2 4 7]))                            ;#(+ % 3) an anonymous function, and % will be replace
(println (map + [2 4 7] [5 6] [1 2 3 4]))                   ;adds corresponding items -> (8 12)

(println (apply + [2 4 7]))                                 ;


(def stooges ["moe" "Larry" "Curly" "Shemp"])
(println (first stooges))                                   ; -> "Moe"
(println (last stooges))                                    ; -> "Shemp"
(println (second stooges))                                  ; -> "Larry"
(println (nth stooges 2))                                   ; indexes start at 0 -> Curly


(println (next stooges))                                    ; -> ("Larry" "Curly" "Shemp")
(println (butlast stooges))                                 ; -> ("Moe" "Larry" "Curly")
(println (drop-last 2 stooges))                             ; -> ("Moe" "Larry")
(println (filter #(> (count %) 3) stooges))                 ; Get names containing more than three characters. -> ("Larry" "Curly" "Shemp")
(println (nthnext stooges 2))                               ; -> ("Curly" "Shemp")


(println (every? #(instance? String %) stooges))            ; -> true
(println (not-every? #(instance? String %) stooges))        ; -> false
(println (some #(instance? Number %) stooges))              ;Returns the first logical true value of (pred x) for any x in coll, else nil.
(println (not-any? #(instance? Number %) stooges))          ;Returns false if (pred x) is logical true for any x in coll, else true.