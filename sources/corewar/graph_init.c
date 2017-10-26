/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 17:56:17 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/26 17:13:09 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		init_color_set(void)
{
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, 107, COLOR_BLACK);
	init_pair(8, 208, COLOR_BLACK);
	init_pair(9, 238, COLOR_BLACK);
}

static void		print_header(t_game *game)
{
	wattron(game->display->head, COLOR_PAIR(5));
	mvwprintw(game->display->head, POS_HEAD_INFO, (POS_C_CYCLE - 9),
															"cycles : PAUSED");
	mvwprintw(game->display->head, POS_HEAD_INFO, (POS_C_NB_PC - 10),
															"process : ");
	set_process_data(game->nb_pc, game->display->head);
	mvwprintw(game->display->head, POS_HEAD_INFO, (POS_C_WINNER - 9),
															"winner : ");
	set_winner_data("In progress", game->display->head);
	mvwprintw(game->display->head, POS_HEAD_INFO, (POS_C_CYCLEDIE - 15),
															"cycle to die : ");
	set_cycle_to_die(CYCLE_TO_DIE, game->display->head);
	mvwprintw(game->display->head, POS_HEAD_INFO, (POS_C_MAX_CHECK - 8),
															"check : ");
	set_cycle_to_die(0, game->display->head);
	mvwprintw(game->display->head, POS_HEAD_INFO, (POS_C_SPEED - 8),
															"speed : ");
	set_speed(game->speed, game->display->head);
}

int				init_window(t_game *game)
{
	initscr();
	if (LINES < MAX_L || COLS < MAX_C)
	{
		error(TOOSMALL, 0);
		game->verb = 0;
		endwin();
		return (0);
	}
	start_color();
	game->display = init_display();
	noecho();
	curs_set(0);
	init_color_set();
	box(game->display->head, ACS_VLINE, ACS_HLINE);
	box(game->display->box, ACS_VLINE, ACS_HLINE);
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
