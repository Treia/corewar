/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 16:53:32 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/24 16:53:45 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			release_game(t_game *game)
{
	if (game->players != NULL)
		release_player(&game->players);
	if (game->pcs != NULL)
		release_pcs(&game->pcs);
	ft_memdel((void *)&game);
}

t_game			*new_game(void)
{
	t_game		*ret;

	ret = (t_game *)malloc(sizeof(t_game));
	if (ret == NULL)
		return (NULL);
	ret->verb = 0;
	ret->players = NULL;
	ret->pcs = NULL;
	ret->nb_pc = 0;
	ft_bzero(ret->arena, MEM_SIZE);
	ret->dump = -999;
	ret->winner = 0;
	return (ret);
}
