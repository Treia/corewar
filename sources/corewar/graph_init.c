/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 17:56:17 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/23 18:50:23 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			resize_handler(int sig)
{
	printw("Hello resize");
	refresh();
	(void)sig;
}

int				init_window(void)
{
	signal(SIGWINCH, resize_handler);
	initscr();
	noecho();
	printw("Corewar");
	refresh();
	return (0);
}

int				clear_window(void)
{
	getch();
	endwin();
	return (0);
}
