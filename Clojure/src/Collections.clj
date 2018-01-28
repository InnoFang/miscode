(ns collections)

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



;;;;; Lists ;;;;;
; Here are some different ways to create to the same list:
;(def stooges (list ("Moe" "Larry" "Curly")))
;(def stooges (quote ("Moe" "Larry" "Curly")))
(def stooges '("Moe" "Larry" "Curly"))

(println (some #(= % "Moe") stooges))
(println (some #(= "Moe" %) stooges))
(println (some #(= % "Mark") stooges))
(println (contains? (set stooges) "Moe"))

; conj and cons
(def more-stooges (conj stooges "Shemp"))                   ;(Shemp Moe Larry Curly)
(println more-stooges)
(def more-stooges1 (cons stooges "Shemp"))                  ;((Moe Larry Curly) S h e m p)
(println more-stooges1)

; remove
(def less-stooges (remove #(= % "Curly") more-stooges))
(println less-stooges)

; into
(def kids-of-mike '("greg" "Peter" "Bobby"))
(def kids-of-carol '("Marcia" "Jan" "Cindy"))
(def brady-bunch (into kids-of-carol kids-of-mike))
;(def brady-bunch (into kids-of-mike kids-of-carol))
(println brady-bunch)

; peek and pop, they all operate the first element in list
(println (peek brady-bunch))                                ; get the fist element
(println (pop brady-bunch))                                 ; create a new list without the first element
(println brady-bunch)                                       ; the source list isn't changed


;;;;; Vector ;;;;;

; Here are two ways to create vector
(def stooges (vector "Moe" "Larry" "Curly"))
(def stooges ["Moe" "Larry" "Curly"])

; get and nth
(println (get stooges 1 "unknown"))
(println (nth stooges 1 "unknown"))

; assoc
(println (assoc stooges 2 "Shemp"))                         ;create a new vector and the 2nd will be replace,[Moe Larry Shemp]
(println (assoc stooges 3 "Shemp"))                         ;create a new vector and add a new element in it
; if key greater than the vector's size, it will throw a IndexOutOfBoundsException
;(println (assoc stooges 4 "Shemp"))


; subvec : create a sub-vector
(println (subvec stooges 1))                                ;[Larry Curly]
(println (subvec stooges 0 1))                              ;[Moe]

; conj and cons
(println (conj stooges "Shemp"))                            ;[Moe Larry Curly Shemp]
(println (cons stooges "Shemp"))                            ;([Moe Larry Curly] S h e m p)

; peek and pop
; get the last element
(println (peek stooges))                                    ;Curly
; create a new vector without the last element
(println (pop stooges))                                     ;[Moe Larry]


;; Sets
; Here are some ways to create the new set
(def stooges (hash-set "Moe" "Larry" "Curly"))              ;not sorted
(def stooges #{"Moe" "Larry" "Curly"})                      ;same as previous
(def stooges (sorted-set "Moe" "Larry" "Curry"))

; contains?
(println (contains? stooges "Moe"))                         ;is stooges contains "Moe" => true
(println (contains? stooges "Mark"))                        ;is stooges contains "Mark => false

; Sets can be use as function, if it contain this element, the element will be return, or return nil
(println (stooges "Moe"))                                   ; "Moe"
(println (stooges "Mark"))                                  ; nil
(println (if (stooges "Curly")
           "stooges"
           "regular person"))

; conj and into, they are used for sorted set
(def more-stooges (conj stooges "Shemp"))                   ;#{Curry Larry Moe Shemp}
(println more-stooges)
; disj : create a new set by removing some of the elements inside a given set
(def less-stooges (disj more-stooges "Curry"))              ;#{Larry Moe Shemp}
(println less-stooges)


;; Maps
; here are some ways to create map
(def popsicle-map (hash-map :red :cherry, :yellow :banana, :purple :grape))
(def popsicle-map {:red :cherry, :yellow :banana, :purple :grape}) ;same as previous
; sorted by key ordered, Lexicographic order may be
(def popsicle-map (sorted-map :red :cherry, :yellow :banana, :purple :grape))

; get
(println (get popsicle-map :yellow))                        ;=>banana
(println (popsicle-map :yellow))                            ;=>banana
; if key is keyword, key also can be the function for map
(println (:yellow popsicle-map))                            ;=>banana

; contains? : is map contain the key?
(println (contains? popsicle-map :yellow))                  ;=>true
(println (contains? popsicle-map :green))                   ;=>false

; keys : return all keys of map
(println (keys popsicle-map))                               ;(:purple :red :yellow)
; vals : return all values of map
(println (vals popsicle-map))                               ;(:purple :red :yellow)

;assoc
; create a new map with the new-value pair, if it contain the key, it will update its value
(println (assoc popsicle-map :yellow :pear :blue :blueberry)) ;{:blue :blueberry, :purple :grape, :red :cherry, :yellow :pear}

;dissoc
; create a new map by ignoring keys we given
(println (dissoc popsicle-map :green :blue))                ;{:purple :grape, :red :cherry, :yellow :banana}


; use doseq and destructuring to traverse map
; bind keys to color, bind values to flavor
(doseq [[color flavor] popsicle-map]                        ;The flavor of purple popsicles is grape.
  (println (str "The flavor of " (name color)               ;The flavor of red popsicles is cherry.
                " popsicles is " (name flavor) ".")))       ;The flavor of yellow popsicles is banana.


;select-keys: create a sub-map contains all keys we given in source map
(println (select-keys popsicle-map [:red :yellow]))         ;{:red :cherry, :yellow :banana}

(def person {
             :name     "Mark Volkman"
             :address  {
                        :street "644 Glen Summit"
                        :city   "St. charles"
                        :state  "Missouri"
                        :zip    63304
                        }
             :employer {
                        :name    "Object Computing, Inc"
                        :address {
                                  :street "12140 Woodcrest Executive Drive, Suite 250"
                                  :city   "Creve Coeur"
                                  :state  "Missouri"
                                  :zip    63141
                                  }
                        }
             })

; use get-in, -> ,reduce to get the person's employer's address
(println (get-in person [:employer :address :city]))
; -> is Macro, e.g. (f1 (f2 (f3 x))) => (-> x f3 f2 f1)
(println (-> person :employer :address :city))
; reduce function need two parameter, an optional value (i.e. person) and a collection (i.e. keys)
(println (reduce get person [:employer :address :city]))


; assoc-in : use for modify the value of the embedded key
(println (assoc-in person [:employer :address :city] "Clayton"))
; update-in : use for update the value of the embedded key
; str is a function that will take the old value
(println (update-in person [:employer :address :zip] str "-1234"))