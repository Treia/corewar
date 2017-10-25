/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_asm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 13:39:58 by mressier          #+#    #+#             */
/*   Updated: 2017/10/25 13:39:59 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

void		asm_t_asm_display(t_asm asm_content)
{
	ft_putendl(asm_content.header.prog_name);
	ft_putendl(asm_content.header.comment);
	asm_t_label_display_list(asm_content.label_list);
}

void		asm_t_asm_del_content(t_asm asm_content)
{
	asm_t_label_del(&(asm_content.label_list));
}

