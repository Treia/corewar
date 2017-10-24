/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 15:19:13 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/24 16:31:37 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int ac, char **av)
{
	t_game		*game;
	t_display	*display;

	display = NULL;
	if ((game = get_players(ac, av)) == NULL)
		return (usage());
	if (game->verb == -1)
		display = init_window(display, game);
	run(game);
	if (game->verb == -1)
		clear_window(display);
	release_game(game);
	return (0);
}
