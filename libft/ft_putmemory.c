/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmemory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 19:07:40 by mressier          #+#    #+#             */
/*   Updated: 2017/10/20 19:07:41 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmemory(void *mem, size_t size)
{
	size_t	i = 0;
	char	*ptr;

	ptr = mem;
	while (i < size)
	{
		ft_putchar(ptr[i]);
		i++;
	}
}
