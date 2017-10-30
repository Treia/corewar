#!/bin/bash

typeset -r MY_DIR="/Users/mressier/Documents/corewar/"
typeset -r REAL_DIR="/Users/mressier/Documents/corewar/tests/"
typeset -r ASM="asm"
typeset -r COREWAR="corewar"

typeset -r MY_OUT_FILE="/tmp/my_out_file"
typeset -r REAL_OUT_FILE="/tmp/real_out_file"
typeset -r MY_STDOUT="/tmp/mystdout"
typeset -r MY_STDERR="/tmp/mystderr"
typeset -r REAL_STDOUT="/tmp/realstdout"
typeset -r REAL_STDERR="/tmp/realstderr"

typeset -r COMPARE_FILE="/tmp/compare"


typeset -i DUMP=1500
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
	echo -e "\t-a: test for asm"
	echo -e "\t-c: test for corewar"
}

typeset -r OPTION_LIST="vac"
typeset -i VERBOSE=0
typeset -i OPTION_ASM=0
typeset -i OPTION_COREWAR=0


while getopts ${OPTION_LIST} option
do
	case $option in
		"v")
			(( VERBOSE++ ))
			;;
		"a")
			(( OPTION_ASM++ ))
			(( VERBOSE )) && echo "OPTION ASM ACTIVATED"
			;;
		"c")
			(( OPTION_COREWAR++ ))
			(( VERBOSE )) && echo "OPTION COREWAR ACTIVATED"
			;;
		\?)
			usage
			exit 1
			;;
	esac
done

[[ -x ${MY_DIR}${ASM} ]] || make -C ${MY_DIR}

test_asm()
{
	typeset -r ALL_FILES=$*

	draw_line ; echo -e "\t\t\t\tTEST ASM"; draw_line

	for FILE in ${ALL_FILES}
	do
		typeset OUT_FILE=${FILE%.s}.cor #cut the .s and add .cor

		## exec my asm
		${MY_DIR}${ASM} ${FILE} 1>${MY_STDOUT} 2>${MY_STDERR}
		typeset -i MY_EXIT_STATUS=$?
		(( ${MY_EXIT_STATUS} == 0 )) && { cp ${OUT_FILE} ${MY_OUT_FILE}; (( VERBOSE > 1 )) && { draw_line; echo "My out file:"; hexdump ${OUT_FILE}; }; }

		## exec real asm
		${REAL_DIR}${ASM} ${FILE} 1>${REAL_STDOUT} 2>${REAL_STDERR}
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
}

## COREWAR

## $0 first champion
## $1 second champion
test_winner()
{
	(( $# == 2 )) || echo "${FUNCNAME} need 2 champions"

	typeset -r CHAMP_1=$1
	typeset -r CHAMP_2=$2

	${MY_DIR}${COREWAR} ${CHAMP_1} ${CHAMP_2} 1> ${MY_STDOUT}
	${REAL_DIR}${COREWAR} ${CHAMP_1} ${CHAMP_2} 1> ${REAL_STDOUT}

	typeset MY_RESULT_LINE=$(cat ${MY_STDOUT} | grep "And the winner is" | sed -E 's/^And the winner is (.*) !$/\1/')
	typeset REAL_RESULT_LINE=$(cat ${REAL_STDOUT} | grep ", has won !" | sed -E 's/^.*, \"(.*)\", .*$/\1/')

	if [ "${MY_RESULT_LINE}" = "${REAL_RESULT_LINE}" ]
	then
		success "${CHAMP_1} VS ${CHAMP_2} : ${MY_RESULT_LINE}"

		unset MY_RESULT_LINE
		unset REAL_RESULT_LINE
		return 0;
	else
		error "${CHAMP_1} VS ${CHAMP_2} - me : ${MY_RESULT_LINE}, real : ${REAL_RESULT_LINE}"

		unset MY_RESULT_LINE
		unset REAL_RESULT_LINE
		return 1;
	fi
}

## $0 first champion
## $1 second champion
test_dump_end()
{
	(( $# == 2 )) || echo "${FUNCNAME} need 2 champions"

	typeset -r CHAMP_1=$1
	typeset -r CHAMP_2=$2

	${MY_DIR}${COREWAR} ${CHAMP_1} ${CHAMP_2} -dump ${DUMP} 1> ${MY_STDOUT}
	${REAL_DIR}${COREWAR} ${CHAMP_1} ${CHAMP_2} -d ${DUMP} 1> ${REAL_STDOUT}

	typeset MY_GAME=$(cat ${MY_STDOUT} | grep -v "Introducing" | grep -v -- "->" | sed -E 's/^[[:alnum:]]{8}//g')
	typeset REAL_GAME=$(cat ${REAL_STDOUT} | grep -v "Introducing" | grep -v -- "* Player" | sed -E 's/^0x[[:alnum:]]* : //g')

	diff <(echo -e "${MY_GAME}") <(echo -e "${REAL_GAME}") > ${COMPARE_FILE}
	typeset EXIT_STATUS=$?
	(( EXIT_STATUS == 0 )) && { success "${CHAMP_1} VS ${CHAMP_2} EQUAL at dump ${DUMP}"; }
	(( EXIT_STATUS == 0 )) || { ((VERBOSE)) && diff <(echo -e "${MY_GAME}") <(echo -e "${REAL_GAME}") ; error "${CHAMP_1} VS ${CHAMP_2} NOT EQUAL at dump ${DUMP}"; }
	# echo -e "${MY_GAME}"
	# draw_line
	return ;
}

test_corewar()
{
	typeset -r ALL_FILES=($*)
	typeset -i INDEX=0
	typeset -i ERROR_COUNT=0

	draw_line ; echo -e "\t\t\t\tTEST COREWAR"; draw_line

	for  (( i = 0; i <= ${#ALL_FILES[@]}; i++ ))
	do
		typeset VS_FILE_1=${ALL_FILES[$i]}

		for (( j = $i+1; j <= ${#ALL_FILES[@]}; j++ ))
		do
			typeset VS_FILE_2=${ALL_FILES[$j]}
			test_winner "${VS_FILE_1}" "${VS_FILE_2}" || (( ERROR_COUNT ++ ))
			test_dump_end "${VS_FILE_1}" "${VS_FILE_2}" || (( ERROR_COUNT ++ ))

		done
	done
	echo "pouet"
}

shift $((OPTIND - 1))
typeset -r FILES=$*

(( OPTION_ASM )) && test_asm ${FILES}
(( OPTION_COREWAR )) && test_corewar ${FILES}

rm -rf ${MY_OUT_FILE} ${REAL_OUT_FILE} ${MY_STDOUT} ${MY_STDERR} ${REAL_STDOUT} ${REAL_STDERR}
rm -f ./break_files/**/*.cor || error "Cannot delete break_files/**/*.cor";