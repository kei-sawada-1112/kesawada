/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:11:04 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/10 17:13:06 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_padding(const char *str, t_format *format)
{
	size_t	len_str;

	len_str = ft_strlen(str);
	write(1, str, len_str);
	format->len += len_str;
}

void	putstr_and_add_len(const char *str, t_format *format)
{
	size_t	len_str;

	len_str = ft_strlen(str);
	if (len_str > format->precision && format->type == TYPE_S && format->f_dot)
		len_str = format->precision;
	write(1, str, len_str);
	format->len += len_str;
}
