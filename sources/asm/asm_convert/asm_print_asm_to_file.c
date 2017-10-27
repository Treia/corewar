/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_print_asm_to_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:03:02 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/27 15:36:50 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static char	*internal_get_recipient_filename(char *original_filename)
{
	char	*result;
	int		i;

	while (original_filename[i])
		i++;
	while (original_filename[i] != '.')
		i--;
	result = (char *)ft_memalloc(sizeof(char *) * i + 4);
	ft_strncpy(result, original_filename, i);
	ft_strcat(result, ".cor");
	return (result);
}

static int	internal_create_recipient_file(char *original_filename)
{
	int		fd;
	char	*filename;

	filename = internal_get_recipient_filename(original_filename);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	ft_memdel((void **)&filename);
	return (fd);
}

int			asm_print_asm_to_file(t_asm *asm_file_content, char *original_filename)
{
	int		fd;

	if ((fd = internal_create_recipient_file(original_filename)) == -1)
		return (EXIT_FAILURE);
	asm_write_header_to_file(asm_file_content, fd);
	asm_write_t_asm_instruct_list_to_file(asm_file_content->label_list, fd);
}
