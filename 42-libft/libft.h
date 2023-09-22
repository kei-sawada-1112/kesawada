/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:44:01 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/21 20:06:54 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *str);
void				*ft_memset(void *s, int c, size_t count);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t count);
void				*ft_memmove(void *dst, const void *src, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *str, const char c);
int					ft_strncmp(const char *str1, const char *str2, size_t num);
void				*ft_memchr(const void *s, int c, size_t count);
int					ft_memcmp(const void *mem1, const void *mem2, size_t n);
char				*ft_strnstr(const char *hay, const char *nee, size_t n);
int					ft_atoi(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char                *ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	            *ft_strtrim(char const *s1, char const *set);
void                ft_putchar_fd(char c, int fd);
void                ft_putstr_fd(char *s, int fd);
void                ft_putendl_fd(char *s, int fd);

#endif
