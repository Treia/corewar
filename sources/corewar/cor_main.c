/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 15:19:13 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/23 16:08:06 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int ac, char **av)
{
	t_game		*game;

	if ((game = get_players(ac, av)) == NULL)
		return (usage());
	//print_arena(game->arena, NB_OCTET_DISPLAY);
	// pcs = get_pc(players);
	// prepare_arena(players, pcs, arena);
	run(game);
	release_game(game);
	return (0);
}
