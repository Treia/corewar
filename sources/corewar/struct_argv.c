/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 18:43:42 by mdezitte          #+#    #+#             */
/*   Updated: 2017/10/20 20:00:02 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			free_item_argvparse(t_argvparse *argvparse)
{
	if (argvparse->name != NULL)
		ft_memdel((void *)&argvparse->name);
	ft_memdel((void *)&argvparse);
}

void			add_in_argvparse_list(t_argvparse **argvparse,
											t_argvparse *to_add)
{
	t_argvparse *begin;

	if (!argvparse || !to_add)
		return ;
	else if (!*argvparse)
		*argvparse = to_add;
	else
	{
		begin = *argvparse;
		while (begin->next)
			begin = begin->next;
		begin->next = to_add;
	}
}

void			release_argvparse(t_argvparse **argvparse)
{
	if (!argvparse || !*argvparse)
		return ;
	release_argvparse(&((*argvparse)->next));
	free_item_argvparse(*argvparse);
}

t_argvparse		*new_argvparse(void)
{
	t_argvparse	*ret;

	if ((ret = (t_argvparse *)malloc(sizeof(t_argvparse))) == NULL)
		return (NULL);
	ret->name = NULL;
	ret->id = 0;
	ret->next = NULL;
	return (ret);
}
