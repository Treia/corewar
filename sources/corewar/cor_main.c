/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 15:19:13 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/24 18:43:54 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int ac, char **av)
{
	t_game		*game;

	if ((game = get_players(ac, av)) == NULL)
		return (usage());
	if (game->verb == -1)
		game->display = init_window(game->display, game);
	run(game);
	if (game->verb == -1)
		clear_window(game->display);
	release_game(game);
	return (0);
}
