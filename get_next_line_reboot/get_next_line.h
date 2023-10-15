/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:04:29 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/15 14:59:35 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	int				fd;
	char			*str;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*read_tmp_and_buffer(t_list *current_list, char *buffer);
char	*ft_strndup(const char *s1, size_t n);
size_t	nextl_line_len(t_list *list);
char	*ft_strjoin(char *s1, const char *s2);
char	*find_next_line(t_list *current_list);

#endif
