/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:25:46 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/24 18:52:46 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			print_int(int index, t_game *game, t_display *display)
{
	int		line;
	int		col;
	int		octets;
	int		real_index;

	octets = 0;
	while (octets < 4)
	{
		real_index = ((index + octets) % MEM_SIZE);
		line = (real_index / NB_OCTET_DISPLAY) + 3;
		col = ((real_index % NB_OCTET_DISPLAY) * 3) + 2;
		printf("%02x ", game->arena[real_index]);
		mvwprintw(display->box, line, col, "%02x ",
									(unsigned char)game->arena[real_index]);
		octets++;
	}
}
