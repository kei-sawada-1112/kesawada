/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:12:44 by kei               #+#    #+#             */
/*   Updated: 2023/09/17 14:11:49 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"
#include <errno.h>
#include <sys/stat.h>

void	display_tail_error(char *filename)
{
	if (!filename)
		return ;
	write(1, "tail: ", 6);
	write(1, filename, ft_strlen(filename));
	if (errno == ENOENT)
		write(1, ": No such file or directory\n", 28);
	else if (errno == EACCES)
		write(1, ": Permission denied\n", 20);
	else
		write(1, ": Unexpected error\n", 19);
}

void	display_filename(const char *filename)
{
	write(1, "==> ", 4);
	write(1, filename, ft_strlen(filename));
	write(1, " <==", 4);
	write(1, "\n", 1);
}
