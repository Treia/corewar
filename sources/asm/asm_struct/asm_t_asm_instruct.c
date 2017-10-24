/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_t_asm_instruct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:19:51 by mressier          #+#    #+#             */
/*   Updated: 2017/10/24 14:19:53 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

t_asm_instruct		*asm_t_asm_instruct_new(void)
{
	t_asm_instruct	*new_asm_instruct;

	new_asm_instruct = (t_asm_instruct *)ft_memalloc(sizeof(t_asm_instruct));
	new_asm_instruct->op_code = 0;
	new_asm_instruct->param_code = 0;
	ft_bzero(new_asm_instruct->param, PARAM_MAX * 4);
	new_asm_instruct->param_size = 0;
	new_asm_instruct->byte_count = 0;
	new_asm_instruct->next = NULL;
	return (new_asm_instruct);
}

void				asm_t_asm_instruct_del(t_asm_instruct **asm_instruct)
{
	ft_memdel((void **)asm_instruct);
}

t_asm_instruct		*asm_t_asm_instruct_add_end(t_asm_instruct *list,
								t_asm_instruct *add)
{
	t_asm_instruct	*ptr;

	ptr = list;
	if (ptr == NULL)
		return (add);
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = add;
	return (list);
}
