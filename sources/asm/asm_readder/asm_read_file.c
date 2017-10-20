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

#define BUF_READ	2048

static int	internal_read_file_content(int fd, char **out_content)
{
	char		*content;
	char		buf[BUF_READ];
	int			ret;

	// content =
	while ((ret = read(fd, buf, BUF_READ)) > 0)
	{

	}
	return (ret);
}

int			asm_read_file(const char *filename, char **out_content)
{
	int		fd;

	if (out_content == NULL || *out_content == NULL || filename == NULL)
	{
		ft_putstr_fd("Param error on "__FILE__ , 2);
		return (EXIT_FAILURE);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		// error message
		return (EXIT_FAILURE);
	}
	if (internal_read_file_content(fd, out_content) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
