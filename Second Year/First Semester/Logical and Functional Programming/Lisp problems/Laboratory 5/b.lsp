(defun invers (l)
	(cond
		((null l) nil)
		((atom(car l))
			(append
				(invers(cdr l))
				(list (car l))
			)
		)
		((listp(car l))
			(append
				(invers(cdr l))
				(list(invers(car l)))
			)
		)
	)
)
