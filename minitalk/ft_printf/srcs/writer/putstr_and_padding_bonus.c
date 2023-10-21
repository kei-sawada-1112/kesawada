/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_and_padding_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:32:35 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/21 07:49:50 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	apply_padding(const char *str, t_format *format)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	write(1, str, str_len);
	format->len += str_len;
}

void	putstr_and_add_len(const char *str, t_format *format)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	if (str_len > format->precision && format->type == TYPE_S && format->f_dot)
		str_len = format->precision;
	write(1, str, str_len);
	format->len += str_len;
}
