/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:08:25 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/21 08:48:23 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>

enum e_type
{
	TYPE_C,
	TYPE_S,
	TYPE_P,
	TYPE_D,
	TYPE_I,
	TYPE_U,
	TYPE_X,
	TYPE_LX,
	TYPE_PER,
	TYPE_INVALID
};

enum e_state
{
	LETTER,
	FLAG,
	FIELD,
	PREFIX,
	TYPE,
};

typedef struct s_format
{
	enum e_state	state;
	enum e_type		type;
	va_list			args;
	size_t			width;
	size_t			precision;
	size_t			len;
	int				sign;
	int				f_sharp;
	int				f_zero;
	int				f_plus;
	int				f_minus;
	int				f_space;
	int				f_dot;
	int				f_num;
	int				f_asta;
	char			*prefix;
	char			*field;
	char			invalid_char;
}	t_format;

typedef char	*(*t_getter)(t_format *);
typedef void	(*t_process)(const char **, t_format *);

int		ft_printf(const char *input, ...);
void	init_format(t_format *format);
void	handle_common(t_format *format, char *(*get_value)(t_format *f));

void	process_letter(const char **str, t_format *format);
void	process_flag(const char **str, t_format *format);
void	process_field(const char **str, t_format *format);
void	process_prefix(const char **str, t_format *format);
void	process_type(const char **str, t_format *format);

void	putstr_and_add_len(const char *str, t_format *format);
void	apply_padding(const char *str, t_format *format);

char	*get_int_value(t_format *format);
char	*get_char_value(t_format *format);
char	*get_double_value(t_format *format);
char	*get_str_value(t_format *format);
char	*get_hexaddr_value(t_format *format);
char	*get_per_value(t_format *format);
char	*get_uint_value(t_format *format);
char	*get_hex_value(t_format *format);
char	*convert_to_hexaddr(void *ptr, int type);
char	*convert_to_hex(int num, int dot_flag);

char	*ft_uitoa(unsigned int num);

#endif
