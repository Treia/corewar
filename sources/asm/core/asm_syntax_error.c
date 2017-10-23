/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_syntax_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:21:36 by mressier          #+#    #+#             */
/*   Updated: 2017/10/23 14:21:37 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

# define MESSAGE_SIZE_MAX 1024
# define DETAILS_LINE_SIZE_MAX 255

static void	internal_get_line_and_char_error(const char *init_ptr,
				const char *error_ptr, char *error)
{
	int		nb_line;
	int		nb_char;
	char	*ptr;

	ft_bzero(error, DETAILS_LINE_SIZE_MAX + 1);
	ptr = ft_strrchr(error_ptr, '\n');
	if (ptr == NULL)
		ptr = (char *)error_ptr;
	else
		ptr++;
	nb_char = error_ptr - ptr;
	nb_line = ft_count_char(init_ptr, '\n');
	ft_strcpy(error, "[");
	// ptr = itoa(nb_line);
	// ft_strcat(error, ptr);
	// free(ptr);
	// ft_strcat(error, ",");
	// ptr = itoa(nb_char);
	// ft_strcat(error, ptr);
	// free(ptr);
 	ft_strcat(error, "]");
}

int			asm_syntax_error(const char *init_ptr, const char *error_ptr)
{
	char		error[MESSAGE_SIZE_MAX + 1];

	ft_bzero(error, MESSAGE_SIZE_MAX + 1);
	ft_strcpy(error, "SYNTAX ERROR: ");

	if (!error_ptr || *error_ptr == '\0')
		ft_strcat(error, "\"(null)\"");
	else
	{
		internal_get_line_and_char_error(init_ptr, error_ptr, error);
	}
	return (print_error(EXIT_FAILURE, error));
}
