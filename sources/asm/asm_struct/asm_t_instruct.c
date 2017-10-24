/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_instruct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:19:48 by mressier          #+#    #+#             */
/*   Updated: 2017/10/24 14:19:50 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

t_instruct		*asm_t_instruct_new(void)
{
	t_instruct	*new_instruct;

	new_instruct = (t_instruct *)ft_memalloc(sizeof(t_instruct));
	ft_bzero(new_instruct->name, INSTRUCT_LENGTH_MAX + 1);
	asm_t_instruct_param_init(new_instruct->param);
	new_instruct->next = NULL;
	return (new_instruct);
}

void			asm_t_instruct_del(t_instruct **instruct)
{
	t_instruct	*ptr;

	if (instruct && *instruct)
	{
		ptr = *instruct;
		asm_t_instruct_param_del(ptr->param);
		ft_memdel((void **)instruct);
	}
}

t_instruct		*asm_t_instruct_add_end(t_instruct *list, t_instruct *add)
{
	t_instruct	*ptr;

	ptr = list;
	if (ptr == NULL)
		return (add);
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = add;
	return (list);
}
