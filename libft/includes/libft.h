/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:40:07 by kei               #+#    #+#             */
/*   Updated: 2023/09/15 13:11:08 by kei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

// ft_checker.c
int			ft_isalpha(char c);
int			ft_isdigit(char c);
int			ft_isalnum(char c);
int			ft_isascii(char c);
int			ft_isprint(char c);

// ft_alphabet.c
char		ft_toupper(char c);
char		ft_tolower(char c);

// ft_string.c
size_t		ft_strlen(const char *str);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
char		*ft_strcpy(char *s1, const char *s2);
char		*ft_strncpy(char *s1, const char *s2, size_t n);

// ft_string2.c
int			ft_strcmp(const char *str1, const char *str2);
int			ft_strncmp(const char *str1, const char *str2, size_t num);
char		*ft_strdup(const char *s);
char		*ft_strndup(const char *s, size_t n);
char		*ft_strjoin(const char *s1, const char *s2);

// ft_string3.c
char		*ft_strchr(const char *s, int c);
char		*ft_strstr(const char *haystack, const char *needle);
int			ft_isspace(char c);
char		*ft_strtrim(const char *str);
size_t		count_words(char const *str);

// ft_string4.c
int			ft_numlen(int n);
char		*ft_itoa(int n);
int			ft_atoi(const char *str);
char		*ft_strrchr(const char *str, const char c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t n);

// ft_string5.c
size_t		ft_strlcat(char *dst, const char *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t n);
char		*ft_strtok(const char *str, const char *delim);
char		*ft_strpbrk(const char *str, const char *set);
size_t		ft_strspn(const char *str, const char *accept);

// ft_string6.c
size_t		ft_strcspn(const char *str, const char *accept);
char		*ft_strtok_r(char *str, const char *delim, char **saveptr);
double		ft_atof(const char *nptr);
int			ft_pow(int x, int y);

// ft_string7.c
int			check_base(int base, char *nptr);
long int	ft_strtol(const char *nptr, char **endptr, int base);
char		*preprocess(const char *nptr, int *sign);

// ft_memory.c
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_realloc(void *ptr, size_t original_size, size_t new_size);

// ft_memory2.c
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
int			ft_memcmp(const void *mem1, const void *mem2);
void		*ft_memalloc(size_t n);

/*
char *strtok(char *str, const char *delim);
strpbrk:
c
Copy code
char *strpbrk(const char *str, const char *set);
次に、標準ライブラリに存在するが、あなたのリストには含まれていない一部の関数のプロトタイプを示します。

<string.h>:
c
Copy code
char *strcat(char *dest, const char *src);
char *strrchr(const char *str, int c);
char *strstr(const char *haystack, const char *needle);
size_t strspn(const char *str, const char *accept);
size_t strcspn(const char *str, const char *reject);
char *strtok_r(char *str, const char *delim, char **saveptr);  // thread-safe version of strtok
<stdlib.h>:
c
Copy code
double atof(const char *nptr);
long int strtol(const char *nptr, char **endptr, int base);
unsigned long int strtoul(const char *nptr, char **endptr, int base);
<ctype.h>:
c
Copy code
int isxdigit(int c);
int iscntrl(int c);
int ispunct(int c);
int isupper(int c);
int islower(int c);
ft_lstnew(): 新しいリスト要素を生成します。
ft_lstdel(): リストの要素を削除します。
ft_lstadd(): リストに新しい要素を追加します。
その他のリスト操作関数...
*/

#endif
