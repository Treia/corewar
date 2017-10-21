/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 13:52:46 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/21 13:53:41 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnum(const char *str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		if (ft_isdigit(str[index]) != 1)
			return (0);
		index++;
	}
	return (1);
}
