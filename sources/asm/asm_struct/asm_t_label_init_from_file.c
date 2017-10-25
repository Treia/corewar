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

static int		internal_set_label_name(const char *name, t_label *new_label)
{
	char			*name_end;
	int				label_size;

	name_end = ft_strchr(name, LABEL_CHAR);
	if (name_end == NULL)
		return (print_error(EXIT_FAILURE, "Tu fais du caca !"));
	label_size = name_end - name;
	if (label_size >= LABEL_LENGTH_MAX)
		return (print_error(EXIT_FAILURE, "Label name too long (max 128)")); // temp
	ft_strncpy(new_label->name, name, label_size);
	return (EXIT_SUCCESS);
}

static int			internal_init_and_add_one_label(t_parser *parser,
						t_label **list)
{
	t_label			*new_label;

	new_label = asm_t_label_new();
	if (internal_set_label_name(parser->current_ptr,
			new_label) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	*list = asm_t_label_add_end(*list, new_label);
	return (EXIT_SUCCESS);
}

static int			internal_get_all_labels_on_file(t_parser *parser,
						t_label **list_to_set)
{
	t_word_type		word_type;

	while (parser->current_ptr && *parser->current_ptr)
	{
		word_type = asm_get_word_type(parser->current_ptr);
		if (word_type == INVALID_WORD_TYPE)
		{
			return (asm_syntax_error(parser->file_content,
				parser->current_ptr));
		}
		if (word_type == LABEL)
		{
			if (internal_init_and_add_one_label(parser,
					list_to_set) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else
		{
			if (*list_to_set == NULL)
				*list_to_set = asm_t_label_add_end(*list_to_set, asm_t_label_new());
		}
		parser->current_ptr = asm_get_next_instruct(parser->current_ptr);
	}
	return (EXIT_SUCCESS);
}

int					asm_t_label_init_from_file(t_parser *parser,
						t_label **list_to_set)
{
	if (internal_get_all_labels_on_file(parser, list_to_set) == EXIT_FAILURE)
	{
		asm_t_label_del_list(*list_to_set);
		*list_to_set = NULL;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
