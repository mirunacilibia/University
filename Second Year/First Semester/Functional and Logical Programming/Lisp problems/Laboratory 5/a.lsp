(defun apare(e l)
	(cond
		((null l) nil)
		((equal (CAR l) e) t)
		(t (apare e (CDR l)))
	)
)

(defun diferenta(a b)
	(cond
		((null a) nil)
		((apare (CAR a) b) (diferenta (CDR a) b))
		(t (APPEND (LIST (CAR a)) (diferenta (CDR a) b)))
	)
)