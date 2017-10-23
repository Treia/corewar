/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_header_get_datas.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:11:55 by mressier          #+#    #+#             */
/*   Updated: 2017/10/23 16:11:56 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

static char		*internal_get_ptr_on_start(const char *file_content)
{
	char	*start;

	start = ft_str_first_not(file_content, ft_isspace);
	if (start && *start != STRING_CHAR)
		return (NULL);
	start++;
	return (start);
}

static char		*internal_get_ptr_on_end(const char *start)
{
	char	*end;

	end = (char *)start;
	while (*end != STRING_CHAR)
	{
		if (*end == '\0')
			return (NULL);
		end++;
	}
	return (end);
}

static int	internal_get_element_inside_quotes(t_parser *parser,
				size_t size_max, char *out_element)
{
	char	*start;
	char	*end;
	size_t	diff;

	ft_bzero(out_element, PROG_NAME_LENGTH + 1);
	start = internal_get_ptr_on_start(parser->current_ptr);
	if (start == NULL)
		return (print_error(EXIT_FAILURE, "mauvais caractere"));
	end = internal_get_ptr_on_end(start);
	if (end == NULL)
		return (print_error(EXIT_FAILURE, "not terminated string"));
	diff = end - start;
	if (diff > size_max)
		return (print_error(EXIT_FAILURE, "too big"));
	ft_strncpy(out_element, start, diff);
	out_element[diff] = '\0';
	parser->current_ptr = end + 1;
	ft_putendl(parser->current_ptr);
	return (EXIT_SUCCESS);
}

int			asm_t_header_get_name(t_parser *parser, t_header *header)
{
	parser->current_ptr = ((char *)parser->current_ptr + NAME_CMD_STRING_SIZE);
	if (internal_get_element_inside_quotes(parser, PROG_NAME_LENGTH,
			header->prog_name) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_putendl(header->prog_name);
	return (EXIT_SUCCESS);
}

int			asm_t_header_get_comment(t_parser *parser, t_header *header)
{
	parser->current_ptr = ((char *)parser->current_ptr + COMMENT_CMD_STRING_SIZE);
	if (internal_get_element_inside_quotes(parser, COMMENT_LENGTH,
			header->comment) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_putendl(header->comment);
	return (EXIT_SUCCESS);
}

