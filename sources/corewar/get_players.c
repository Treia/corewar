/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:28:42 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/21 15:07:10 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void					print_argv(t_argvparse *argv)
{
	while (argv)
	{
		ft_putstr(argv->name);
		ft_putnbr(argv->id);
		ft_putendl(" ");
		argv = argv->next;
	}
}

static t_argvparse 		*make_argv_list(char **av)
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

static int				parse_my_argv(char **av, int *dump)
{
	t_argvparse		*argv;

	argv = make_argv_list(av);
	if (clear_dump(dump, &argv) < 0)
	{
		release_argvparse(&argv);
		return (-1);
	}
	if (clear_n_option(&argv) < 0)
	{
		release_argvparse(&argv);
		return (-1);
	}
	if (check_is_correct_champ(argv) < 0)
	{
		release_argvparse(&argv);
		return (-1);
	}
	print_argv(argv);
	release_argvparse(&argv);
	return (0);
	(void)dump;
}

t_player				*get_players(int argc, char **argv, int *dump)
{
	t_player		*player;

	if (argc < 2)
	{
		error(EMPTYARGV, 0);
		return (NULL);
	}
	*dump = -1;
	if (parse_my_argv(argv, dump) < 0)
		return (NULL);
	player = new_player();
	return (player);
	(void)dump;
	(void)argv;
}
