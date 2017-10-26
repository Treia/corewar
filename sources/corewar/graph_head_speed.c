/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_head_speed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:52:36 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/26 16:00:32 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		set_speed(unsigned int speed, WINDOW *box)
{
	mvwprintw(box, POS_HEAD_INFO, POS_C_SPEED, "%d    ", speed);
}