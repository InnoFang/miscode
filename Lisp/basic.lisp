;gnu clisp 2.49

(print "Hello, Dcoder!")
(print (+ 1 2 3 4 5 6 7 8 9 10))    
(print (/ (- 7 1) (+ 1 2)))
(quote (+ 1 2))
(print '(+ 1 2))
(print (list 'my (+ 2 3) "hello"))
(print ())
(print nil)

;; list operations
(print (cons 'a '(a b c)))
(print (cons 'a 'b))
(print (cons 'a (cons 'b nil)))
(print (car '(a b c d)))
(print (cdr '(a b c d)))
; get the third element in list
(print (car (cdr (cdr '(a b c d)))))

;; Truth
;If return value is true or false, 
;we will call it 'predicate' in common lisp.
;and the name of predicate usually end of 'p'
(print (listp '(a b c)))
(print (null nil))
(print (not nil))
(print (if (listp '(a b c))
	(+ 1 2 3)
	(- 1 2 3)))

;; Functions
;symbol must be quoted, or it will not be used as variable
;list must be quoted, or it will be considered as code
(defun our-third (x)
	(car (cdr (cdr x))))
(print (our-third '(a b c d)))
;is x+y greater than z?
(defun sum-greater (x y z)
	(> (+ x y) z))
(print (sum-greater 2 3 4))


;; Recurison
(defun our-member (obj lst)
	(if (null lst)
		nil
	(if (eql (car lst) obj)
		lst
		(our-member obj (cdr lst)))))

(print (our-member 'b '(a b c)))
(print (our-member 'z '(a b c)))

;; Input and Output
;~A will be replace, ~% a new line
(format t "~A plus ~A equals ~A. ~%" 2 3 (+ 2 3))
; the last line or expression will be return.
(defun askem (string)
	(format t "~A" string)
	(read))
(askem "How old you are?")
