#!/bin/bash

typeset -r MY_ASM_DIR="/Users/mressier/Documents/corewar/"
typeset -r REAL_ASM_DIR="/Users/mressier/Documents/corewar/tests/"
typeset -r ASM="asm"

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

draw_line()
{
	echo -e "--------------------------------------------------------------------------------"
}

usage()
{
	echo -e "$0 [-v] <files>"
	echo -e "\t-v: verbose (display error output if error occur on files)"
	echo -e "\t-vv: verbose (display hexdump of each success files)"
}

typeset -r OPTION_LIST="v"
typeset -i VERBOSE=0

while getopts ${OPTION_LIST} option
do
	case $option in
		"v")
			(( VERBOSE++ ))
			;;
		\?)
			usage
			exit 1
			;;
	esac
done

[[ -x ${MY_ASM_DIR}${ASM} ]] || make -C ${MY_ASM_DIR}

shift $((OPTIND - 1))
typeset -r FILES=$*

for FILE in ${FILES}
do
	typeset OUT_FILE=${FILE%.s}.cor #cut the .s and add .cor

	## exec my asm
	${MY_ASM_DIR}${ASM} ${FILE} 1>${MY_STDOUT} 2>${MY_STDERR}
	typeset -i MY_EXIT_STATUS=$?
	(( ${MY_EXIT_STATUS} == 0 )) && { cp ${OUT_FILE} ${MY_OUT_FILE}; (( VERBOSE > 1 )) && { draw_line; echo "My out file:"; hexdump ${OUT_FILE}; }; }

	## exec real asm
	${REAL_ASM_DIR}${ASM} ${FILE} 1>${REAL_STDOUT} 2>${REAL_STDERR}
	typeset -i REAL_EXIT_STATUS=$?
	(( ${REAL_EXIT_STATUS} == 0 )) && { cp ${OUT_FILE} ${REAL_OUT_FILE}; (( VERBOSE > 1 )) && { draw_line; echo "Real out file:"; hexdump ${OUT_FILE}; }; }

	## compare both exit status
	(( ${MY_EXIT_STATUS} == ${REAL_EXIT_STATUS} )) || { warning "${FILE} : My exit status: ${MY_EXIT_STATUS}, real exit status: ${REAL_EXIT_STATUS}"; }
	if (( ${MY_EXIT_STATUS} == ${REAL_EXIT_STATUS} ))
	then

		## in case of success, compare out files
		if (( ${MY_EXIT_STATUS} == 0 ))
		then
			typeset COMPARE_COMMAND="diff ${MY_OUT_FILE} ${REAL_OUT_FILE}"
			echo `${COMPARE_COMMAND}` > ${COMPARE_FILE}
			typeset EXIT_STATUS=$?
			(( EXIT_STATUS == 0 )) && { success "${FILE} : return success OK and diff OK "; }
			(( EXIT_STATUS != 0)) && { error "${COMPARE_COMMAND} (return success OK and diff KO) : "; cat ${COMPARE_FILE}; }
		else

			if (( VERBOSE ))
			then
				draw_line; echo "My stderr:"
				# cat ${MY_STDOUT}; draw_line;
				cat ${MY_STDERR}
				draw_line; echo "Real stderr:"
				cat ${REAL_STDERR}; cat ${REAL_STDOUT};
			fi
			(( EXIT_STATUS == 0 )) && { success "${FILE} : return error OK"; }
		fi

	fi

	unset OUT_FILE
	unset COMPARE_COMMAND
done

rm -rf ${MY_OUT_FILE} ${REAL_OUT_FILE} ${MY_STDOUT} ${MY_STDERR} ${REAL_STDOUT} ${REAL_STDERR}
rm -f ./break_files/**/*.cor || error "Cannot delete break_files/**/*.cor";