/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:51:34 by mressier          #+#    #+#             */
/*   Updated: 2017/10/20 15:51:59 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <unistd.h>

static int		internal_get_filename_on_arg(int ac, char **av, char **out_filename)
{
	if (ac != 2)
		return (error(EMPTYARGV, EXIT_FAILURE));
	*out_filename = av[1];
	return (EXIT_SUCCESS);
}

static int		internal_get_basic_file_content(const char *filename, t_asm *file_content)
{
	t_asm		content;
	char		*read_file_content;
	int			size;

	asm_read_file(filename, &read_file_content, &size);
	(void)file_content;
	(void)content;
	return (EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	char		*filename;
	t_asm		file_content;

	if (internal_get_filename_on_arg(ac, av, &filename) == EXIT_FAILURE)
		return (asm_usage());

	if (internal_get_basic_file_content(filename, &file_content) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	//if (internal_get_asm_from_file_content(file_content) == EXIT_FAILURE)
	//	return (EXIT_FAILURE);

	//if (internal_print_asm_to_file(file_content) == EXIT_FAILURE)
	//	return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
