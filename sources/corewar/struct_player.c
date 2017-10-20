/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:11:24 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/20 16:20:01 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			free_item_player(t_player *player)
{
	ft_memdel((void *)&player);
}

void				release_player(t_player **player)
{
	if (!player || !*player)
		return ;
	release_player(&((*player)->next));
	free_item_player(*player);
}

t_player			*new_player(void)
{
	t_player	*ret;

	ret = (t_player *)malloc(sizeof(t_player));
	if (ret == NULL)
		return (NULL);
	ret->live = 0;
	ret->nb_live = 0;
	ret->next = NULL;
	return (ret);
}
