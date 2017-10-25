/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_fill_part2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:01:38 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/24 17:33:39 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

void	fill_asm_instruct_and(t_asm_instruct *new, t_instruct *target)
{
	new->op_code = 6;
	new->param_code = asm_get_param_code(target->param);
	new->param_size = 0;
	new->byte_count = 2;
	ft_bzero(new->param);
	asm_convert_params(new, target, 4);
}

void	fill_asm_instruct_or(t_asm_instruct *new, t_instruct *target)
{
	new->op_code = 7;
	new->param_code = asm_get_param_code(target->param);
	new->param_size = 0;
	new->byte_count = 2;
	ft_bzero(new->param);
	asm_convert_params(new, target, 4);
}

void	fill_asm_instruct_xor(t_asm_instruct *new, t_instruct *target)
{
	new->op_code = 8;
	new->param_code = asm_get_param_code(target->param);
	new->param_size = 0;
	new->byte_count = 2;
	ft_bzero(new->param);
	asm_convert_params(new, target, 4);
}

void	fill_asm_instruct_zjmp(t_asm_instruct *new, t_instruct *target)
{
	new->op_code = 9;
	new->param_code = 0;
	new->param_size = 0;
	new->byte_count = 1;
	ft_bzero(new->param);
	asm_convert_params(new, target, 2);
}

void	fill_asm_instruct_ldi(t_asm_instruct *new, t_instruct *target)
{
	new->op_code = 10;
	new->param_code = asm_get_param_code(target->param);
	new->param_size = 0;
	new->byte_count = 2;
	ft_bzero(new->param);
	asm_convert_params(new, target, 2);
}
