/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 17:56:17 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/24 18:51:42 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		print_arena_start(t_game *game, t_display *display)
{
	int		index;

	index = 0;
	while (index < MEM_SIZE)
	{
		print_int(index, game, display);
		index += 4;
	}
}

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
	mvwprintw(display->head, POS_HEAD_INFO, (POS_C_CYCLE - 9), "cycles : ");
	set_cycle_data(0, display->head);
	mvwprintw(display->head, POS_HEAD_INFO, (POS_C_NB_PC - 10), "process : ");
	set_process_data(game->nb_pc, display->head);
	mvwprintw(display->head, POS_HEAD_INFO, (POS_C_WINNER - 9), "winner : ");
	set_winner_data("In progress", display->head);
	print_arena_start(game, display);
	wrefresh(display->box);
	wrefresh(display->head);
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
