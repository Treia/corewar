/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 15:19:13 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/20 15:34:19 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int ac, char **av)
{
	t_player	*players;
	t_pc		*pcs;
	char		arena[MEM_SIZE];
	int			dump;

	players = get_players(ac, av, &dump);
	pcs = get_pc(players);
	prepare_arena(players, pcs, arena);
	run(players, pcs, arena, dump);
	return (0);
}
