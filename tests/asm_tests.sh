#!/bin/bash

typeset -r ASM_DIR="../"
typeset -r ASM_NAME="asm"
typeset -r FT_ASM=${ASM_DIR}${ASM_NAME}
typeset -r REAL_ASM="./"${ASM_NAME}

## tests dir
typeset -r TEST_DIR="./break_files/"
typeset -r ERROR_DIR=$(find ${TEST_DIR} -d -name "*_error")
typeset -r SUCCESS_DIR=$(find ${TEST_DIR} -d -name "*_success")

## created files
typeset -r TMP_OUT_FILE="/tmp/asm_out"
typeset -r TMP_ERR_FILE="/tmp/asm_err"
typeset -r TMP_REAL_OUT_FILE="/tmp/asm_out_real"
typeset -r TMP_REAL_ERR_FILE="/tmp/asm_err_real"

##
## initialisation
##

[[ -x ${FT_ASM} ]] || { make -C ${ASM_DIR} || echo "Fail to create ${FT_ASM}"; }

typeset -i ERRORS=0
typeset -i FATAL_ERRORS=0
typeset -i NB_TESTS=0

#scripts details
typeset -r OPTION_LIST="ves"
usage()
{
	echo -e "Usage: $0 [-${OPTION_LIST}]"
	echo -e "\t\t-v : display verbose (error messages from asm compilation)"
	echo -e "\t\t-e : test only errors files"
	echo -e "\t\t-s : test only success files"
}

#options
typeset -i VERBOSE=0
typeset -i ERRORS_TESTS=1
typeset -i SUCCESS_TESTS=1

while getopts ${OPTION_LIST} option
do
	case $option in
		"v")
			(( VERBOSE++ ))
			;;
		"e")
			ERRORS_TESTS=1
			SUCCESS_TESTS=0
			;;
		"s")
			ERRORS_TESTS=0
			SUCCESS_TESTS=1
			;;
		?)
			usage
			exit 1
			;;
	esac
done

##
## functions
##

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

draw_line()
{
	echo -e "--------------------------------------------------------------------------------"
}

## exec_file
##
## @param	$0 filename
test_fatal_error()
{
	(( $# == 1 )) || { error "Missing argument in ${FUNCNAME}"; return 1; }

	typeset -r CMD=$1
	typeset -i EXIT_STATUS=0

	${CMD} 1>${MY_NM_FILE} 2>&-
	EXIT_STATUS=$?
	(( EXIT_STATUS == 139 )) && { echo -e "\033[34m[SEGV]\033[0m"; (( FATAL_ERRORS++ )); } # segfault
	(( EXIT_STATUS == 138 )) && { echo -e "\033[34m[BUS]\033[0m"; (( FATAL_ERRORS++ )); } # bus error
	(( EXIT_STATUS == 136 )) && { echo -e "\033[34m[FLOATPT]\033[0m"; (( FATAL_ERRORS++ )); } # floating point
	(( EXIT_STATUS == 134 )) && { echo -e "\033[34m[ABRT]\033[0m"; (( FATAL_ERRORS++ )); } # abort
	return ${EXIT_STATUS}
}

## exec_file
##
## @param	$0 filename

exec_file()
{
	(( $# == 1 )) || { error "Missing argument in ${FUNCNAME}"; return 1; }

	typeset -r FILE=$1

	${FT_ASM} ${FILE} 1>${TMP_OUT_FILE} 2>${TMP_ERR_FILE}
	typeset FT_EXIT_STATUS=$?
	${REAL_ASM} ${FILE} 1>${TMP_REAL_OUT_FILE} 2>${TMP_REAL_ERR_FILE}
	typeset REAL_EXIT_STATUS=$?

	(( ${VERBOSE} != 0 )) && { echo -e "\n\t\t\t> asm output <"; cat ${TMP_ERR_FILE};
								echo -e "\n\t\t\t> official asm output <"; cat ${TMP_REAL_OUT_FILE} | head -n 10; echo ""; }

	(( ${FT_EXIT_STATUS} == ${REAL_EXIT_STATUS} )) || { warning "personnal asm and official asm doesn't return the same exit status"; }
	return ${FT_EXIT_STATUS}
}

## test_file_error
##
## @param 	$0 filename

test_file_error()
{
	(( $# == 1 )) || { error "Missing argument in ${FUNCNAME}"; return 1; }

	typeset -r FILE=$1

	exec_file ${FILE}
	typeset EXIT_STATUS=$?
	(( ${EXIT_STATUS} != 0 )) || { error "${FILE} : expect return on error "; return 1; }
	success ${FILE}
	(( ${VERBOSE} != 0 )) && draw_line
	return 0
}

## test_file_success
##
## @param	$0 filename

test_file_success()
{
	(( $# == 1 )) || { error "Missing argument in ${FUNCNAME}"; return 1; }

	typeset -r FILE=$1

	exec_file ${FILE}
	typeset EXIT_STATUS=$?
	(( ${EXIT_STATUS} == 0 )) || { error "${FILE} : expect return on success"; return 1; }
	success ${FILE}
	(( ${VERBOSE} != 0 )) && draw_line
	return 0
}

##
## test all files
##

if (( ${ERRORS_TESTS} ))
then
	for FILE in $(find ${ERROR_DIR} -name "*.s")
	do
		test_file_error ${FILE}
		typeset EXIT_STATUS=$?
		(( ${EXIT_STATUS} == 0 )) || (( ERRORS++ ))
		(( NB_TESTS++ ))
	done
fi

if (( ${SUCCESS_TESTS} ))
then
	for FILE in $(find ${SUCCESS_DIR} -name "*.s")
	do
		test_file_success ${FILE}
		typeset EXIT_STATUS=$?
		(( ${EXIT_STATUS} == 0 )) || (( ERRORS++ ))
		(( NB_TESTS++ ))
	done
fi

draw_line

(( ${ERRORS} == 0 )) || error "${ERRORS} ERRORS ON ${NB_TESTS}"
(( ${FATAL_ERRORS} == 0 )) || error "/!\/!\\${ERRORS} FATAL ERRORS /!\/!\\"
(( ${ERRORS} == 0 )) && success "${ERRORS} ERRORS ON ${NB_TESTS}"

# delete temporary files

rm -rf ${TMP_OUT_FILE} ${TMP_ERR_FILE} || { error "cannot delete ${TMP_OUT_FILE} ${TMP_ERR_FILE}"; exit 1; }
rm -rf ${TMP_REAL_OUT_FILE} ${TMP_REAL_ERR_FILE} || { error "cannot delete ${TMP_REAL_OUT_FILE} ${TMP_REAL_ERR_FILE}"; exit 1; }