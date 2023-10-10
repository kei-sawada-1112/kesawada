/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:16:14 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/10 15:26:39 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_letter(char **str, t_format *format)
{
	size_t	i;

	i = 0;
	while ((*str)[i] && (*str)[i] != '%')
		i++;
	write(1, *str, i);
	format->len += i;
	if (**str == '%')
	{
		format->state = FLAG;
		i++;
	}
	(*str) += i;
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

void	set_format_flags(char c, t_format *format)
{
	if (c == '0')
		format->f_zero = 1;
	else if (c == '#')
		format->f_hash = 1;
	else if (c == '+')
		format->f_plus = 1;
	else if (c == ' ')
		format->f_space = 1;
	else if (c == '-')
		format->f_minus = 1;
}

int	set_format_state(char **str, t_format *format)
{
	if (**str == '%')
	{
		format->state = LETTER;
		putstr_and_add_len("%", format);
	}
	else if (ft_isdigit(**str) && **str != '0' && !format->f_dot)
	{
		format->state = FIELD;
		return (0);
	}
	else if (**str == '.')
	{
		format->state = PREFIX;
		format->f_dot = 1;
	}
	else
		format->type = TYPE_INVALID;
	return (1);
}

void	process_flag(char **str, t_format *format)
{
	if (check_type(**str, format))
		return ;
	set_format_flags(**str, format);
	if (set_format_state(str, format))
		(*str)++;
}
