/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_fill_part1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:11:24 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/24 17:30:20 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

void	fill_asm_instruct_live(t_asm_instruct *new, t_instruct *target)
{
	new->op_code = 1;
	new->param_code = 0;
	new->param_size = 0;
	new->byte_count = 1;
	ft_bzero(new->param);
	asm_convert_params(new, target, 4);
}

void	fill_asm_instruct_ld(t_asm_instruct *new, t_instruct *target)
{
	new->op_code = 2;
	new->param_code = asm_get_param_code(target->param);
	new->param_size = 0;
	new->byte_count = 2;
	ft_bzero(new->param);
	asm_convert_params(new, target, 4);
}

void	fill_asm_instruct_st(t_asm_instruct *new, t_instruct *target)
{
	new->op_code = 3;
	new->param_code = asm_get_param_code(target->param);
	new->param_size = 0;
	new->byte_count = 2;
	ft_bzero(new->param);
	asm_convert_params(new, target, 0);
}

void	fill_asm_instruct_add(t_asm_instruct *new, t_instruct *target)
{
	new->op_code = 4;
	new->param_code = asm_get_param_code(target->param);
	new->param_size = 0;
	new->byte_count = 2;
	ft_bzero(new->param);
	asm_convert_params(new, target, 0);
}

void	fill_asm_instruct_sub(t_asm_instruct *new, t_instruct *target)
{
	new->op_code = 4;
	new->param_code = asm_get_param_code(target->param);
	new->param_size = 0;
	new->byte_count = 2;
	ft_bzero(new->param);
	asm_convert_params(new, target, 4);
}
