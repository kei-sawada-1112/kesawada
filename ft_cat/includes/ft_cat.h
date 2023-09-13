/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:12:22 by kei               #+#    #+#             */
/*   Updated: 2023/09/10 21:33:30 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int		ft_strcmp(char *str1, char *str2);
char	*ft_strtok(char *str, const char *delim);
void	ft_cat(char *filename);
void	display_cat_error(char *filename);
void	read_and_display_from_fd(int fd);
void	ft_cat(char *filename);
int		ft_strlen(char *str);

#endif
