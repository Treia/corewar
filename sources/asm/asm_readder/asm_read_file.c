/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_read_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:52:19 by mressier          #+#    #+#             */
/*   Updated: 2017/10/20 15:52:22 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"

int			asm_read_file(const char *filename, char **out_content, int *size)
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
