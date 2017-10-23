/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_asm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:18:21 by mressier          #+#    #+#             */
/*   Updated: 2017/10/23 11:18:22 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

t_asm						*asm_t_asm_new(void)
{
	t_asm		*new_asm;

	new_asm = (t_asm *)ft_memalloc(sizeof(t_asm));
	return (new_asm);
}

int							asm_t_asm_init(t_asm *to_init)
{
	(void)to_init;
	return (EXIT_SUCCESS);
}

void						asm_t_asm_del(t_asm **to_del)
{
	ft_memdel((void **)to_del);
}
