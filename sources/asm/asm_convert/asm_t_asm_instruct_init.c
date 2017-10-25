/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_asm_instruct_init.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:07:57 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/25 20:46:34 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	asm_t_asm_instruct_get_op_code_2(t_asm_instruct *new,
															t_instruct *target)
{
	if (ft_strequ("lld", target->name))
		new->op_code = 13;
	if (ft_strequ("lldi", target->name))
		new->op_code = 14;
	if (ft_strequ("lfork", target->name))
		new->op_code = 15;
	if (ft_strequ("aff", target->name))
		new->op_code = 16;
}

void	asm_t_asm_instruct_get_op_code(t_asm_instruct *new, t_instruct *target)
{
	if (ft_strequ("live", target->name))
		new->op_code = 1;
	if (ft_strequ("ld", target->name))
		new->op_code = 2;
	if (ft_strequ("st", target->name))
		new->op_code = 3;
	if (ft_strequ("add", target->name))
		new->op_code = 4;
	if (ft_strequ("sub", target->name))
		new->op_code = 5;
	if (ft_strequ("and", target->name))
		new->op_code = 6;
	if (ft_strequ("or", target->name))
		new->op_code = 7;
	if (ft_strequ("xor", target->name))
		new->op_code = 8;
	if (ft_strequ("zjmp", target->name))
		new->op_code = 9;
	if (ft_strequ("ldi", target->name))
		new->op_code = 10;
	if (ft_strequ("sti", target->name))
		new->op_code = 11;
	if (ft_strequ("fork", target->name))
		new->op_code = 12;
	asm_t_asm_instruct_get_op_code_2(new, target);
}

void	asm_t_asm_instruct_byte_and_param_count(t_asm_instruct *new,
															t_instruct *target)
{
	if (new->op_code == 1 || new->op_code == 9 ||
									new->op_code == 12 || new->op_code == 15)
		new->byte_count = 1;
	else
		new->byte_count = 2;
	if (new->op_code == 1 || new->op_code == 2 || new->op_code == 6 ||
				new->op_code == 7 || new->op_code == 8 || new->op_code == 13)
		get_param_size(new, target, 4);
	else if (new->op_code == 9 || new->op_code == 10 || new->op_code == 11 ||
			new->op_code == 12 || new->op_code == 14 || new->op_code == 15)
		get_param_size(new, target, 2);
	else
		get_param_size(new, target, 0);
	new->byte_count += new->param_size;
}

void	asm_t_asm_instruct_init_from_t_instruct(t_asm_instruct *new, 
															t_instruct *target)
{
	asm_t_asm_instruct_get_op_code(new, target);
	if (new->op_code == 1 || new->op_code == 9 ||
			new->op_code == 12 || new->op_code == 15)
		new->param_code = 0;
	else
		new->param_code = asm_get_param_code(target->param);
	asm_t_asm_instruct_get_byte_and_param_count(new, target);
}
