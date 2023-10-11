/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:32:35 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/11 11:36:10 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (str_len < format->precision && !format->f_num && format->type != TYPE_P)
		str_len = format->precision;
	write(1, str, str_len);
	format->len += str_len;
}
