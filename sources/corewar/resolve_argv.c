/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 19:12:25 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/20 20:16:35 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		ft_isnum(const char *str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		if (ft_isdigit(str[index]) != 1)
			return (0);
		index++;
	}
	return (1);
}

static int		clear_first(t_argvparse **argv, int *dump)
{
	t_argvparse		*tmp;

	while ((*argv) && ft_strequ((*argv)->name, "-dump"))
	{
		if (ft_isnum((*argv)->next->name) == 0)
			return (error(DUMPAV, -1));
		*dump = ft_atoi((*argv)->next->name);
		tmp = (*argv);
		(*argv) = (*argv)->next->next;
		free_item_argvparse(tmp->next);
		free_item_argvparse(tmp);
	}
	return (0);
}

int				clear_dump(int *dump, t_argvparse **argv)
{
	t_argvparse		*tmp;

	if (!(*argv)->next)
		return (0);
	if (clear_first(argv, dump) < 0)
		return (-1);
	while ((*argv) && (*argv)->next)
	{
		if (ft_strequ((*argv)->next->name, "-dump"))
		{
			if ((*argv)->next->next == NULL)
				return (0);
			if (ft_isnum((*argv)->next->next->name) == 0)
				return (error(DUMPAV, -1));
			*dump = ft_atoi((*argv)->next->next->name);
			tmp = (*argv)->next;
			(*argv)->next = (*argv)->next->next->next;
			free_item_argvparse(tmp->next);
			free_item_argvparse(tmp);
		}
		else
			(*argv) = (*argv)->next;
	}
	return (0);
}
