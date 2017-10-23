/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 13:14:54 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/23 14:22:45 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cmd_base(t_game *game, t_pc *pc)
{
	(void)game;
	return ((pc->addr + 1) % MEM_SIZE);
}

void	*get_cmd(int opcode)
{
	if (opcode == 1)
		return (&cmd_base);
	return (&cmd_base);
}
