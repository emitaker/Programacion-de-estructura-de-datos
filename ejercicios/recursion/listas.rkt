;;; O(N)
(define cons-fin
  (lambda (x lst)
    (if (null? lst)
        (cons x '())
        (cons (car lst)
              (cons-fin x (cdr lst))))))

;;; O(N)
(define dup
  (lambda (lst)
    (if (null? lst)
        '()
        (cons (car lst)
              (cons (car lst)
                    (dup (cdr lst)))))))

(define suma
  (lambda (lst)
    (if (null? lst)
        0
        (+ (car lst) (suma (cdr lst))))))
