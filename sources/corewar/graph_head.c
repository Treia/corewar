/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:56:07 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/25 16:37:37 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		set_cycle_data(unsigned int cycles, WINDOW *box)
{
	mvwprintw(box, POS_HEAD_INFO, POS_C_CYCLE, "%d      ", cycles);
}

void		set_process_data(unsigned int process, WINDOW *box)
{
	mvwprintw(box, POS_HEAD_INFO, POS_C_NB_PC, "%d      ", process);
}

void		set_winner_data(const char *str, WINDOW *box)
{
	mvwprintw(box, POS_HEAD_INFO, POS_C_WINNER, "%s              ", str);
}

void		set_cycle_to_die(unsigned int cycle_die, WINDOW *box)
{
	mvwprintw(box, POS_HEAD_INFO, POS_C_CYCLEDIE, "%d      ", cycle_die);
}
