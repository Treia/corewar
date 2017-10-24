/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_label_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:14:52 by mressier          #+#    #+#             */
/*   Updated: 2017/10/24 14:14:54 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static int				internal_get_all_labels_on_file(t_parser *parser,
							t_label **list_to_set)
{
	t_word_type		word_type;

	while (parser->current_ptr && *parser->current_ptr)
	{
		word_type = asm_get_word_type(parser->current_ptr);
		if (word_type == INVALID_WORD_TYPE)
			return (asm_syntax_error(parser->file_content,
				parser->current_ptr));
		ft_putendl(asm_t_word_type_to_string(word_type));
		parser->current_ptr = asm_get_next_instruct(parser->current_ptr);
	}
	(void)list_to_set;
	return (EXIT_FAILURE);
}

int						asm_t_label_init_from_file(t_parser *parser,
							t_label **list_to_set)
{
	char		*ptr_on_file_start;

	ptr_on_file_start = parser->current_ptr;
	if (internal_get_all_labels_on_file(parser, list_to_set) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_putendl(parser->current_ptr);
	return (EXIT_FAILURE);
}
