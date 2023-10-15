/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:18:32 by kesawada          #+#    #+#             */
/*   Updated: 2023/10/15 17:19:27 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	has_next_line(t_list *list)
{
	int	i;

	if (!list->str)
		return (0);
	i = 0;
	while (list->str[i])
	{
		if (list->str[i] == '\n')
			return (1);
		else
			i++;
	}
	return (0);
}

t_list	*search_list(t_list *list, int fd)
{
	t_list	*tmp_list;

	tmp_list = list;
	while (tmp_list)
	{
		if (tmp_list->fd == fd)
			return (tmp_list);
		else
			tmp_list = tmp_list->next;
	}
	return (NULL);
}

void	insert_list(t_list **list, int fd)
{
	t_list	*new_list;
	t_list	*tmp_list;

	tmp_list = *list;
	new_list = malloc(sizeof(t_list));
	new_list->fd = fd;
	new_list->next = NULL;
	new_list->str = malloc(1);
	if (!new_list->str)
	{
		free(new_list);
		return ;
	}
	new_list->str[0] = '\0';
	if (!tmp_list)
	{
		*list = new_list;
		return ;
	}
	while (tmp_list->next)
		tmp_list = tmp_list->next;
	tmp_list = new_list;
}

int	check_list(t_list *list)
{
	int		bytes;
	char	*buffer;
	char	*tmp_buffer;

	while (!has_next_line(list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
		bytes = read(list->fd, buffer, BUFFER_SIZE);
		if (!bytes)
		{
			free(buffer);
			return (1);
		}
		buffer[bytes] = '\0';
		tmp_buffer = ft_strjoin(list->str, buffer);
		free(list->str);
		list->str = NULL;
		free(buffer);
		buffer = NULL;
		list->str = tmp_buffer;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	t_list			*current_list;
	char			*next_line;

	next_line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, next_line, 0) < 0)
		return (NULL);
	current_list = search_list(list, fd);
	if (!current_list)
	{
		insert_list(&list, fd);
		current_list = list;
	}
	if (!check_list(current_list) || *current_list->str == '\0')
		return (NULL);
	next_line = find_next_line(current_list);
	return (next_line);
}

// int	main(int argc, char *argv[])
// {
// 	int	fd1;
// 	// int	fd2;
// 	int	i;
// 	char	*ret1;
// 	// char	*ret2;

// 	(void)argc;
// 	i = 0;
// 	fd1 = open(argv[1], O_RDONLY);
// 	// fd2 = open(argv[2], O_RDONLY);
// 	while (i < 6)
// 	{
// 		ret1 = get_next_line(fd1);
// 		printf("ret1:%s", ret1);
// 		free(ret1);
// 		// ret2 = get_next_line(fd2);
// 		// printf("%s\n", ret2);
// 		i++;
// 	}
// 	close (fd1);
// 	system("leaks a.out");
// 	// free(ret2);
// }
