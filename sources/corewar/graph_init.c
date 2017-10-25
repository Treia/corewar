/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 17:56:17 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/25 13:27:51 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		init_color_set(void)
{
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_BLACK, COLOR_CYAN);
	init_pair(8, COLOR_BLACK, COLOR_WHITE);
}

static void		print_header(t_game *game)
{
	wattron(game->display->head, COLOR_PAIR(2));
	mvwprintw(game->display->head, POS_HEAD_INFO, (POS_C_CYCLE - 9), "cycles : ");
	set_cycle_data(0, game->display->head);
	mvwprintw(game->display->head, POS_HEAD_INFO, (POS_C_NB_PC - 10), "process : ");
	set_process_data(game->nb_pc, game->display->head);
	mvwprintw(game->display->head, POS_HEAD_INFO, (POS_C_WINNER - 9), "winner : ");
	set_winner_data("In progress", game->display->head);
}

int				init_window(t_game *game)
{
	initscr();
	if (LINES < MAX_L || COLS < MAX_C)
	{
		game->verb = 0;
		endwin();
		return (0);
	}
	game->display = init_display();
	noecho();
	curs_set(0);
	box(game->display->head, ACS_VLINE, ACS_HLINE);
	box(game->display->box, ACS_VLINE, ACS_HLINE);
	init_color_set();
	print_header(game);
	print_arena_start(game);
	wrefresh(game->display->box);
	wrefresh(game->display->head);
	return (0);
}

int				clear_window(t_display *display)
{
	while (getch() != 27)
		;
	endwin();
	release_display(display);
	return (0);
}
