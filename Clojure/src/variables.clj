(ns variables)

(def ^:dynamic v 1)                                         ; v is a global binding

(defn f1 []
  (println "f1: v = " v))                                   ; global binding

(f1)


(defn f2 []
  (println "f2: before let v = " v)                        ; global binding
  (let [v 2]                                               ; creates local binding v that shadows global one
    (println "f2: in let, v = " v)                         ; local binding
    (f1))
  (println "f2: after let v = " v))                        ; global binding

(f2)

(defn f3 []
  (println "f3: before binding v = " v)                     ;global binding
  (binding [v 3]                                            ;same global binding with new, temporary value
           (println "f3: in binding, v = " v)               ;global binding
           (f1))
  (println "f3: after binding v = " v))                     ;global binding

(f3)

(defn f4 []
  (def v 4))                                                ;changes the value of the global binding

(f4)

(println "after calling f4, v = " v)