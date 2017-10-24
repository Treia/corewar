/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:34:03 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/24 17:21:10 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		read_nb(char *arena, int addr, int size)
{
	int		tmp;

	tmp = 0;
	while (size > 0)
	{
		tmp = tmp << 8;
		tmp += (unsigned char)(arena[addr % MEM_SIZE]);
		addr++;
		size--;
	}
	return (tmp);
}
