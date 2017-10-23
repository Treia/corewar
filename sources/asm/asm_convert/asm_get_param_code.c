/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_param_code.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:45:29 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/23 17:22:13 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			asm_param_type(char *param)
{
	if (param[0] == 'r')
		return (REG_CODE);
	if (param[0] == '%')
		return (DIR_CODE);
	else
		return (IND_CODE);
}

char		asm_get_param_code(char **params)
{
	char	param_code;

	param_code = asm_param_type(params[0]) << 6;
	if (params[1])
		param_code += asm_param_type(params[1]) << 4;
	if (params[2])
		param_code += asm_param_type(params[2]) << 2;

	return (param_code);
}
