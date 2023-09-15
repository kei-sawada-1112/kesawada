/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:40:07 by kei               #+#    #+#             */
/*   Updated: 2023/09/15 23:04:08 by kei              ###   ########.fr       */
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
char				*ft_strnstr(const char *haystack, const char *needle, size_t n);

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
char 				*ft_strrev(char *str);
char 				*ft_strset(char *str, int ch);
void				*ft_memrev(void *ptr, size_t n);
int					ft_isgraph(int c);

// ft_list.c
void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));

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
void				*ft_realloc(void *ptr, size_t original_size, size_t new_size);
void				ft_memdel(void **mem);

// ft_ctype.c
int 				ft_isxdigit(int c);
int 				ft_iscntrl(int c);
int 				ft_ispunct(int c);
int 				ft_isupper(int c);
int 				ft_islower(int c);

/*
メモリ管理関連:

void *malloc(size_t size); - 指定されたバイト数のメモリを動的に確保します。
void free(void *ptr); - malloc()やcalloc()などで確保したメモリを解放します。
void *calloc(size_t num_elements, size_t element_size); - 指定された要素数と要素のサイズに基づいてメモリを動的に確保し、0で初期化します。
void *realloc(void *ptr, size_t new_size); - すでに確保されたメモリのサイズを変更します。
数学関連:

double atof(const char *str); - すでにリスト化されています。
int atoi(const char *str); - すでにリスト化されています。
long int strtol(const char *nptr, char **endptr, int base); - すでにリスト化されています。
unsigned long int strtoul(const char *nptr, char **endptr, int base); - すでにリスト化されています。
乱数関連:

void srand(unsigned int seed); - 乱数生成器の初期化を行います。
int rand(void); - 0からRAND_MAXまでの範囲で乱数を返します。
その他のユーティリティ関連:

void abort(void); - プログラムを異常終了させます。
void exit(int status); - プログラムを終了させ、シェルや親プロセスにステータスを返します。
int atexit(void (*func)(void)); - プログラム終了時に実行される関数を登録します。
環境関連:

char *getenv(const char *name); - 環境変数の値を取得します。
int system(const char *command); - シェルコマンドを実行します。
検索およびソート関連:

void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)); - 二分検索を使用して配列内の要素を検索します。
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)); - 配列の要素をクイックソートを使用してソートします。
ft_lstnew(): 新しいリスト要素を生成します。
ft_lstdel(): リストの要素を削除します。
ft_lstadd(): リストに新しい要素を追加します。
その他のリスト操作関数...

strrev: 文字列を逆順にする関数。
strstr: 文字列の中で別の文字列を探す関数（すでに言及済みですが、再確認のためにリストに含めています）。
strset: 文字列の中のすべての文字を指定された文字で置き換える関数。
strtok: 文字列を指定された区切り文字でトークンに分割する関数（これもすでにリストにありますが、再確認のために含めています）。
memrev: メモリブロックの内容を逆順にする関数。
*/

#endif
