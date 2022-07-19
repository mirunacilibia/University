(defun nr_subarbori(l)
	(cond
		((null l) 0)
		(	(and 	(listp (car l))
				(= (length (car l)) 0) 
		  	)
			(nr_subarbori (cdr l))
		)
		(t (+ 1 (nr_subarbori (cdr l))))
	)
)


(defun convert(l)
	(cond
		((null l) nil)
		(t (append
			(append
				(append (list (car l))
					(list (nr_subarbori(cdr l)))
				)
				(convert (car (cdr l)))
			)
			(convert(car (cdr (cdr l))))
		))
	)
)