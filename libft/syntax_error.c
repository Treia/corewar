/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:13:02 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/21 17:20:01 by mdezitte         ###   ########.fr       */
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
	return (ret);
}

int				syntax_error(int id, int ret)
{
	if (id <= (SYNTAX + 10))
		return (lib_error_one_ten(id, ret));
	return (ret);
}
