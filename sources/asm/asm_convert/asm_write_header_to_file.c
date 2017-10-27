/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_print_header_to_file.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:49:05 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/27 16:52:08 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

/*
** static int		internal_swap_endian(int data)
** {
**     return((data << 24) | ((data << 8) & 0x00FF) |
**                                     ((data >> 8) & 0x0000FF) | (data >> 24));
** }
*/

void			asm_write_header_to_file(t_asm *asm_file_content, int fd)
{
	t_header *header;

	header = &asm_file_content->header;
	swap_byte_32(header->magic);
	swap_byte_32(header->prog_size);
	write(fd, header, sizeof(t_header));
}
