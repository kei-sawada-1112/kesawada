/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:08:25 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/12 22:13:46 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printf(const char *input, ...);

size_t	ft_putstr(const char *str);
size_t	ft_putchar(const char c);
size_t	ft_putnbr(int num);
size_t	ft_putunbr(unsigned int num);
size_t	ft_putaddress(void *ptr);
size_t	ft_putnbr_base(unsigned num, char *base);
size_t	ft_strlen(const char *str);

#endif
