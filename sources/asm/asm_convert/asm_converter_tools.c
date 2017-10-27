/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_converter_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:41:09 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/27 07:48:36 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

int				asm_identify_param_type(char *param)
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

void			asm_convert_int_param_to_bytes(char *param, char *dest,
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
