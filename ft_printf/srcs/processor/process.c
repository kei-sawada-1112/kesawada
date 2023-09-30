/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:16:14 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/30 23:23:42 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

#include <stdio.h>

void	process_letter(char **str, t_format *format)
{
	char	tmp[2];

	if (**str == '%')
		format->state = FLAG;
	else
	{
		tmp[0] = **str;
		tmp[1] = '\0';
		add_to_buffer(tmp, format);
	}
	(*str)++;
}

static int	set_type(char c, t_format *format)
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
	if (set_type(**str, format))
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
