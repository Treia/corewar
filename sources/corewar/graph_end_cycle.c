/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_end_cycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:12:56 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/25 16:43:13 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		display_end_cycle(t_game *game, int cycle, int cycle_to_die)
{
	set_cycle_data(cycle, game->display->head);
	set_process_data(game->nb_pc, game->display->head);
	set_cycle_to_die(cycle_to_die, game->display->head);
	wrefresh(game->display->head);
	wrefresh(game->display->box);
}
