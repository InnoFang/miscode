(ns interactionWithJava
  (:import (java.util Calendar GregorianCalendar)
           (javax.swing JFrame JLabel)))

(import
  '(java.util Calendar GregorianCalendar)
  '(javax.swing JFrame JLabel))


(println (. Calendar APRIL))                                ; get Calendar's APRIL => 3
(println Calendar/APRIL)                                    ; get Calendar's APRIL => 3

(println (. Math pow 2 3))                                  ; use Math.pow 2^3 = 8
(println (Math/pow 2 3))                                    ; use Math.pow 2^3 = 8


; new an object of GregorianCalendar
(def calendar (new GregorianCalendar 2018 Calendar/JANUARY 29)) ;JAN 29 2018
(def calendar (GregorianCalendar. 2018 Calendar/JANUARY 29)) ;JAN 29 2018

; call java method
(. calendar add Calendar/MONTH 1)
(println (. calendar get Calendar/MONTH))

(.add calendar Calendar/MONTH 1)
(println (.get calendar Calendar/MONTH))

(println (. (. calendar getTimeZone) getDisplayName))       ;long way
(println (.. calendar getTimeZone getDisplayName))          ;short way


;; `doto` can be used to call multiple methods on an object
(doto calendar
  (.set Calendar/YEAR 2018)
  (.set Calendar/MONTH Calendar/FEBRUARY)
  (.set Calendar/DATE 1))
(def formatter (java.text.DateFormat/getDateInstance))
(println (.format formatter (.getTime calendar)))


;; memfn
(println (map #(.substring %1 %2)
              ["Moe" "Larry" "Curly"] [1, 2, 3]))           ;(oe rry ly)

;当用 memfn 来调用java里面那些需要参数的方法的时候， **你必须给每个参数指定一个名字，以让clojure知道你要调用的方法需要几个参数**。
; 这些名字到底是什么不重要，但是它们必须要是唯一的， 因为要用这些名字来生成Clojure代码的
(println (map (memfn substring beginIndex)
              ["Moe" "Larry" "Curly"] [1, 2, 3]))           ;(oe rry ly)



;; Thread
; All of methods in Clojure are implemented `java.lang.Runnable` interface and `java.util.concurrent.Callable` interface
; That's make it very easy to use functions inside Clojure with threads inside Java

(defn delayed-print [ms text]
  (Thread/sleep ms)
  (println text))

; Pass an anonymous function that invokes delayed-print
; to the Thread constructor so the delayed-print function
; executes inside the Thread instead of
; while the Thread object is being created.
(.start (Thread. #(delayed-print 1000 ", world")))          ;prints 2nd
(print "Hello")
; output is "Hello, World!"


(println "\n------Divider Line------")

;; Exception handling
(defn collection? [obj]
  "is the instance of `coll` in Clojure or `Collection` in Java"
  (println "obj is a " (class obj))
  ; Clojure collections implement clojure.lang.IPersistentCollection.
  (or (coll? obj)                                           ; Clojure collection?
      (instance? java.util.Collection obj)))


(defn average [coll]
  (when-not (collection? coll)
    (throw (IllegalArgumentException. "excepted a collection")))
  (when (empty? coll)
    (throw (IllegalArgumentException. "collection is empty")))
  ; Apply the + function to all the items in coll,
  ; then divide by the number of items in it.
  (let [sum (apply + coll)]
    (/ sum (count coll))))

(try
  (println "list average = " (average '(2 3)))              ;result is a clojure.lang.Ratio Object
  (println "vector average = " (average [2 3]))             ;same
  (println "set average = " (average #{2 3}))               ;same
  (let [al (java.util.ArrayList.)]
    (doto al (.add 2) (.add 3))
    (println "ArrayList average = " (average al)))          ;same
  (println "string average = " (average "1 2 3 4"))         ;illegal argument
  (catch IllegalArgumentException e
    (println e)
    ; (.printStackTrace e)   ;if a stack trace is desired.
    )
  (finally
    (println "in finally")))