/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:40:07 by kei               #+#    #+#             */
/*   Updated: 2023/09/15 23:16:01 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

// ft_checker.c
int					ft_isalpha(char c);
int					ft_isdigit(char c);
int					ft_isalnum(char c);
int					ft_isascii(char c);
int					ft_isprint(char c);

// ft_alphabet.c
char				ft_toupper(char c);
char				ft_tolower(char c);

// ft_string.c
size_t				ft_strlen(const char *str);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strncpy(char *s1, const char *s2, size_t n);

// ft_string2.c
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t num);
char				*ft_strdup(const char *s);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strjoin(const char *s1, const char *s2);

// ft_string3.c
char				*ft_strchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_isspace(char c);
char				*ft_strtrim(const char *str);
size_t				count_words(char const *str);

// ft_string4.c
int					ft_numlen(int n);
char				*ft_itoa(int n);
int					ft_atoi(const char *str);
char				*ft_strrchr(const char *str, const char c);
char				*ft_strnstr(const char *hay, const char *nee, size_t n);

// ft_string5.c
size_t				ft_strlcat(char *dst, const char *src, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t n);
char				*ft_strtok(const char *str, const char *delim);
char				*ft_strpbrk(const char *str, const char *set);
size_t				ft_strspn(const char *str, const char *accept);

// ft_string6.c
size_t				ft_strcspn(const char *str, const char *accept);
char				*ft_strtok_r(char *str, const char *delim, char **saveptr);
double				ft_atof(const char *nptr);
int					ft_pow(int x, int y);

// ft_string7.c
long int			ft_strtol(const char *nptr, char **endptr, int base);
unsigned long int	ft_strtoul(const char *nptr, char **endptr, int base);
char				*preprocess(const char *nptr, int *sign);

// ft_string8.c
char				*ft_strrev(char *str);
char				*ft_strset(char *str, int ch);
void				*ft_memrev(void *ptr, size_t n);
int					ft_isgraph(int c);

// ft_list.c

// ft_memory.c
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memrchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

// ft_memory2.c
int					ft_memcmp(const void *mem1, const void *mem2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memalloc(size_t n);
void				*ft_realloc(void *ptr, size_t orig_size, size_t new_size);
void				ft_memdel(void **mem);

// ft_ctype.c
int					ft_isxdigit(int c);
int					ft_iscntrl(int c);
int					ft_ispunct(int c);
int					ft_isupper(int c);
int					ft_islower(int c);

#endif
