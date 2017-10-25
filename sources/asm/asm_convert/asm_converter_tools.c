/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_converter_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:41:09 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/25 13:53:41 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

int		asm_identify_param_type(char *param)
{
	if (param[0] == 'r')
		return (T_REG);
	if (param[0] == '%' && param[1] == ':')
		return (T_DIR | T_LAB);
	if (param[0] == '%')
		return (T_DIR);
	if (param[0] == ':')
		return (T_IND | T_LAB);
	else
		return (T_IND);
}

void	asm_convert_int_param_to_bytes(char *param, char *dest, int size)
{
	int		to_conv;

	if (*param == '%')
		param++;
	to_conv = ft_atoi(param);
	if (size == 4)
	{
		dest[0] = (to_conv >> 24) & 0xFF;
		dest[1] = (to_conv >> 16) & 0xFF;
		dest[2] = (to_conv >> 8) & 0xFF;
		dest[3] = to_conv & 0xFF;
	}
	else
	{
		dest[0] = (to_conv >> 8) & 0xFF;
		dest[1] = to_conv & 0xFF;
	}
}

void	get_param_size(t_asm_instruct *new, t_instruct *target, int size)
{
	unsigned int	param_size;
	unsigned int	type;
	unsigned int	i;

	i = 0;
	while (target->param[i])
	{
		type = asm_identify_param_type(param[i])
		if (type == T_REG)
			param_size += 1;
		if (type == T_DIR)
			param_size += size;
		if (type == T_IND)
			param_size += 2;
		if (type == (T_DIR | T_LAB) || type == (T_DIR | T_IND))
			
		i++;
	}
}

void	get_asm_instruct_byte_and_param_count(t_asm_instruct *new, 
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

	return (byte_count);
}
