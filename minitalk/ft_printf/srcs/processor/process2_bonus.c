/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:16:14 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/12 14:00:17 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

static void	set_asta_value(t_format *format)
{
	int	asta_num;

	asta_num = va_arg(format->args, int);
	if (format->f_dot && asta_num > 0)
		format->precision = asta_num;
	else if (format->f_dot && asta_num < 0)
		format->f_dot = 0;
	else if (!format->f_dot)
	{
		if (asta_num < 0)
		{
			format->f_minus = 1;
			format->width = asta_num * -1;
		}
		else
			format->width = asta_num;
	}
	format->f_asta = 1;
	format->state = FLAG;
}

static int	set_format_flags(char **str, t_format *format)
{
	if (**str == '0')
		format->f_zero = 1;
	else if (**str == '#')
		format->f_sharp = 1;
	else if (**str == '+')
		format->f_plus = 1;
	else if (**str == ' ')
		format->f_space = 1;
	else if (**str == '-')
		format->f_minus = 1;
	else if (**str == '*')
		set_asta_value(format);
	else
		return (0);
	(*str)++;
	return (1);
}

static void	set_format_state(char **str, t_format *format)
{
	if (ft_isdigit(**str) && **str != '0' && !format->f_dot)
	{
		format->state = FIELD;
		return ;
	}
	else if (**str == '.')
	{
		format->state = PREFIX;
		format->f_dot = 1;
	}
	else
	{
		format->type = TYPE_INVALID;
		format->invalid_char = **str;
		format->state = TYPE;
		return ;
	}
	(*str)++;
}

void	process_flag(char **str, t_format *format)
{
	if (check_type(**str, format))
		return ;
	if (set_format_flags(str, format))
		return ;
	set_format_state(str, format);
}
