/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_end_cycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:12:56 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/25 17:38:57 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		display_end_cycle(t_game *game, t_cycle *cycle)
{
	set_cycle_data(cycle->current, game->display->head);
	set_process_data(game->nb_pc, game->display->head);
	set_cycle_to_die(cycle->to_die, game->display->head);
	set_max_check(cycle->nb_check, game->display->head);
	wrefresh(game->display->head);
	wrefresh(game->display->box);
}
