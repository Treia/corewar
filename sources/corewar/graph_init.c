/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 17:56:17 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/24 13:25:08 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				init_window(WINDOW *box)
{
	initscr();
	box = subwin(stdscr, LINES, COLS, 0, 0);
	box(box, ACS_VLINE, ACS_HLINE);
	wrefresh(box);
	return (0);
}

int				clear_window(WINDOW *box)
{
	getch();
	endwin();
	free(box);
	return (0);
}
