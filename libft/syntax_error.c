/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:13:02 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/21 13:59:13 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		lib_error_one_ten(int id, int ret)
{
	if (id == EMPTYARGV)
		return (print_error(ret, "Empty argv"));
	else if (id == DUMPAV)
		return (print_error(ret, "Dump argv error"));
	else if (id == OPTNAV)
		return (print_error(ret, "flag n argv is incorrect"));
	return (ret);
}

int				syntax_error(int id, int ret)
{
	if (id <= (SYNTAX + 10))
		return (lib_error_one_ten(id, ret));
	return (ret);
}
