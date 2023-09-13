/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:37:41 by kei               #+#    #+#             */
/*   Updated: 2023/09/13 11:30:55 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

#define BUFFER_SIZE 512

typedef struct s_options
{
    int n;
    char **filenames;
    int file_count;
	int plus_flag;
	int n_flag;
} t_options;

int		ft_strcmp(const char *str1, const char *str2);
int		ft_strncmp(const char *str1, const char *str2, size_t num);
char	*ft_strtok(const char *str, const char *delim);
int		ft_strlen(const char *str);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strchr(const char *s, char c);
char	*ft_strdup(const char *s);
int		ft_atoi(char *str);
void	*ft_memcpy(void *dst, const void *src, size_t size);
void	*ft_realloc(void *ptr, size_t original_size, size_t new_size);
char	**ft_split(char *str, char *delimiter);
size_t	ft_count_elements(char **array);

void	display_no_option(char *filename);
void	display_n_option(t_options *options, int index);

void	ft_tail(int argc, char **argv);
void	display_tail_error(const char *filename);
char	*get_next_line(char **start_pos);
void	display_filename(const char *filename);
void	handle_lines(char *start_pos, char **lines, int *current_line);
void	display_lines(char **buffer_split, int first, int last);
void	parse_options(int argc, char **argv, t_options *options);
void 	execute_tail(t_options *options);

void	free_memory(void **any, size_t length);
void	**alloc_memory(size_t num_elements);

int		open_file(const char *filename);
char	*dynamic_read(int fd);
char	*read_file_content(int fd);
char	*expand_buffer(char *buffer, size_t total_read, size_t *current_block_size);

#endif
