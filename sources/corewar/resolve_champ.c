/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 14:16:58 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/23 14:42:10 by mdezitte         ###   ########.fr       */
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
	ft_strcat(error, " is not a champion...");
	return (print_error(ret, error));
}

static int		is_champ(const char *name)
{
	char		**tmp;
	int			ret;

	tmp = ft_strsplit(name, '.');
	if (tmp == NULL)
		return (-1);
	ret = ft_len_tab(tmp);
	if (ret < 2)
	{
		ft_memtabdel((void *)&tmp);
		return (-1);
	}
	if (ft_strequ(tmp[ret - 1], "cor"))
	{
		ft_memtabdel((void *)&tmp);
		return (1);
	}
	ft_memtabdel((void *)&tmp);
	return (-1);
}

int				check_is_correct_champ(t_argvparse *argv, t_game *game)
{
	t_argvparse *begin;
	int			nb;
	int			id;

	id = -1;
	begin = argv;
	nb = 0;
	while (begin)
	{
		if (is_champ(begin->name) < 0)
			return (bad_name(begin->name, -1));
		if (begin->id == -999)
		{
			while (check_if_id_use(id, argv))
				id--;
			begin->id = id;
		}
		game->winner = begin->id;
		begin = begin->next;
		nb++;
	}
	if (nb > MAX_PLAYERS)
		return (error(TOO_MANY_CHAMP, -1));
	if (nb == 0)
		return (error(NO_CHAMP, -1));
	return (0);
}
