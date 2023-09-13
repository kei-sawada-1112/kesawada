/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:37:41 by kei               #+#    #+#             */
/*   Updated: 2023/09/13 17:31:52 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# define BUFFER_SIZE 512

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_options
{
	int		n;
	char	**filenames;
	int		file_count;
	int		option_count;
	int		plus_flag;
	int		n_flag;
	int		c_flag;
	int		b_flag;
}	t_options;

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

void	display_n_option(t_options *options, int index);

void	ft_tail(int argc, char **argv);
void	display_tail_error(char *filename);
char	*get_next_line(char **start_pos);
void	display_filename(const char *filename);
void	handle_lines(char *start_pos, char **lines, int *current_line);
void	display_lines(char **buffer_split, int first, int last);

// parse_options.c オプションの解析
int		parse_options(int argc, char **argv, t_options *options);
int		check_options(char **argv, t_options *options, int *i);
void	set_filenames(int argc, char **argv, t_options *options, int i);
int		is_valid_number(char *num);

void	execute_tail(t_options *options);

void	free_memory(void **any, size_t length);
void	**alloc_memory(size_t num_elements);

// file_controller.c ファイルを読んだり閉じたり
int		open_file_or_stdin(const char *filename);
char	*dynamic_read(int fd);
char	*resize_buffer(char *buffer, size_t *current_size, size_t total_read);
void	free_resources(char *buffer, char **buffer_split, size_t size, int fd);

#endif
