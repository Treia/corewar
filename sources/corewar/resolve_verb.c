/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_verb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 16:48:54 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/21 16:52:25 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		free_verb_and_val(t_argvparse *item)
{
	free_item_argvparse(item->next);
	free_item_argvparse(item);
	return (0);
}

static int		for_first(t_argvparse **argv, int *dump)
{
	t_argvparse		*tmp;

	while ((*argv) && ft_strequ((*argv)->name, "-v"))
	{
		if (ft_isnum((*argv)->next->name) == 0)
			return (error(DUMPAV, -1));
		*dump = ft_atoi((*argv)->next->name);
		tmp = (*argv);
		(*argv) = (*argv)->next->next;
		free_verb_and_val(tmp);
	}
	return (0);
}

int				clear_verbose_option(int *dump, t_argvparse **argv)
{
	t_argvparse		*tmp;
	t_argvparse		*begin;

	if (!(*argv) || !(*argv)->next)
		return (0);
	if (for_first(argv, dump) < 0)
		return (-1);
	begin = *argv;
	while (begin && begin->next)
	{
		if (ft_strequ(begin->next->name, "-v"))
		{
			if (begin->next->next == NULL)
				return (0);
			if (ft_isnum(begin->next->next->name) == 0)
				return (error(DUMPAV, -1));
			*dump = ft_atoi(begin->next->next->name);
			tmp = begin->next;
			begin->next = begin->next->next->next;
			free_verb_and_val(tmp);
		}
		else
			begin = begin->next;
	}
	return (0);
}	