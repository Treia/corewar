.name "King Bibi"
.comment "Hey Mathiiiiiilde"

reload:
	fork %:write
	live %0
	fork %:start_piege
	fork %:push
	fork %:write
	fork %:reload
	fork %:defplus

start_piege:
ld		%-16, r5				# r2 = soustraction de start pr aller a r2 : carry a 1
ld		%-12, r4				# r4 = suite (soustraction de start pr aller a r3 : suite du carry)
ld		%-8, r6					# r6 = soustration de start pr aller a r10 : zjmp
ld		%150994944, r10			# r10 = zjmp
ld		%42991616, r2			# debut de carry a 1
ld		%256, r3				# suite du carry a 1
ld		%16, r16				# decrementation de start
ld		%12, r7					# r7 = addition de end pr aller a r7 : carry a 1
ld		%16, r9					# r9 = suite (addition de end pr aller a r9 : suite du carry)
ld		%20, r11				# r11 = addition de end pr aller a r11 : zjmp
ld		%23, r12				# compteur pour le nombres de pieges
ld		%1, r13
ld		%0, r8					# carry = 1
sti		r1, %:piege1, %1
sti		r1, %:piege2, %1
sti		r1, %:begin, %1
sti		r1, %:live, %1
fork	%:begin

piege1:							# while(1)
live	%118978653103279		# je suis en vie
sti		r2, %:push, r5 
sti		r3, %:push, r4
sti		r10, %:push, r6
sub		r5, r16, r5
sub		r4, r16, r4
sub		r6, r16, r6
sub		r12, r13, r12			# decrementation du compteur
zjmp	%:start_piege			# reviens en debut de boucle
ld		%0, r8					# carry = 1
zjmp	%:piege1				# reviens en debut de boucle

begin:
live 	%13371337
fork	%:piege1
live 	%42424242
fork	%:piege2
live 	%123456789
fork	%:begin
live	%08395432657
fork	%:live
zjmp	%:begin

live:
live	%23456789456780987
zjmp	%:begin

piege2:
live	%198562346853412
sti		r2, %:defplus, r7 
sti		r3, %:defplus, r9
sti		r10, %:defplus, r11
add		r7, r16, r7
add		r9, r16, r9
add		r11, r16, r11
sub		r12, r13, r12			# decrementation du compteur
zjmp	%:start_piege			# reviens en debut de boucle
ld		%0, r8					# carry = 1
zjmp	%:piege2				# reviens en debut de boucle

defplus:
	live	%-42
	ld		%-165, r13
	ld		%0, r2
	zjmp	%:defplus

push:
	live %-1
	ld		%8, r12
	add		r10, r10, r12
	sti		r1, 128, r10
	fork	%:reload
	zjmp	%330
	sti		r1,	128, %845455
	sti		r1, %:push, %:push
	fork	%:push

write:
	live %-42
	sti		r1, 47, %784841784
	live %0
	sti		r1, 47, %8455
	sti		r1, 47, %78484
	zjmp %330
	fork %:write

atj1:
	live	%-42
	sti		r1, %:defdessus, %1
	ld		%57672959, r10
	ld		%-30, r11
	ld		%-5, r12
	st		r1, 6
defplus:
	live	%-42
	fork	%:defdessus
	ld		%-165, r13
	ld		%0, r2
	zjmp	%:defplus
at2:
	sti		r1, %:li1, %1
	sti     r1, %:proc1, %1
	fork    %:atj1
	st      r1, 6
	live    %-42
	or		r1, r1, r7
	ld		%1880161814, r9
	ld      %1879571989, r10
	ld      %34209281, r11

li1:
	live	%-42
	fork	%:push
	ld		%0, r2
	zjmp	%:push

proc1:
	live	%-42
	fork    %:tail

tail:
	ld      %0, r2
	ld      %12, r6
	ld      %0, r2
	zjmp    %:write

defdessus:
	live	%-42
	sti		r10, r11, r13
	add		r12, r13, r13
	xor		r13, %-255, r14
	zjmp	%:zero
	ld		%0, r14
	zjmp	%:defdessus
zero:
	ld		%0, r13
	zjmp	%:defdessus
