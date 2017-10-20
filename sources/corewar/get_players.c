/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:28:42 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/20 18:41:57 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int				parse_my_argv(char **av, int *dump)
{
	t_argvparse		*argv;

	return (0);
}

t_player				*get_players(int argc, char **argv, int *dump)
{
	t_player		*player;

	if (argc < 2)
	{
		error(EMPTYARGV, 0);
		return (NULL);
	}
	if (parse_my_argv(argv, dump) < 0)
		return (NULL);
	player = new_player();
	return (player);
	(void)dump;
	(void)argv;
}
