(defun construire_impar(l)
	(cond
		((null l) nil)
		((and (listp (car l)) (=(mod(length(car l)) 2) 1))(append(list(caar l)) (construire_impar(cdr l))))
		(t(construire_impar(cdr l)))
	)

)

(defun construire_wrapper(l)
	(cond
		( (=(mod(length l) 2) 1)
			(append (list(car l)) (construire_impar l))
		)
		(t (construire_impar l))
	)
)