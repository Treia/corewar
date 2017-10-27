/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_asm_instruct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 10:33:34 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/27 07:46:22 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

t_asm_instruct		*asm_t_asm_instruct_new(t_instruct *target,
													unsigned int current_byte)
{
	t_asm_instruct	*new;

	new = (t_asm_instruct *)ft_memalloc(sizeof(t_asm_instruct));
	ft_bzero(new->param, PARAM_MAX * 4);
	new->starting_byte = current_byte;
	new->next = NULL;
	return (new);
}

void				asm_t_asm_instruct_del(t_asm_instruct **instruct)
{
	if (instruct && *instruct)
		ft_memdel((void **)instruct);
}

void				asm_t_asm_instruct_del_list(t_asm_instruct *list)
{
	t_asm_instruct *ptr;

	if (list)
	{
		ptr = list;
		if (ptr->next)
			asm_t_asm_instruct_del_list(ptr->next);
		asm_t_asm_instruct_del(&list);
	}
}

void				asm_t_asm_instruct_add_to_end(t_label *label,
															t_asm_instruct *new)
{
	t_asm_instruct	*tmp;

	tmp = label->asm_instruct_list;
	while (tmp)
		tmp = tmp->next;
	tmp = new;
}

int					asm_t_asm_instruct_init_list(t_asm *asm_file_content)
{
	t_label				*label;
	t_instruct			*instruct;
	t_asm_instruct		*new;
	unsigned int		current_byte;

	label = asm_file_content->label_list;
	current_byte = 0;
	while (label)
	{
		label->starting_byte = current_byte;
		instruct = label->instruc_list;
		while (instruct)
		{
			new = asm_t_asm_instruct_new(instruct, current_byte);
			asm_t_asm_instruct_init(new, instruct, current_byte);
			asm_t_asm_instruct_add_to_end(label, new);
			current_byte = new->starting_byte;
			instruct = instruct->next;
		}
		label = label->next;
	}
}
