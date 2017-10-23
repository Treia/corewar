/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_not.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 13:45:05 by mressier          #+#    #+#             */
/*   Updated: 2017/10/23 13:45:07 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 	*ft_str_first_not(const char *str, int (*ft_is)(int))
{
	char	*ptr;

	ptr = (char *)str;
	while (ptr && *ptr && ft_is(*ptr))
		ptr++;
	return (ptr);
}
