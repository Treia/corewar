/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_identify_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 10:19:45 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/23 11:12:57 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

t_asm_instruct	*asm_identify_op_2(t_instruct *target)
{
	if (ft_strequ("lld", target->name))
		return(create_asm_instruct(fill_asm_instruct_lld(target)));
	if (ft_strequ("lldi", target->name))
		return(create_asm_instruct(fill_asm_instruct_lldi(target)));
	if (ft_strequ("lfork", target->name))
		return(create_asm_instruct(fill_asm_instruct_lfork(target)));
	if (ft_strequ("add", target->name))
		return(create_asm_instruct(fill_asm_instruct_add(target)));
	return (NULL);
}

t_asm_instruct	*asm_identify_op(t_instruct *target)
{
	if (ft_strequ("live", target->name))
		return(create_asm_instruct(fill_asm_instruct_live(target)));
	if (ft_strequ("ld"))
		return(create_asm_instruct(fill_asm_instruct_ld(target)));
	if (ft_strequ("ld"))
		return(create_asm_instruct(fill_asm_instruct_st(target)));
	if (ft_strequ("add"))
		return(create_asm_instruct(fill_asm_instruct_add(target)));
	if (ft_strequ("sub"))
		return(create_asm_instruct(fill_asm_instruct_sub(target)));
	if (ft_strequ("and"))
		return(create_asm_instruct(fill_asm_instruct_and(target)));
	if (ft_strequ("or"))
		return(create_asm_instruct(fill_asm_instruct_or(target)));
	if (ft_strequ("xor"))
		return(create_asm_instruct(fill_asm_instruct_xor(target)));
	if (ft_strequ("zjmp"))
		return(create_asm_instruct(fill_asm_instruct_zjmp(target)));
	if (ft_strequ("ldi"))
		return(create_asm_instruct(fill_asm_instruct_ldi(target)));
	if (ft_strequ("sti"))
		return(create_asm_instruct(fill_asm_instruct_sti(target)));
	if (ft_strequ("fork"))
		return(create_asm_instruct(fill_asm_instruct_fork(target)));
	return (asm_identify_op_2(target));
}
