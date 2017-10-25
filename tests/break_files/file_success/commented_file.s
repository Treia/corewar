	.name "basic"
	.comment "just a basic living prog"

#start instructions
	ld		%0, r10
	st		r1, 6
#be sure we live
l:		# ninja comment :D
	live	%0		# assure we live
	zjmp	%:l
