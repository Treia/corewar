/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:03:56 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/20 18:58:39 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			usage(void)
{
	ft_putstr_fd("[\033[32m USAGE \033[0m] \033[33m", 2);
	ft_putstr_fd("./corewar [-dump nbr_cycles] [[-n number] champion] ...", 2);
	ft_putstr_fd("\n\033[0m", 2);
	return (-1);
}
