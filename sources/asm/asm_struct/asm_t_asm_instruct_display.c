/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_asm_instruct_display.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 04:02:25 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/29 04:59:47 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "stdio.h"

void	to_delete(t_asm_instruct *list, int tab)
{
	int i;

	i = 0;
	ft_putnchar(tab, '\t');
	while (i < list->param_size)
		printf("%02x", list->param[i++]);
}

void	asm_t_asm_instruct_display_list(t_asm_instruct *list, int tab)
{
	t_asm_instruct	*ptr;
	int			i;

	ptr = list;
	i = 0;
	while (ptr)
	{
		ft_putnchar(tab, '\t');
		ft_putstr("instruct (");
		ft_putnbr(i);
		ft_putstr(") | op_code = ");
		ft_putnbr(ptr->op_code);
		ft_putstr(" | (");
		ft_putnbr(ptr->starting_byte);
		ft_putendl(")");
		ft_putnchar(tab + 1, '\t');
		ft_putstr("encoding byte = ");
		ft_putnbr(ptr->param_code);
		ft_putchar('\n');
		ft_putnchar(tab + 1, '\t');
		ft_putstr("param_size = ");
		ft_putnbr(ptr->param_size);
		ft_putchar('\n');
		to_delete(ptr, tab + 1);
		ft_putchar('\n');
		ptr = ptr->next;
		i++;
	}
}
