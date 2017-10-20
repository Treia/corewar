/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:44:13 by mressier          #+#    #+#             */
/*   Updated: 2017/10/20 15:44:22 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"

# include <stdlib.h>

# define LABEL_LENGTH_MAX		128
# define INSTRUCT_LENGTH_MAX 	5
# define PARAM_MAX				3

/*
** ASM_INSTRUCT
*/

typedef struct				s_asm_instruct
{
	char					op_code;
	char					param_code;

	char					param[PARAM_MAX * 4];
	unsigned int			param_size;

	unsigned int			byte_count; // fonction calcul taille -> sizeof(char) * 2 + param_size

	struct s_asm_instruct	*next;
}							t_asm_instruct;

/*
** INSTRUCT
*/

typedef struct				s_instruct
{
	char					name[INSTRUCT_LENGTH_MAX + 1];
	char					*param[PARAM_MAX];
	struct s_instruct		*next;
}							t_instruct;

/*
** LABEL
*/

typedef struct				s_label
{
	char					name[LABEL_LENGTH_MAX];
	t_instruct				*instruc_list;
	t_asm_instruct			*asm_instruct_list;
	struct s_label			*next;
}							t_label;

/*
** ASM
*/

typedef struct				s_asm
{
	t_header				header;
	t_label					*label_list;
}							t_asm;

/* CORE */

int							asm_usage(void);

/* READDER */

int							asm_read_file(const char *filename,
								char **out_content, int *size);



/* STRUCTS */

t_asm						*asm_t_asm_new(void);
int							asm_t_asm_init();
void						asm_t_asm_del(t_asm **to_del);

t_label						*asm_t_label_new(void);
int							asm_t_label_init();
void						asm_t_label_del(t_label **label);

t_instruct					*asm_t_instruct_new(void);
int							asm_t_instruct_init();
void						asm_t_instruct_del(t_instruct **instruct);

t_asm_instruct				*asm_t_asm_instruct_new(void);
int							asm_t_asm_instruct_init();
void						asm_t_asm_instruct_del(t_asm_instruct **asm_instruct);

#endif
