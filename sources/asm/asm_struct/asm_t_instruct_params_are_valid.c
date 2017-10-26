/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_instruct_param_is_valid.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:00:55 by mressier          #+#    #+#             */
/*   Updated: 2017/10/26 14:00:56 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static int		internal_get_param_code_from_type(t_param_type type)
{
	int		params_code[NB_PARAM_TYPE];

	if (type == INVALID_PARAM || type >= NB_PARAM_TYPE)
		return (0);
	params_code[REG_PARAM] = T_REG;
	params_code[DIR_PARAM] = T_DIR;
	params_code[INDIR_PARAM] = T_IND;
	return (params_code[type]);
}

static int		internal_one_param_is_valid(const char *param, int exp_param)
{
	int					param_code;
	t_param_type		param_type;

	if (param == NULL && exp_param == 0)
		return (EXIT_SUCCESS);
	if (param == NULL || exp_param == 0)
		return (EXIT_FAILURE);
	param_type = asm_get_param_type(param);
	param_code = internal_get_param_code_from_type(param_type);
	if (exp_param & param_code)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int				asm_t_instruct_params_are_valid(t_instruct *instruct)
{
	t_instruct_type		type;
	int					expect_params[PARAM_MAX];
	int					i;

	i = 0;
	type = asm_get_instruct_type(instruct->name);
	if (type == INVALID_INSTRUCT)
		return (print_error(EXIT_FAILURE, "Tu fais du caca (instruct)"));
	asm_get_expected_params(type, expect_params);
	while (i < PARAM_MAX)
	{
		if (internal_one_param_is_valid(instruct->param[i],
				expect_params[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
