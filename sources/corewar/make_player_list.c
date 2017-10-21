/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_player_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 15:59:54 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/21 18:26:59 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	write_prog_in_arena(int index, int fd, t_game *game)
{
	char	buffer[CHAMP_MAX_SIZE];
	int		ret;

	if ((ret = read(fd, buffer, CHAMP_MAX_SIZE)) < 0)
		return (-1);
	ft_memcpy(&game->arena[index], buffer, CHAMP_MAX_SIZE);
	return (0);
}

t_player	*make_player(const char *file, int id, t_game *game, int index)
{
	t_header	*header;
	t_player	*player;
	char		buffer[HEADER_SIZE];
	int			ret;
	int			fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	if ((ret = read(fd, buffer, HEADER_SIZE)) < HEADER_SIZE)
		return (NULL);
	header = (t_header *)(buffer);
	if (header->magic != COREWAR_EXEC_MAGIC)
		return (NULL);
	player = new_player();
	ft_memcpy(player->comment, header->comment, COMMENT_LENGTH);
	ft_memcpy(player->name, header->prog_name, PROG_NAME_LENGTH);
	if (write_prog_in_arena(index, fd, game) < 0)
		return (NULL);
	player->live = id;
	close(fd);
	return (player);
}

t_player	*make_player_list(t_argvparse *argv, t_game *game, int interval)
{
	t_player	*players;
	t_player	*tmp;
	t_argvparse	*begin;
	int			index;

	index = 0;
	players = NULL;
	begin = argv;
	while (begin)
	{
		if ((tmp = make_player(begin->name, begin->id, game, index)) == NULL)
			return (NULL);
		add_in_player_list(&players, tmp);
		index = index + interval;
		begin = begin->next;
	}
	return (players);
}
