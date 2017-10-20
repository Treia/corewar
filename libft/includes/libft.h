/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 18:09:19 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/10/20 18:33:10 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 512
# define FD_MAX 100
/*
** Error
*/
# define SYNTAX 100
# define EMPTYARGV 101
# define DUMPAV 102

# define SYSTEM 200

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strcmp(const char *s1, const char *s2);

void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char const *s);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);

void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memjoin(const void *p1, size_t s1, const void *p2, size_t s2);
void	ft_memdel(void **ap);
void	ft_putmemory(void *mem, size_t size);

int		ft_strequ(char const *s1, char const *s2);
char	*ft_strtrim(char const *str);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strcat(char *s1, const char *s2);

int		get_next_line(const int fd, char **line);
int		ft_read_file(int fd, char **out_content);
int		ft_read_file_with_filename(const char *filename,
				char **out_content);


void	ft_error(int status, char *str);
void	ft_error_fd(int status, char *str, int fd);
int		error(int id, int ret);
int		syntax_error(int id, int ret);
int		print_error(int ret, const char *message);

#endif
