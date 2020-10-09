;;; (define ... (lambda ...))
;;; (if ...)

(define inc
  (lambda (x)
    (+ x 1)))

(define dec
  (lambda (x)
    (- x 1)))

(define zero? ; Predicado: función que devuelve un valor booleano
  (lambda (x)
    (equal? x 0)))

(define add
  (lambda (a b)
    (if (zero? a)
        b
        (inc (add (dec a) b)))))

(define sub
  (lambda (a b)
    (if (zero? b)
        a
        (dec (sub a (dec b))))))

(define mul
  (lambda (a b)
    (if (zero? a)
        a
        (add (mul (dec a) b) b))))

(define less?
  (lambda (a b)
    (if (zero? a)
        (if (zero? b)
            #f
            #t)
        (if (zero? b)
            #f
            (less? (dec a) (dec b))))))

(define div
  (lambda (a b)
    (if (less? a b)
        (sub a a) ; zero
        (inc (div (sub a b) b)))))

(define rem
  (lambda (a b)
    (if (less? a b)
        a
        (rem (sub a b) b))))

(define pow
  (lambda (a b)
    (if (zero? b)
        (inc b)
        (mul a (pow a (dec b))))))
