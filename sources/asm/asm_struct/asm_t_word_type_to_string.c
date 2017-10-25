/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_word_type_to_string.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:13:02 by mressier          #+#    #+#             */
/*   Updated: 2017/10/24 16:13:03 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

char		*asm_t_word_type_to_string(t_word_type type)
{
	char			*words[NB_WORD_TYPE];

	words[COMMAND_NAME] = "COMMAND_NAME";
	words[COMMAND_COMMENT] = "COMMAND_COMMENT";
	words[LABEL] = "LABEL";
	words[INSTRUCTION] = "INSTRUCTION";
	words[SEPARATOR] = "SEPARATOR";
	words[END_OF_LINE] = "ENDLINE";
	words[END_OF_FILE] = "END";
	if (type == INVALID_WORD_TYPE || type >= NB_WORD_TYPE)
		return ("unknow");
	return (words[type]);
}
