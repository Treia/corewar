/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 15:19:13 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/21 18:42:28 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int ac, char **av)
{
	t_game		*game;
	char		arena[MEM_SIZE];

	if ((game = get_players(ac, av)) == NULL)
		return (usage());
	// pcs = get_pc(players);
	// prepare_arena(players, pcs, arena);
	// run(players, pcs, arena, dump);
	release_game(game);
	sleep(80);
	return (0);
	(void)arena;
}
