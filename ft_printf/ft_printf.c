/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:45:33 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/28 18:13:58 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

enum e_option get_option_type(char c) {
    char	 *location;
	char	op_list[] = "cspdiuxX%";

	location = ft_strchr(op_list, c);
    if (location)
        return (location - op_list);
    return (OP_UNKNOWN);
}

void	execute(va_list args, enum e_option type)
{
	static f_execute f[] =
	{
		handle_c, handle_s, handle_p, handle_d, handle_i,
		handle_u, handle_x, handle_X, handle_per
	};
	f[type](args);
}

int	ft_printf(const char *input, ...)
{
	va_list 		args;
	enum e_option	type;

	va_start(args, input);
	while (*input) {
		if (*input == '%') {
			input++;
			type = get_option_type(*input);
			if (type != OP_UNKNOWN)
				execute(args, type);
			input++;
		}
		else {
			write(1, input, 1);
			input++;
		}
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	char	*c = "aiueo";
	ft_printf("%s", c);
}
