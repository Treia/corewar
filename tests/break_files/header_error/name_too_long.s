	.name "basicabcdefghijklmnopqrstuvwxyz_0123456789abcdefghijklmnopqrstuvwxyz_0123456789abcdefghijklmnopqrstuvwxyz_0123456789abcdefghijklm"
	.comment "just a basic program"

	ld		%0, r10
	st		r1, 6
l:
	live	%0
	zjmp	%:l