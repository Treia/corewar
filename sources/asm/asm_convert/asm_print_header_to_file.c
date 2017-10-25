/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_print_header_to_file.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:49:05 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/25 19:11:24 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		internal_swap_endian(int data)
{
	return((data << 24) | ((data << 8) & 0x00FF) |
									((data >> 8) & 0x0000FF) | (data >> 24));
}

void			asm_print_header_to_file(t_asm *asm_file_content, int fd)
{
	t_header *header;

	header = &asm_file_content->header;
	internal_swap_endian(header->magic);
	internal_swap_endian(header->prog_size);
	write(fd, header, sizeof(t_header));
}
