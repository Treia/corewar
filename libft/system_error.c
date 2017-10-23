/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 10:51:56 by mressier          #+#    #+#             */
/*   Updated: 2017/10/23 19:07:28 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		lib_error_one_ten(int id, int ret)
{
	if (id == INVALID_FILE)
		return (print_error(ret, "Can't read source file"));
	if (id == MALLOC_FAILED)
		return (print_error(ret, "Malloc() failed"));
	return (ret);
}

int				system_error(int id, int ret)
{
	if (id <= (SYSTEM + 10))
		return (lib_error_one_ten(id, ret));
	return (ret);
}
