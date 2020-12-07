;Omar Rodrigo Sorchini Puente A01749389
;Eva Denisse Vargas Sosa A01377098
;Emilio Campuzano Mejía A01378948

;Ejercicio 1
(define ultimo
  (lambda (lst)
    (if (null? (cdr lst))
          (car lst)
          (ultimo(cdr lst))
        )))

;Ejercicio 2
(define sin-ultimo
  (lambda (lst)
    (if (null? (cdr lst))
          (cdr lst)
          (cons (car lst) (sin-ultimo (cdr lst))))))

;Ejercicio 3
(define replica
  (lambda (n x)
    (if (eq? 0 n)
        '()
        (cons x (replica (- n 1) x))
        )))

;Ejercicio 4
(define enlista
  (lambda (n)
    (if (null? n)
        '()
        (cons (list (car n)) (enlista (cdr n)))
        )))

;Ejercicio 5
(define mezcla
    (lambda (n o)
        (if (null? n)
            (if (null? o)
                '()
                o)
            (if (null? o)
                n
                (if (< (car n) (car o))
                    (cons (car n)
                          (mezcla (cdr n) o))
                     (cons (car o)
                           (mezcla n (cdr o))))))))

;Ejercicio 6
(define prefijo?
    (lambda (a b)
        (if (null? a)
            #t
            (if (null? b)
                #f
                (if (equal? (car a) (car b))
                            (prefijo? (cdr a) (cdr b))
                            #f)))))

;Ejercicio 7
(define inserta
  (lambda (n lst)
    (if (null? lst)
        (list n)
        (if (< n (car lst))
          (cons n lst)
          (cons (car lst) (inserta n (cdr lst)))))))

;Ejercicio 8
(define ordena-por-insercion
  (lambda (lst)
    (if (null? lst)
      '()
      (inserta (car lst) (ordena-por-insercion(cdr lst))))))