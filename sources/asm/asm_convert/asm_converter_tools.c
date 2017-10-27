/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_converter_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:41:09 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/27 15:27:27 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

unsigned int	asm_get_current_param_size(char *param, t_asm_instruct *new)
{
	unsigned int	size;

	if (param[0] == '%')
	{
		if (new->op_code == 1 || new->op_code == 2 || new->op_code == 6 ||
				new->op_code == 7 || new->op_code == 8 || new->op_code == 13)
			size = 4;
	}
	else
		size = 2;
	return (size);
}

void			asm_convert_char_param_to_bytes(char *param, char *dest,
																	int size)
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

void			asm_convert_label_address_to_bytes(int param, char *dest,
																	int size)
{
	if (size == 4)
	{
		dest[0] = (param >> 24) & 0xFF;
		dest[1] = (param >> 16) & 0xFF;
		dest[2] = (param >> 8) & 0xFF;
		dest[3] = param & 0xFF;
	}
	else
	{
		dest[0] = (param >> 8) & 0xFF;
		dest[1] = param & 0xFF;
	}
}

unsigned int	asm_t_asm_instruct_find_label(char *param, t_label *label_list)
{
	int		offset;

	offset = 1;
	if (param[1] == ':')
		offset = 2;
	while (label_list)
	{
		if (ft_strequ(param + offset, label_list->name))
			return (label_list->starting_byte);
		label_list = label_list->next;
	}
	return (-1);
}

void			asm_get_param_size(t_asm_instruct *new, t_instruct *target,
																	int size)
{
	unsigned int	param_size;
	unsigned int	type;
	unsigned int	i;

	i = 0;
	while (target->param[i])
	{
		type = asm_identify_param_type(target->param[i]);
		if (type == T_REG)
			param_size += 1;
		if (type == T_DIR)
			param_size += size;
		if (type == T_IND)
			param_size += 2;
		if (type == (T_DIR | T_LAB) || type == (T_IND | T_LAB))
			param_size += 2;
		i++;
	}
	new->param_size = param_size;
}
