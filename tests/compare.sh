#!/bin/bash

typeset -r MY_ASM_DIR="/Users/mressier/Documents/corewar/"
typeset -r REAL_ASM_DIR="/Users/mressier/Documents/corewar/tests/"
typeset -r ASM="asm"

typeset -r FILES=$*

for FILE in ${FILES}
do
	echo "--------------------Mine : ${FILE}--------------------"
	${MY_ASM_DIR}${ASM} ${FILE}
	echo "--------------------Real : ${FILE}--------------------"
	${REAL_ASM_DIR}${ASM} ${FILE}
done

