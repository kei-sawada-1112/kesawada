/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:08:25 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/01 01:43:24 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stddef.h>

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
	TYPE_INVALID,
};

enum e_state
{
	LETTER, // 文字列解析状態
	FLAG,   // %直後の # などのフラグを管理する状態
	FIELD,  // フィールド幅を調査する状態
	PREFIX, // .以降の精度の値を調査する状態
	TYPE,   // c, s, d などのタイプを処理する状態
	ERROR   // エラーが発生した状態
};

#define BUFFER_SIZE 1024

typedef struct s_format
{
	enum e_state	state;
	enum e_type		type;
	va_list			args;
	char			*buffer;
	size_t			cap;
	size_t			width;
	int				precision;
	int				f_hash;
	int				f_zero;
	int				f_plus;
	int				f_minus;
	int				f_space;
	char			*prefix;
}	t_format;

// opごとに実行する関数ポインタの宣言
typedef void	(*f_execute)(t_format *);

typedef char	*(*f_getter)(t_format *);

typedef void	(*f_process)(char **, t_format *);

// op_handler
// void	handle_c(t_format *format);
// void	handle_s(t_format *format);
// void	handle_p(t_format *format);
// void	handle_d(t_format *format);
// void	handle_i(t_format *format);
// void	handle_u(t_format *format);
// void	handle_x(t_format *format);
// void	handle_X(t_format *format);
// void	handle_per(t_format *format);
void	handle_common(t_format *format, char *(*get_value)(t_format *f));

// process
void	process_letter(char **str, t_format *format);
void	process_flag(char **str, t_format *format);
void	process_field(char **str, t_format *format);
void	process_prefix(char **str, t_format *format);
void	process_type(char **str, t_format *format);
void	process_error(char **str, t_format *format);

// buffer_handler
void	init_buffer(t_format *format);
void	add_to_buffer(const char *str, t_format *format);

// getter
char	*get_int_value(t_format *format);
char	*get_char_value(t_format *format);
char	*get_double_value(t_format *format);
char	*get_str_value(t_format *format);
char	*get_hex_value(t_format *format);

// 変換してbufferに書き込み
char	*convert_to_hex(char *ptr);

int		ft_printf(const char *input, ...);

#endif
