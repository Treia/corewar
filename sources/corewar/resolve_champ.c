/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 14:16:58 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/21 14:39:19 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		bad_name(const char *name, int ret)
{
	char		error[256];

	if (ft_strlen(name) > 160)
		return (ret);
	ft_strcpy(error, "ARGUMENT : ");
	ft_strcat(error, name);
	ft_strcat(error, "is not a champion...");
	return (print_error(ret, error));
}

static int 		is_champ(const char *name)
{
	char		**tmp;
	int			ret;

	tmp = ft_strsplit(name, '.');
	if (tmp == NULL)
		return (-1);
	ret = ft_len_tab(tmp);
	if (ret < 2)
		return (-1);
	if (ft_strequ(tmp[ret - 1], "cor"))
		return (1);
	return (-1);
}

int				check_is_correct_champ(t_argvparse *argv)
{
	t_argvparse *begin;

	begin = argv;
	while (argv)
	{
		if (is_champ(argv->name) < 0)
			return (bad_name(argv->name, -1));
	}
	return (0);
}