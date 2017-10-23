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

	nb_line = ft_count_char_with_limit(init_ptr, error_ptr, '\n');
	ptr = ft_memrchr(init_ptr, error_ptr, '\n');
	if (ptr == NULL)
		nb_char = 1;
	else
		nb_char = error_ptr - ptr;
	ft_strcat(error, "[");
	ptr = ft_itoa(nb_line + 1);
	ft_strcat(error, ptr);
	free(ptr);
	ft_strcat(error, ",");
	ptr = ft_itoa(nb_char);
	ft_strcat(error, ptr);
	free(ptr);
 	ft_strcat(error, "]");
}

static void	internal_add_problematic_word(const char *error_ptr, char *error)
{
	char	*end_error_ptr;
	char	*end_error_str;

	end_error_ptr = ft_str_first(error_ptr, ft_isspace);
	end_error_str = error + ft_strlen(error);
	ft_strncpy(error + ft_strlen(error), error_ptr, end_error_ptr - error_ptr);
}

int			asm_syntax_error(const char *init_ptr, const char *error_ptr,
				const char *message)
{
	char		error[MESSAGE_SIZE_MAX + 1];

	ft_bzero(error, MESSAGE_SIZE_MAX + 1);
	ft_strcpy(error, "SYNTAX ERROR: ");
	if (!error_ptr)
		ft_strcat(error, "\"[null]\"");
	else
		internal_get_line_and_char_error(init_ptr, error_ptr, error);
	if (message)
	{
		ft_strcat(error, " ");
		ft_strcat(error, message);
	}
	ft_strcat(error, " : \"");
	internal_add_problematic_word(error_ptr, error);
	ft_strcat(error, "\"");
	return (print_error(EXIT_FAILURE, error));
}
