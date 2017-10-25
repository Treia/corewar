/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_asm_word_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 10:41:36 by mressier          #+#    #+#             */
/*   Updated: 2017/10/24 10:41:37 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static void		internal_init_word_type_tab(t_ft_is_word_type *ft_is)
{
	ft_is[COMMAND_NAME] = asm_is_command_name;
	ft_is[COMMAND_COMMENT] = asm_is_command_comment;
	ft_is[LABEL] = asm_is_label;
	ft_is[INSTRUCTION] = asm_is_instruction;
	ft_is[SEPARATOR] = asm_is_separator;
	ft_is[END_OF_LINE] = asm_is_end_of_line;
	ft_is[END_OF_FILE] = asm_is_end_of_file;
}

t_word_type		asm_get_word_type(const char *word)
{
	t_ft_is_word_type		ft_is[NB_WORD_TYPE];
	int						i;

	i = 0;
	internal_init_word_type_tab(ft_is);
	while (i < NB_WORD_TYPE)
	{
		if (ft_is[i](word))
			return (i);
		i++;
	}
	return (INVALID_WORD_TYPE);
}
