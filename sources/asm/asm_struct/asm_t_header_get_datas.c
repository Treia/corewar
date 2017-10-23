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

#include "asm.h"
#include "libft.h"

// static int	internal_get_element()

int			asm_t_header_get_name(const char *file_content,
				t_header *header, char **next)
{
	char	*start;
	char	*end;
	size_t	diff;

	ft_bzero(header->prog_name, PROG_NAME_LENGTH + 1);
	start = (file_content + NAME_CMD_STRING_SIZE);
	start = ft_str_first_not(start, ft_isspace);
	if (start && *start != STRING_CHAR)
		return (print_error(EXIT_FAILURE, "mauvais caractere"));
	start++;
	end = start;
	while (end != STRING_CHAR)
	{
		if (*end == '\0')
			return (print_error(EXIT_FAILURE, "not terminated string"))
	}
	diff = end - start;
	if (diff > PROG_NAME_LENGTH)
		return (print_error(EXIT_FAILURE, "too big name"));
	ft_strncpy(header->prog_name, start, diff);
	header->prog_name[diff] = '\0';
	print(header->prog_name);
	return (EXIT_SUCCESS);
}

int			asm_t_header_get_comment(const char *file_content,
				t_header *header, char **next)
{
	ft_bzero(header->comment, PROG_NAME_LENGTH + 1);
	(void)file_content;
	(void)header;
	(void)next;
	return (EXIT_SUCCESS);
}

