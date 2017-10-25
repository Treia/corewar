/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_fill_part3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:34:03 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/24 17:41:33 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

void	fill_asm_instruct_sti(t_asm_instruct *new, t_instruct *target)
{
	new->op_code = 11;
	new->param_code = asm_get_param_code(target->param);
	new->param_size = 0;
	new->byte_count = 2;
	ft_bzero(new->param);
	asm_convert_params(new, target, 2);
}

void	fill_asm_instruct_fork(t_asm_instruct *new, t_instruct *target)
{
	new->op_code = 12;
	new->param_code = 0;
	new->param_size = 0;
	new->byte_count = 1;
	ft_bzero(new->param);
	asm_convert_params(new, target, 2);
}

void	fill_asm_instruct_lld(t_asm_instruct *new, t_instruct *target)
{
	new->op_code = 13;
	new->param_code = asm_get_param_code(target->param);
	new->param_size = 0;
	new->byte_count = 2;
	ft_bzero(new->param);
	asm_convert_params(new, target, 4);
}

void	fill_asm_instruct_lldi(t_asm_instruct *new, t_instruct *target)
{
	new->op_code = 14;
	new->param_code = asm_get_param_code(target->param);
	new->param_size = 0;
	new->byte_count = 2;
	ft_bzero(new->param);
	asm_convert_params(new, target, 2);
}

void	fill_asm_instruct_lfork(t_asm_instruct *new, t_instruct *target)
{
	new->op_code = 15;
	new->param_code = 0;
	new->param_size = 0;
	new->byte_count = 1;
	ft_bzero(new->param);
	asm_convert_params(new, target, 2);
}
