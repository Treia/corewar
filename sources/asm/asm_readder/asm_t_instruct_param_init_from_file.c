/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_instruct_param_init_from_file.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 11:15:08 by mressier          #+#    #+#             */
/*   Updated: 2017/10/25 11:15:09 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static char		*internal_dup_and_trim(const char *str, const char *end_str)
{
	char		*new_str;
	int			size;

	size = end_str - str;
	while (size > 0 && ft_isspace(str[size - 1]))
		size--;
	new_str = ft_memalloc(size + 1);
	ft_strncpy(new_str, str, size);
	return (new_str);
}

static void		internal_move_to_next_instruct(t_parser *parser, char *ptr)
{
	parser->current_ptr = ptr;
	if (*ptr != '\n')
		parser->current_ptr++;
	if (*ptr == COMMENT_CHAR)
		parser->current_ptr = asm_skip_commented_lines(ptr);
}

int				asm_t_instruct_param_init_from_file(t_parser *parser,
					t_instruct *instruct)
{
	char	*one_param;
	char	*ptr;

	ptr = ft_str_first(parser->current_ptr, asm_is_param_separator);
	if (ptr == NULL)
		return (asm_message_error(SYNTAX_ERR, parser->current_ptr, ptr));
	one_param = internal_dup_and_trim(parser->current_ptr, ptr);
	if (asm_t_instruct_param_add_end(instruct->param, one_param) == EXIT_FAILURE)
	{
		ft_memdel((void **)&one_param);
		return (asm_param_error(instruct, parser->file_content,
			parser->current_ptr));
	}
	internal_move_to_next_instruct(parser, ptr);
	return (EXIT_SUCCESS);
}
