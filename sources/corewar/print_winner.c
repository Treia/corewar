/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_winner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 17:20:33 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/24 13:34:31 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		nb_winner(t_game *game)
{
	int			nb;
	t_player	*tmp;

	nb = 0;
	tmp = game->players;
	while (tmp != 0)
	{
		if (tmp->live == game->winner)
			nb++;
		tmp = tmp->next;
	}
	return (nb);
}

void	print_player(t_game *game, int nb)
{
	int			i;
	t_player	*tmp;

	i = 0;
	tmp = game->players;
	while (tmp != 0)
	{
		if (tmp->live == game->winner)
		{
			i++;
			ft_putstr(tmp->name);
			if (i == nb)
				ft_putstr(" !\n");
			else if (i == nb - 1)
				ft_putstr(" & ");
			else
				ft_putstr(", ");
		}
		tmp = tmp->next;
	}
}

void	print_winner(t_game *game)
{
	int		nb;

	if (game->verb != -1)
	{
		nb = nb_winner(game);
		if (nb > 1)
			ft_putstr("And the winners are ");
		else
			ft_putstr("And the winner is ");
		print_player(game, nb);
	}
}
