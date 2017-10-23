/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:13:02 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/23 12:03:49 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		lib_error_one_ten(int id, int ret)
{
	if (id == EMPTYARGV)
		return (print_error(ret, "ARGUMENT : Empty argv"));
	else if (id == DUMPAV)
		return (print_error(ret, "ARGUMENT : Dump argv error"));
	else if (id == OPTNAV)
		return (print_error(ret, "SYNTAX : flag n argv is incorrect"));
	else if (id == TOO_MANY_CHAMP)
		return (print_error(ret, "SYNTAX : too many champion"));
	else if (id == VERBAV)
		return (print_error(ret, "ARGUMENT : verbose argv invalid"));
	else if (id == NO_CHAMP)
		return (print_error(ret, "ARGUMENT : no champion in argv"));
	return (ret);
}

int				syntax_error(int id, int ret)
{
	if (id <= (SYNTAX + 10))
		return (lib_error_one_ten(id, ret));
	return (ret);
}
