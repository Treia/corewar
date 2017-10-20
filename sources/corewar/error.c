/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:25:04 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/20 16:45:44 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		lib_error_one_file(int id, int ret)
{
	char	error[80];

	if (id == EMPTYARGV)
		ft_strcpy(error, "Empty argv");
	return (print_error(ret, error));
}

int				error(int id, int ret)
{
	if (id <= (SYNTAX + 5))
		return (lib_error_one_file(id, ret));
	return (ret);
}
