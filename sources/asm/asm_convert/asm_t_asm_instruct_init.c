/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_asm_instruct_init.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:07:57 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/27 16:44:29 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static void		internal_asm_t_asm_instruct_get_op_code_2(t_asm_instruct 
					*asm_instruct, t_instruct *target)
{
	if (ft_strequ("lld", target->name))
		asm_instruct->op_code = 13;
	if (ft_strequ("lldi", target->name))
		asm_instruct->op_code = 14;
	if (ft_strequ("lfork", target->name))
		asm_instruct->op_code = 15;
	if (ft_strequ("aff", target->name))
		asm_instruct->op_code = 16;
}

static void		internal_asm_t_asm_instruct_get_op_code(t_asm_instruct 
					*asm_instruct, t_instruct *target)
{
	if (ft_strequ("live", target->name))
		asm_instruct->op_code = 1;
	if (ft_strequ("ld", target->name))
		asm_instruct->op_code = 2;
	if (ft_strequ("st", target->name))
		asm_instruct->op_code = 3;
	if (ft_strequ("add", target->name))
		asm_instruct->op_code = 4;
	if (ft_strequ("sub", target->name))
		asm_instruct->op_code = 5;
	if (ft_strequ("and", target->name))
		asm_instruct->op_code = 6;
	if (ft_strequ("or", target->name))
		asm_instruct->op_code = 7;
	if (ft_strequ("xor", target->name))
		asm_instruct->op_code = 8;
	if (ft_strequ("zjmp", target->name))
		asm_instruct->op_code = 9;
	if (ft_strequ("ldi", target->name))
		asm_instruct->op_code = 10;
	if (ft_strequ("sti", target->name))
		asm_instruct->op_code = 11;
	if (ft_strequ("fork", target->name))
		asm_instruct->op_code = 12;
	internal_asm_t_asm_instruct_get_op_code_2(asm_instruct, target);
}

/*
** void	asm_t_asm_instruct_byte_and_param_count(t_asm_instruct *asm_instruct,
**                                                             t_instruct *target)
** {
**     if (asm_instruct->op_code == 1 || asm_instruct->op_code == 9 ||
**                                     asm_instruct->op_code == 12 || asm_instruct->op_code == 15)
**         asm_instruct->byte_count = 1;
**     else
**         asm_instruct->byte_count = 2;
**     if (asm_instruct->op_code == 1 || asm_instruct->op_code == 2 || asm_instruct->op_code == 6 ||
**                 asm_instruct->op_code == 7 || asm_instruct->op_code == 8 || asm_instruct->op_code == 13)
**         asm_get_param_size(asm_instruct, target, 4);
**     else if (asm_instruct->op_code == 9 || asm_instruct->op_code == 10 || asm_instruct->op_code == 11 ||
**             asm_instruct->op_code == 12 || asm_instruct->op_code == 14 || asm_instruct->op_code == 15)
**         asm_get_param_size(asm_instruct, target, 2);
**     else
**         asm_get_param_size(asm_instruct, target, 0);
**     asm_instruct->byte_count += asm_instruct->param_size;
** }
*/

void	asm_t_asm_instruct_init(t_asm_instruct *asm_instruct,
								t_instruct *target, unsigned int current_byte)
{
	internal_asm_t_asm_instruct_get_op_code(asm_instruct, target);
	if (asm_instruct->op_code == 1 || asm_instruct->op_code == 9 ||
			asm_instruct->op_code == 12 || asm_instruct->op_code == 15)
		asm_instruct->param_code = 0;
	else
		asm_instruct->param_code = asm_get_param_code(target->param);
	/*
	** asm_t_asm_instruct_get_byte_and_param_count(asm_instruct, target);
	*/
	asm_instruct->starting_byte = current_byte;
}
