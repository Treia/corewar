/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:49:33 by mressier          #+#    #+#             */
/*   Updated: 2017/10/23 11:49:34 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"
#include <stdbool.h>

#define PROG_NAME 0
#define COMMENT 1
#define DATAS_SIZE 2

static int		internal_get_parse_mode(const char *file_content)
{
	int		parse_mode;

	parse_mode = -1;
	if (ft_strnequ(file_content, NAME_CMD_STRING, NAME_CMD_STRING_SIZE - 1))
		parse_mode = PROG_NAME;
	else if (ft_strnequ(file_content, COMMENT_CMD_STRING, COMMENT_CMD_STRING_SIZE - 1))
		parse_mode = COMMENT;
	return (parse_mode);
}

static int		internal_all_datas_are_get(int *header_datas_get)
{
	int		i;

	i = 0;
	while (i < DATAS_SIZE)
	{
		if (header_datas_get[i] == 0)
			return (false);
		i++;
	}
	return (true);
}

static int		internal_parse_header(const char *file_content,
					t_header *header, char **next, int *header_datas_get)
{
	t_ft_parse_header	ft_parse[DATAS_SIZE];
	int					parse_mode;

	ft_parse[PROG_NAME] = asm_t_header_get_name;
	ft_parse[COMMENT] = asm_t_header_get_comment;

	parse_mode = internal_get_parse_mode(file_content);
	if (parse_mode == -1)
	{
		if (internal_all_datas_are_get(header_datas_get) == false)
			return (print_error(EXIT_FAILURE, "y manque des trucs dans le header"));
		else
			return (print_error(EXIT_FAILURE, "invalid command"));
	}
	if (header_datas_get[parse_mode] != 0)
		return (print_error(EXIT_FAILURE, "doublons dans le header"));
	header_datas_get[parse_mode] = 1;
	return (ft_parse[parse_mode](file_content, header, next));
}

int				asm_t_header_init_from_file(const char *file_content,
					t_header *out_header, char **next)
{
	int		header_datas_get[DATAS_SIZE];
	char	*ptr;

	ptr = ft_str_first_not(file_content, ft_isspace);
	ft_bzero(header_datas_get, sizeof(int) * DATAS_SIZE);
	while (internal_all_datas_are_get(header_datas_get) == false)
	{
		if (internal_parse_header(ptr, out_header, next,
				header_datas_get) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		ptr = asm_get_next_instruct(*next);
		if (ptr == NULL)
		{
			asm_syntax_error(file_content, ptr);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}


