.name "basic"
.comment "just a basic living prog"

		st		r1,		6
live:	live	%0
		sub		r2, 	r2,		r2
		zjmp	%:live
