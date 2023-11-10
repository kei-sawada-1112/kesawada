/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:36:51 by kesawada          #+#    #+#             */
/*   Updated: 2023/11/10 13:47:44 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

enum e_state
{
	LETTER,
	NEWLINE,
	NEED_READ,
	GNL_EOF,
	ERROR
};

typedef struct s_ms
{
	int				fd;
	enum e_state	state;
	char			*buffer;
	char			*tmp_buffer;
	size_t			tmp_len;
	size_t			count;
	size_t			copied_len;
	size_t			cap;
	int				bytes_read;
	struct s_ms		*next;
}	t_ms;

void	read_letter(t_ms *ms);
void	set_next_line(t_ms *ms, char **next_line);
int		set_tmp_buffer(t_ms *ms);
int		re_read(t_ms *ms);

char	*get_next_line(int fd);

#endif
