/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:28:42 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/23 12:04:31 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int				len_argv(t_argvparse *argv)
{
	t_argvparse	*begin;
	int			nb;

	begin = argv;
	nb = 0;
	while (begin)
	{
		nb++;
		begin = begin->next;
	}
	return (nb);
}

static t_argvparse		*clean_argv(t_argvparse **argv)
{
	release_argvparse(argv);
	return (NULL);
}

static t_argvparse		*make_argv_list(char **av)
{
	t_argvparse		*ret;
	t_argvparse		*tmp;
	int				index;

	index = 1;
	ret = NULL;
	while (av[index])
	{
		tmp = new_argvparse();
		tmp->name = ft_strdup(av[index]);
		add_in_argvparse_list(&ret, tmp);
		index++;
	}
	return (ret);
}

static t_argvparse		*parse_my_argv(char **av, t_game *game)
{
	t_argvparse		*argv;

	argv = make_argv_list(av);
	if (clear_dump(&game->dump, &argv) < 0)
		return (clean_argv(&argv));
	if (clear_verbose_option(&game->verb, &argv) < 0)
		return (clean_argv(&argv));
	if (clear_n_option(&argv) < 0)
		return (clean_argv(&argv));
	if (check_is_correct_champ(argv, game) < 0)
		return (clean_argv(&argv));
	return (argv);
}

t_game					*get_players(int argc, char **argv)
{
	t_game			*game;
	t_argvparse		*l_argv;
	int				nb_players;

	if (argc < 2)
	{
		error(EMPTYARGV, 0);
		return (NULL);
	}
	game = new_game();
	if ((l_argv = parse_my_argv(argv, game)) == NULL)
		return (NULL);
	if (game->verb < 0 || game->verb > 7)
	{
		error(VERBAV, 0);
		release_game(game);
		release_argvparse(&l_argv);
		return (NULL);
	}
	nb_players = len_argv(l_argv);
	if (nb_players < 1)
		return (NULL);
	game->players = make_player_list(l_argv, game, (MEM_SIZE / nb_players));
	release_argvparse(&l_argv);
	return (game);
}
