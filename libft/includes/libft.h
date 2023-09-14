/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:40:07 by kei               #+#    #+#             */
/*   Updated: 2023/09/14 14:43:13 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

// ft_checker.c
int		ft_isalpha(char c);
int		ft_isdigit(char c);
int		ft_isalnum(char c);
int		ft_isascii(char c);
int		ft_isprint(char c);

// ft_alphabet.c
char	ft_toupper(char c);
char	ft_tolower(char c);

// ft_string.c
size_t	ft_strlen(const char *str);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strncpy(char *s1, const char *s2, size_t n);

// ft_string2.c
int		ft_strcmp(const char *str1, const char *str2);
int		ft_strncmp(const char *str1, const char *str2, size_t num);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);

// ft_string3.c
char	*ft_strchr(char *s, char c);
char	*ft_strstr(char *haystack, const char *needle);
int		ft_isspace(char c);
char	*ft_strtrim(const char *str);
size_t	ft_count_words(char const *str);

//ft_string4.c
char	*ft_itoa(int n);

// ft_memory.c
void	*ft_memset(void *s, int c, size_t n); //: メモリ領域を特定のバイトで埋める
void	*ft_memmove(void *dst, const void *src, size_t len); // メモリ領域を別の場所にコピー
void	*ft_memchr(const void *s, int c, size_t n); // メモリ領域の中から特定のバイトを検索

#endif
