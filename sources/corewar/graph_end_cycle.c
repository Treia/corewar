/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_end_cycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:12:56 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/25 16:24:08 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		display_end_cycle(t_game *game, int cycle)
{
	set_cycle_data(cycle, game->display->head);
	set_process_data(game->nb_pc, game->display->head);
	wrefresh(game->display->head);
	wrefresh(game->display->box);
}
