
(defun atomi (elem)
	(cond
		((atom elem) (list elem))
		(t (mapcan #'atomi elem) )
	)
)