/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 19:28:25 by mressier          #+#    #+#             */
/*   Updated: 2017/01/17 19:08:05 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** ft_count_char.c
**
** Give the number of occurence of the character c in the string str
**
** @param		str
** @param		c
**
** @error str is NULL
**
** @return 0 if null or there is no c in str, else the number of occurence of c
*/

int				ft_count_char(const char *str, int c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			n++;
		i++;
	}
	return (n);
}
