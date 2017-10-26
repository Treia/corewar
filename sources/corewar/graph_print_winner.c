/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_print_winner.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:59:14 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/26 12:51:09 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		finish_string(char *str)
{
	int		index;

	index = 0;
	while (str[index] && index < 40)
		index++;
	if (index == 40)
		str[index] = '\0';
	else
	{
		while (index < 40)
		{
			str[index] = ' ';
			index++;
		}
		str[index] = '\0';
	}
}

static int 		get_win(t_game *game, char *buff)
{
	int			nb;
	t_player	*begin;

	nb = 0;
	begin = game->players;
	while (begin)
	{
		if (begin->live == game->winner)
		{
			if (nb == 0)
				ft_strcpy(buff, begin->name);
			else
			{
				ft_strcat(buff, " and ");
				ft_strcat(buff, begin->name);
			}
			nb++;
		}
		begin = begin->next;
	}
	return (nb);
}

void			graph_print_winner(t_game *game)
{
	char		buff[256];

	ft_bzero(buff, 256);
	if (get_win(game, buff) == 0)
		set_winner_data("No winner at the moment", game->display->head);
	else
	{
		finish_string(buff);
		set_winner_data(buff, game->display->head);
	}
	wrefresh(game->display->head);
}
