/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_asm_from_file_content.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:02:42 by mressier          #+#    #+#             */
/*   Updated: 2017/10/23 11:02:43 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

int			asm_get_asm_from_file_content(const char *file_content,
				t_asm *asm_content, char **next)
{
	t_header	header;

	if (asm_t_header_init_from_file(file_content, &header, next) == EXIT_FAILURE)
	{
		print_error(0, "Cannot get header");
		return (EXIT_FAILURE);
	}
	asm_content->header = header;
	return (EXIT_FAILURE);
}
