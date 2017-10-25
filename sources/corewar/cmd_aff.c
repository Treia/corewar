/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_aff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:32:08 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/25 20:40:29 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cmd_aff(t_game *game, t_pc *pc, t_cycle *cycle)
{
	int		tab[4];
	int		next;

	(void)cycle;
	get_param_code(game->arena, pc->addr, tab);
	next = get_next_addr(pc->addr, tab, 4, 1);
	if (tab[1] == 1)
	{
		if (get_param_value(game->arena, pc->addr, tab, 4) > 1)
			print_aff(game, tab[1] % 256);
	}
	pc->addr = next;
	return (0);
}
