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

static int		internal_get_parse_mode(const char *line)
{
	int		parse_mode;

	parse_mode = -1;
	if (ft_strnequ(line, NAME_CMD_STRING, NAME_CMD_STRING_SIZE - 1))
		parse_mode = PROG_NAME;
	else if (ft_strnequ(line, COMMENT_CMD_STRING,
			COMMENT_CMD_STRING_SIZE - 1))
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

static int		internal_parse_header(t_parser *parser,
					t_header *header, int *header_datas_get)
{
	t_ft_parse_header	ft_parse[DATAS_SIZE];
	int					parse_mode;

	ft_parse[PROG_NAME] = asm_t_header_get_name;
	ft_parse[COMMENT] = asm_t_header_get_comment;
	parse_mode = internal_get_parse_mode(parser->current_ptr);
	if (parse_mode == -1)
	{
		if (internal_all_datas_are_get(header_datas_get) == false)
			return (asm_syntax_error(parser->file_content,
				parser->current_ptr, "unexpected command"));
		else
			return (print_error(EXIT_FAILURE, "Tu fais du caca"));
	}
	if (header_datas_get[parse_mode] != 0)
	{
		return (asm_syntax_error(parser->file_content, parser->current_ptr,
			(parse_mode == PROG_NAME) ? "COMMAND_NAME" : "COMMENT"));
	}
	header_datas_get[parse_mode] = 1;
	return (ft_parse[parse_mode](parser, header));
}

int				asm_t_header_init_from_file(t_parser *parser,
					t_header *out_header)
{
	int		header_datas_get[DATAS_SIZE];

	parser->current_ptr = ft_str_first_not(parser->file_content, ft_isspace);
	ft_bzero(header_datas_get, sizeof(int) * DATAS_SIZE);
	while (internal_all_datas_are_get(header_datas_get) == false)
	{
		if (internal_parse_header(parser, out_header,
				header_datas_get) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		parser->current_ptr = asm_get_next_instruct(parser->current_ptr);
		if (parser->current_ptr == NULL)
		{
			asm_syntax_error(parser->file_content, parser->current_ptr,
				"unexpected end of file");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
