/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:36:51 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/05 15:32:33 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

enum e_state
{
	LETTER,
	NEWLINE,
	NEED_READ,
	GNL_EOF,
};

typedef struct s_machine_state
{
	int				fd;
	enum e_state	state;
	char			buffer[BUFFER_SIZE];
	char			*tmp_buffer;
	size_t			tmp_len;
	size_t			count;
	size_t			copied_len;
	size_t			start_pos;
	int				bytes_read;
}	t_ms;

typedef struct s_list
{
	char			*tmp_buffer;
	struct s_list	*next;
	size_t			tmp_len;
}	t_list;

void	read_letter(t_ms *ms);
void	set_next_line(t_ms *ms, char **next_line);
void	set_tmp_buffer(t_ms *ms);
void	re_read(t_ms *ms);

char	*get_next_line(int fd);

#endif
