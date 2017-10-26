/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:25:46 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/26 17:12:00 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			print_char(int index, t_game *game, int id)
{
	int		line;
	int		col;

	wattron(game->display->box, COLOR_PAIR(id));
	line = (index / NB_OCTET_DISPLAY) + 3;
	col = ((index % NB_OCTET_DISPLAY) * 3) + 2;
	mvwprintw(game->display->box, line, col, "%02x ",
									(unsigned char)game->arena[index]);
	wattroff(game->display->box, COLOR_PAIR(id));
}

void			print_int(int index, t_game *game, int id)
{
	int		line;
	int		col;
	int		octets;
	int		real_index;

	octets = 0;
	wattron(game->display->box, COLOR_PAIR(id));
	while (octets < 4)
	{
		real_index = ((index + octets) % MEM_SIZE);
		line = (real_index / NB_OCTET_DISPLAY) + 3;
		col = ((real_index % NB_OCTET_DISPLAY) * 3) + 2;
		mvwprintw(game->display->box, line, col, "%02x ",
									(unsigned char)game->arena[real_index]);
		octets++;
	}
	wattroff(game->display->box, COLOR_PAIR(id));
}
