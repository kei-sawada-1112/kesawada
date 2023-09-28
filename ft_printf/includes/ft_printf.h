/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:08:25 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/28 18:28:07 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>

enum e_option
{
	OP_D,
	OP_C,
	OP_F,
	OP_INVALID,
};

// opごとに実行する関数ポインタの宣言
typedef void (*f_execute)(va_list);

// op_handler
void	handle_c(va_list args);
void	handle_s(va_list args);
void	handle_p(va_list args);
void	handle_d(va_list args);
void	handle_i(va_list args);
void	handle_u(va_list args);
void	handle_x(va_list args);
void	handle_X(va_list args);
void	handle_per(va_list args);

// ポインタの位置を取得する
void	print_hex_addr(char *ptr);

int	ft_printf(const char *input, ...);

#endif
