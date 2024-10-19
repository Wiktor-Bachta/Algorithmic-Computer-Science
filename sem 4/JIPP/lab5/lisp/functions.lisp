; clisp 
; (load "functions.lisp")

(defun binomial (n k)
  (if (or (= k 0) (= k n))
      1
      (+ (binomial (- n 1) k) (binomial (- n 1) (- k 1)))))
    
; -----------------------------------------------------------------


(defun pascal (n)
  (if (= n 0)
        '(1)
        (let ((previous-row (pascal (- n 1))))
        (cons 1 (append (mapcar #'+ previous-row (cdr previous-row)) '(1))))))

(defun binomial2 (n k)
  (nth k (pascal n)))

; -----------------------------------------------------------------

(defun mymerge (left right)
  (cond
    ((null left) right)
    ((null right) left)
    ((<= (first left) (first right))
     (cons (first left) (mymerge (rest left) right)))
    (t
     (cons (first right) (mymerge left (rest right))))))

(defun mergesort (list)
  (if (or (null list) (null (rest list)))
      list
      (let* ((middle (floor (/ (length list) 2)))
             (left (subseq list 0 middle))
             (right (subseq list middle)))
        (mymerge (mergesort left) (mergesort right)))))
    
; -----------------------------------------------------------------

(defun extended-gcd (a b)
  (if (= a 0)
      (values b 0 1)
      (multiple-value-bind (g x y) (extended-gcd (mod b a) a)
        (values g (- y (* (floor b a) x)) x))))

(defun de (a b)
  (multiple-value-bind (g x y) (extended-gcd a b)
    (list x y g)))

; -----------------------------------------------------------------

(defun prime-factors (n)
  (labels ((factorize (n f)
             (cond
               ((= n 1) nil)
               ((= (mod n f) 0) (cons f (factorize (/ n f) f)))
               (t (factorize n (+ f 1))))))
    (factorize n 2)))

; -----------------------------------------------------------------

(defun gcd (a b)
  (if (= b 0) a (gcd b (mod a b))))

(defun totient (n)
  (length (remove-if-not (lambda (x) (= (gcd x n) 1)) (loop for i from 1 to n collect i))))

; -----------------------------------------------------------------

(defun totient2 (n)
  (let ((prime-factors (remove-duplicates (prime-factors n))))
    (floor (* n (reduce #'* (mapcar (lambda (p) (- 1 (/ 1 (float p)))) prime-factors))))))

; -----------------------------------------------------------------

(defun sieve (list)
  (if (null list) nil
      (let ((p (car list)))
        (cons p (sieve (remove-if (lambda (x) (= (mod x p) 0)) (cdr list)))))))

(defun primes (n)
  (sieve (loop for i from 2 to n collect i)))

