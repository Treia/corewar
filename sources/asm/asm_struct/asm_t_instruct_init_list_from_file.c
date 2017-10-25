/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_instruct_init_from_file.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 09:27:47 by mressier          #+#    #+#             */
/*   Updated: 2017/10/25 09:27:48 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static int			internal_get_all_instructs_for_label(t_parser *parser,
						t_label *label)
{
	t_word_type		word_type;

	while (parser->current_ptr && *parser->current_ptr)
	{
		word_type = asm_get_word_type(parser->current_ptr);
		if (word_type == INSTRUCTION)
		{
			if (asm_t_instruct_init_from_file(parser, label) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else
			break ;
		parser->current_ptr = asm_get_next_instruct(parser->current_ptr);
	}
	return (EXIT_SUCCESS);
}

int					asm_t_instruct_init_list_from_file(t_parser *parser,
						t_label *label_list)
{
	t_word_type		word_type;
	t_label			*ptr;

	ptr = NULL;
	if (label_list == NULL)
		return (print_error(EXIT_FAILURE, "Caca, label list = null!!"));
	while (parser->current_ptr && *parser->current_ptr)
	{
		word_type = asm_get_word_type(parser->current_ptr);
		if (word_type == LABEL)
		{
			ptr = (ptr == NULL) ? label_list : ptr->next;
			if (ptr == NULL)
				return (print_error(EXIT_FAILURE, "Caca dans les labels!!"));
		}
		else if (word_type == INSTRUCTION)
		{
			ptr = (ptr == NULL) ? label_list : ptr->next;
			if (internal_get_all_instructs_for_label(parser,
					ptr) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			continue;
		}
		else
		{
			return (asm_message_error((word_type == INVALID_WORD_TYPE)
				? LEXICAL_ERR : SYNTAX_ERR, parser->file_content,
				parser->current_ptr));
		}
		parser->current_ptr = asm_get_next_instruct(parser->current_ptr);
	}
	return (EXIT_SUCCESS);
}
