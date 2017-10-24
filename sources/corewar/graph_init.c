/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 17:56:17 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/24 17:16:02 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_display		*init_window(t_display *display, t_game *game)
{
	initscr();
	if (LINES < MAX_L || COLS < MAX_C)
	{
		game->verb = 0;
		endwin();
		return (NULL);
	}
	display = init_display();
	noecho();
	curs_set(0);
	box(display->head, ACS_VLINE, ACS_HLINE);
	box(display->box, ACS_VLINE, ACS_HLINE);
	mvwprintw(display->box, POS_HEAD_INFO, (POS_C_CYCLE - 9), "cycles : ");
	set_cycle_data(0, display->box);
	mvwprintw(display->box, POS_HEAD_INFO, (POS_C_NB_PC - 10), "process : ");
	set_cycle_data(game->nb_pc, display->box);
	mvwprintw(display->box, POS_HEAD_INFO, (POS_C_WINNER - 9), "winner : ");
	set_winner_data("In progress", display->box);
	wrefresh(display->box);
	return (display);
}

int				clear_window(t_display *display)
{
	while (getch() != 27)
		;
	endwin();
	release_display(display);
	return (0);
}
