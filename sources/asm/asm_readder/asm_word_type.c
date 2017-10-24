/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_word_type_is.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 10:50:52 by mressier          #+#    #+#             */
/*   Updated: 2017/10/24 10:50:53 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdbool.h>

int				asm_is_command_name(const char *word)
{
	if (ft_strnequ(word, NAME_CMD_STRING, NAME_CMD_STRING_SIZE - 1))
		return (true);
	return (false);
}

int				asm_is_command_comment(const char *word)
{
	if (ft_strnequ(word, COMMENT_CMD_STRING, COMMENT_CMD_STRING_SIZE - 1))
		return (true);
	return (false);
}

int				asm_is_label(const char *word)
{
	(void)word;
	return (false);
}

int				asm_is_instruction(const char *word)
{
	(void)word;
	return (false);
}
