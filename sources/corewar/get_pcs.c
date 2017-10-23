/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:10:30 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/23 16:35:45 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				get_pcs_struct(t_pc **pcs, t_player *player, int index)
{
	t_pc		*temp;

	if ((temp = new_pc(player->live)) == NULL)
		return (-1);
	temp->addr = index;
	push_in_front_pc(pcs, temp);
	return (0);
}
