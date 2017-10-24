/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_syntax_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:21:36 by mressier          #+#    #+#             */
/*   Updated: 2017/10/23 14:21:37 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

#define WORD_ERROR_SIZE_MAX	25
#define MESSAGE_SIZE_MAX		(1024 + WORD_ERROR_SIZE_MAX)

#define DETAILS_LINE_SIZE_MAX	255

static char	*internal_get_str_matching_word_type(const char *word)
{
	char			*words[NB_WORD_TYPE];
	t_word_type		type;

	words[COMMAND_NAME] = "COMMAND_NAME";
	words[COMMAND_COMMENT] = "COMMAND_COMMENT";
	words[LABEL] = "LABEL";
	words[INSTRUCTION] = "INSTRUCTION";
	words[END_OF_FILE] = "END";
	type = asm_get_asm_word_type(word);
	if (type == INVALID_WORD_TYPE || type >= NB_WORD_TYPE)
		return ("unknow");
	return (words[type]);
}

static void	internal_add_problematic_word(const char *error_ptr, char *error)
{
	char	word_error[WORD_ERROR_SIZE_MAX + 1];
	char	*type_word;

	ft_bzero(word_error, WORD_ERROR_SIZE_MAX + 1);
	asm_error_get_word_error(error_ptr, word_error, WORD_ERROR_SIZE_MAX);
	type_word = internal_get_str_matching_word_type(word_error);
	ft_strcat(error, " ");
	ft_strcat(error, type_word);
	ft_strcat(error, " \"");
	ft_strcat(error, word_error);
	ft_strcat(error, "\"");
}

int			asm_syntax_error(t_parser *parser,
				const char *message)
{
	char		error[MESSAGE_SIZE_MAX + 1];

	ft_bzero(error, MESSAGE_SIZE_MAX + 1);
	ft_strcpy(error, "SYNTAX ERROR: ");
	if (!parser->current_ptr)
		ft_strcat(error, "\"[null]\"");
	else
		asm_error_concat_line_and_char(parser->file_content,
			parser->current_ptr, error);
	if (message)
	{
		ft_strcat(error, " ");
		ft_strcat(error, message);
	}
	internal_add_problematic_word(parser->current_ptr, error);
	return (print_error(EXIT_FAILURE, error));
}
