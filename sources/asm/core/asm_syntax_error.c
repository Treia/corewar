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

static char		*internal_get_str_word_type(const char *word)
{
	t_word_type		type;

	type = asm_get_word_type(word);
	return (asm_t_word_type_to_string(type));
}

static void		internal_add_problematic_word(const char *type_word,
					const char *word_error, char *error)
{
	ft_strcat(error, " ");
	ft_strcat(error, type_word);
	ft_strcat(error, " \"");
	ft_strcat(error, word_error);
	ft_strcat(error, "\"");
}

int				asm_syntax_error(const char *start_file, const char *error_ptr)
{
	char		error[MESSAGE_SIZE_MAX + 1];
	char		word_error[WORD_ERROR_SIZE_MAX + 1];
	char		*type_word;

	ft_bzero(error, MESSAGE_SIZE_MAX + 1);
	ft_bzero(word_error, WORD_ERROR_SIZE_MAX + 1);
	asm_error_get_word_error(error_ptr, word_error, WORD_ERROR_SIZE_MAX);
	type_word = internal_get_str_word_type(word_error);
	if (ft_strequ(type_word, "unknow"))
		ft_strcpy(error, "LEXICAL ERROR: ");
	else
		ft_strcpy(error, "SYNTAX ERROR: ");
	asm_error_concat_line_and_char(start_file,
		error_ptr, error);
	internal_add_problematic_word(type_word, word_error, error);
	return (print_error(EXIT_FAILURE, error));
}
