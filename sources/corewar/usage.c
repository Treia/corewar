/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:03:56 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/23 12:24:32 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			usage(void)
{
	ft_putstr_fd("[\033[32m USAGE \033[0m] \033[33m", 2);
	ft_putstr_fd("./corewar [-dump nbr_cycles] [-v 0-7] ", 2);
	ft_putstr_fd("[[-n number] champion] ...\n\033[0m", 2);
	// 1 = cycle, cycle_to_die
	// 2 = pc live / pc kill
	// 4 = AFF
	return (-1);
}
