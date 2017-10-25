/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_instruct_param.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:32:37 by mressier          #+#    #+#             */
/*   Updated: 2017/10/24 14:32:38 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

void		asm_t_instruct_param_init(char **params)
{
	int			i;

	i = 0;
	while (i < PARAM_MAX)
	{
		params[i] = NULL;
		i++;
	}
}

void		asm_t_instruct_param_del(char **params)
{
	int			i;

	i = 0;
	while (i < PARAM_MAX)
	{
		free(params[i]);
		params[i] = NULL;
		i++;
	}
}

int			asm_t_instrict_param_add_end(char **param, char *new_param)
{
	int		i;

	i = 0;
	while (i < PARAM_MAX)
	{
		if (param[i] == NULL)
		{
			param[i] = new_param;
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_FAILURE);
}

void		asm_t_instruct_param_display(char **params, int tab)
{
	int		i;

	i = 0;
	while (i < PARAM_MAX)
	{
		ft_putnchar(tab, '\t');
		ft_putchar('[');
		ft_putnbr(i);
		ft_putstr("] : ");
		if (params[i])
			ft_putendl(params[i]);
		else
			ft_putendl("(null)");
		i++;
	}
}
