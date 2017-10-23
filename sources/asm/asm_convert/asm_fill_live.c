/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_fill_live.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:11:24 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/23 11:33:42 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	fill_asm_instruct(t_asm_instruct *new, t_instruct *target)
{
	new->op_code = 1;
	new->param_code = 0;
	new->param_size = 0;
	get_param(new, T_DIR, 4);
	new->byte_count = 5;
}
