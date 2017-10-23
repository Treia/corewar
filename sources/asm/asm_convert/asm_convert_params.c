/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_convert_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:54:55 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/23 18:42:26 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_convert_register(char *param, t_asm_instruct *new, int pos)
{
	char	reg;

	reg = (char)ft_atoi(param + 1);
	new->param[pos] = reg;
	new->byte_count += 1;
	new->param_size += 1;
	return (1);
}

int		asm_convert_dir(char *param, t_asm_instruct *new, int pos, int size)
{
	asm_convert_int_param_to_bytes(param, new->param + pos, size);
	new->byte_count += size;
	new->param_size += size;
	return (size);
}

int		asm_convert_ind(char *param, t_asm_instruct *new, int pos)
{
	asm_convert_int_param_to_bytes(param, new->param + pos, 2);
	new->byte_count += 2;
	new->param_size += 2;
	return (2);
}

int		asm_convert_label(char *param, t_asm_instruct *new, int type, int size)
{
	new->has_label = 1;
	if (type == (T_DIR | T_LAB))
	{
		new->byte_count += size;
		new->byte_count += size;
		return (size);
	}
	if (type == (T_IND | T_LAB))
	{
		new->byte_count += 2;
		new->param_size += 2;
		return (2);
	}
	return (0);
}

void	asm_convert_params(t_asm_instruct *new, t_instruct *target, int size)
{
	int		i;
	int		type;
	int		pos;
	
	i = 0;
	pos = 0;
	while (target->param[i])
	{
		type = asm_identify_param_type(target->param[i]);
		if (type == T_REG)
			pos += asm_convert_register(target->param[i], new, pos);
		if (type == T_DIR)
			pos += asm_convert_dir(target->param[i], new, pos, size);
		if (type == T_IND)
			pos += asm_convert_ind(target->param[i], new, pos);
		if (type == (T_DIR | T_LAB) || type == (T_DIR | T_IND))
			pos += asm_convert_label(target->param[i], new, type, size);
		i++;
	}
}
