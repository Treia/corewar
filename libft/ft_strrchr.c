/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <mressier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 12:08:13 by mressier          #+#    #+#             */
/*   Updated: 2016/01/21 11:14:30 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Search the last occurence of the char c in the string s.
**	It return a pointer on it, or NULL if it's not int the string
*/

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
