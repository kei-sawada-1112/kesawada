/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:16:14 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/01 13:28:19 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

#include <stdio.h>

void	process_letter(char **str, t_format *format)
{
	char	tmp[BUFFER_SIZE];
	size_t	i;

	i = 0;
	while (**str && **str != '%')
	{
		tmp[i] = **str;
		if (tmp[BUFFER_SIZE - 1])
		{
			add_to_buffer(tmp, format);
			ft_memset(tmp, '\0', BUFFER_SIZE);
			i = 0;
		}
		(*str)++;
		i++;
	}
	if (i > 0) {
		tmp[i] = '\0';
		add_to_buffer(tmp, format);
    }
	if (**str == '%')
	{
		format->state = FLAG;
		(*str)++;
	}
}

static int	check_type(char c, t_format *format)
{
	char	*op_list;
	char	*type;

	op_list = "cspdiuxX%";
	type = ft_strchr(op_list, c);
	if (type)
	{
		format->state = TYPE;
		format->type = type - op_list;
		return (1);
	}
	return (0);
}

void	process_flag(char **str, t_format *format)
{
	if (check_type(**str, format))
		return ;
	else if (**str == '0')
		format->f_zero = 1;
	else if (**str == '#')
		format->f_hash = 1;
	else if (**str == '+')
		format->f_plus = 1;
	else if (**str == ' ')
		format->f_space = 1;
	else if (**str == '-')
		format->f_minus = 1;
	else if (**str == '%')
	{
		format->state = LETTER;
		add_to_buffer("%", format);
	}
	else if (ft_isdigit(**str))
	{
		format->state = FIELD;
		return ;
	}
	else if (**str == '.')
		format->state = PREFIX;
	else
		format->type = TYPE_INVALID;
	(*str)++;
}
