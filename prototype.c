/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplanell <mplanell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 20:55:17 by mplanell          #+#    #+#             */
/*   Updated: 2017/10/25 02:03:24 by mplanell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"
#include "libft.h"

typedef struct				s_param
{
	size_t					size;
	union
	{
		int					size_4;
		short				size_2;
		char				size_1;
	};
}							t_param;

typedef struct				s_test
{
	char					op_code;
	char					param_code;
	struct s_param			param1;
	struct s_param			param2;
	struct s_param			param3;
	unsigned int			byte_count;
}							t_test;

void	write_int_as_big_endian(int fd, unsigned int data)
{
	char	buffer[4];

	buffer[0] = (data >> 24) & 0xFF;
	buffer[1] = (data >> 16) & 0xFF;
	buffer[2] = (data >> 8) & 0xFF;
	buffer[3] = data & 0xFF;

	/*
	** ft_printf("%hhx\n", buffer[0]);
	** ft_printf("%hhx\n", buffer[1]);
	** ft_printf("%hhx\n", buffer[2]);
	** ft_printf("%hhx\n", buffer[3]);
	*/
	write(fd, buffer, 4);
}

int SwapEndian(int val)
{
	/*
    ** val = (val<<8) | (val>>8);
	*/
    val = (val<<24) | ((val<<8) & 0x00ff0000) |
          ((val>>8) & 0x0000ff00) | (val>>24);
	return (val);
}

t_asm_instruct	*create_instruct(char op_code, char param_code, char *param, unsigned int param_size,
		unsigned int byte_count, char has_label)
{
	t_asm_instruct *new;

	new = ft_memalloc(sizeof(t_asm_instruct));
	new->op_code = op_code;
	new->param_code = param_code;
	ft_strcpy(new->param, param);
	new->param_size = param_size;
	new->byte_count = byte_count;
	new->has_label = 0;
	new->next = NULL;
	return (new);
}

int	write_param(int fd, t_param *to_write)
{
	int		ret;

	if (to_write->size == 0)
		return (0);
	else if (to_write->size == 4)
		ret = write(fd, &to_write->size_4, to_write->size);
	else if (to_write->size == 2)
		ret = write(fd, &to_write->size_2, to_write->size);
	else if (to_write->size == 1)
		ret = write(fd, &to_write->size_1, to_write->size);
	return (ret);
}

int main(void)
{
	int			fd;
	t_header	test = { COREWAR_EXEC_MAGIC, "basic", 20, "just a basic living prog" };

/*
**     t_asm_instruct	*kek;
**     char		param[PARAM_MAX * 4];
**
**     ft_bzero(param, PARAM_MAX *4);
**     param[0] = 0;
**     param[1] = 0;
**     param[2] = 0;
**     param[3] = 0;
**     param[4] = 10;
**     kek = create_instruct(2, 144, param, 6, 7, 1);
*/
	char op_code;
	char param_code;
	char first_param;

	op_code = 2;
	param_code = 144;
	first_param = 0;

	fd = open("header.cor", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	t_param		test2;
	test2.size = 4;
	test2.size_4 = SwapEndian(10);

	test.magic = SwapEndian(test.magic);
	test.prog_size = SwapEndian(test.prog_size);
	write(fd, &test, sizeof(t_header));
	write(fd, &op_code, 1);
	write(fd, &param_code, 1);
	write(fd, &first_param, 1);
	write_param(fd, &test2);
	/*
	** write(fd, &kek->op_code, sizeof(char));
	** write(fd, &kek->param_code, sizeof(char));
	** write(fd, kek->param, kek->param_size);
	*/
	close(fd);
	return (0);
}
