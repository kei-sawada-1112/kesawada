/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:59:39 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/03 10:48:45 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 8

#endif

#include <stddef.h>

enum e_state
{
	LETTER,
	NEWLINE,
	NEED_READ,
	EOF = -1,
};

typedef struct	s_machine_state
{
	enum e_state	state;
	char			*buffer;
	char			*tmp_buffer;
	size_t			copied_len;
	size_t			tmp_len;
	size_t			count;
	size_t			start_pos;
	size_t			bytes_read;
	size_t			capacity;
	int				is_eof;
}	t_ms;

void	read_letter(t_ms *ms);
void	set_next_line(t_ms *ms, char **next_line);
void	set_tmp_buffer(t_ms *ms);
void	re_read(t_ms *ms, int fd);
