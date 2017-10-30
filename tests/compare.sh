#!/bin/bash

typeset -r MY_ASM_DIR="/Users/mressier/Documents/corewar/"
typeset -r REAL_ASM_DIR="/Users/mressier/Documents/corewar/tests/"
typeset -r ASM="asm"

typeset -r FILES=$*

typeset -r MY_OUT_FILE="/tmp/my_out_file"
typeset -r REAL_OUT_FILE="/tmp/real_out_file"
typeset -r MY_STDOUT="/tmp/mystdout"
typeset -r MY_STDERR="/tmp/mystderr"
typeset -r REAL_STDOUT="/tmp/realstdout"
typeset -r REAL_STDERR="/tmp/realstderr"

typeset -r COMPARE_FILE="/tmp/compare"

error()
{
	echo -e "\033[31m[ERROR]\033[0m" $*
}

warning()
{
	echo -e "\033[33m[WARNING]\033[0m" $*
}

success()
{
	echo -e "\033[32m[SUCCESS]\033[0m" $*
}

for FILE in ${FILES}
do
	typeset OUT_FILE=${FILE%.s}.cor #cut the .s and add .cor

	## exec my asm
	${MY_ASM_DIR}${ASM} ${FILE} 1>${MY_STDOUT} 2>${MY_STDERR}
	typeset -i MY_EXIT_STATUS=$?
	[[ -e ${OUT_FILE} ]] && mv ${OUT_FILE} ${MY_OUT_FILE}

	## exec real asm
	${REAL_ASM_DIR}${ASM} ${FILE} 1>${REAL_STDOUT} 2>${REAL_STDERR}
	typeset -i REAL_EXIT_STATUS=$?
	[[ -e ${OUT_FILE} ]] && mv ${OUT_FILE} ${REAL_OUT_FILE}

	## compare both exit status
	(( ${MY_EXIT_STATUS} == ${REAL_EXIT_STATUS} )) || { warning "My exit status: ${MY_EXIT_STATUS}, real exit status: ${REAL_EXIT_STATUS}"; continue; }

	## in case of success, compare out files
	typeset COMPARE_COMMAND="diff ${MY_OUT_FILE} ${REAL_OUT_FILE}"
	`${COMPARE_COMMAND}` > ${COMPARE_FILE}
	typeset EXIT_STATUS=$?
	(( EXIT_STATUS == 0 )) && { success "${FILE}"; }
	(( EXIT_STATUS != 0)) && { error "${COMPARE_COMMAND} : "; cat ${COMPARE_FILE}; }

	unset OUT_FILE
	unset COMPARE_COMMAND
done

rm -rf ${MY_OUT_FILE} ${REAL_OUT_FILE} ${MY_STDOUT} ${MY_STDERR} ${REAL_STDOUT} ${REAL_STDERR}