/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_fill_part4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:41:43 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/24 17:42:20 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

void	fill_asm_instruct_sti(t_asm_instruct *new, t_instruct *target)
{
	new->op_code = 16;
	new->param_code = 0;
	new->param_size = 0;
	new->byte_count = 1;
	ft_bzero(new->param);
	asm_convert_params(new, target, 0);
}
