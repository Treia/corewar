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

static int		internal_get_filename_on_arg(int ac, char **av,
					char **out_filename)
{
	if (ac != 2)
		return (error(EMPTYARGV, EXIT_FAILURE));
	*out_filename = av[1];
	return (EXIT_SUCCESS);
}

int				main(int ac, char **av)
{
	char		*filename;
	char		*file_content;
	t_asm		asm_file_content;

	if (internal_get_filename_on_arg(ac, av, &filename) == EXIT_FAILURE)
		return (asm_usage());
	if (asm_get_file_content(filename, &file_content) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (asm_get_asm_from_file_content(file_content,
			&asm_file_content) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	//if (internal_print_asm_to_file(asm_file_content) == EXIT_FAILURE)
	//	return (EXIT_FAILURE);
	ft_memdel((void **)&file_content);
	return (EXIT_SUCCESS);
}
