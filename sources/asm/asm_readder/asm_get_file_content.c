/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_file_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 10:34:48 by mressier          #+#    #+#             */
/*   Updated: 2017/10/23 10:34:49 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static int		internal_read_file(const char *filename, char **out_content,
					int *size)
{
	if (size == NULL)
	{
		ft_putstr_fd("Param error on "__FILE__ , 2);
		return (EXIT_FAILURE);
	}
	*size = ft_read_file_with_filename(filename, out_content);
	if (*size == -1)
		return (EXIT_FAILURE);
	else
		ft_putmemory(*out_content, *size);
	return (EXIT_SUCCESS);
}

int				asm_get_file_content(const char *filename, t_asm *file_content)
{
	t_asm		content;
	char		*read_file_content;
	int			size;

	internal_read_file(filename, &read_file_content, &size);
	(void)file_content;
	(void)content;
	return (EXIT_FAILURE);
}
