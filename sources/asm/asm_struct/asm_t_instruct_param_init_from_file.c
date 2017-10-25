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

static int	ft_is_eol_or_separator_char(int c)
{
	return (c == '\n' || c == SEPARATOR_CHAR);
}

int			asm_t_instruct_param_init_from_file(t_parser *parser,
				char **param)
{
	char	*one_param;
	char	*ptr;
	int		param_size;

	ptr = ft_str_first(parser->current_ptr, ft_is_eol_or_separator_char);
	if (ptr == NULL)
		return (asm_message_error(SYNTAX_ERR, parser->current_ptr, ptr));
	param_size = ptr - parser->current_ptr;
	one_param = ft_memalloc(param_size + 1);
	ft_strncpy(one_param, parser->current_ptr, param_size);
	parser->current_ptr = ptr;
	if (*ptr != '\n')
		parser->current_ptr++;
	ft_putendl(one_param);
	return (asm_t_instruct_param_add_end(param, one_param));
}
