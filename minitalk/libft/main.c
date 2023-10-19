/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:44:29 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/29 12:34:03 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdlib.h>

char    add_index(unsigned int index, char c)
{
    c = index + c;
    return (c);
}

void	ptr_add_index(unsigned int index, char *s)
{
	*s += index;
}

void	checker(int i, int result) {
	if (result) {
		printf("\033[32m%d.OK\033[0m ", i);
    } else {
		printf("\033[31m%d.NG\033[0m ", i);
	}
}

int	main(void)
{
	// sanitize=address チェックするときは、メモリ系は消すこと。
	setbuf(stdout, NULL);

	printf("ft_isalpha: ");
	checker(1, ft_isalpha('a') == isalpha('a'));
	checker(2, ft_isalpha('a' - 1) == isalpha('a' - 1));
	checker(3, ft_isalpha('z') == isalpha('z'));
	checker(4, ft_isalpha('z' + 1) == isalpha('z' + 1));
	checker(5, ft_isalpha('A') == isalpha('A'));
	checker(6, ft_isalpha('A' - 1) == isalpha('A' - 1));
	checker(7, ft_isalpha('Z') == isalpha('Z'));
	checker(8, ft_isalpha('Z' + 1) == isalpha('Z' + 1));

	printf("\nft_isdigit: ");
	checker(1, ft_isdigit('0') == isdigit('0'));
	checker(2, ft_isdigit('0' - 1) == isdigit('0' - 1));
	checker(3, ft_isdigit('9') == isdigit('9'));
	checker(4, ft_isdigit('9' + 1) == isdigit('9' + 1));

	printf("\nft_isalnum: ");
	checker(1, ft_isalnum('a') == isalnum('a'));
	checker(2, ft_isalnum('a' - 1) == isalnum('a' - 1));
	checker(3, ft_isalnum('z') == isalnum('z'));
	checker(4, ft_isalnum('z' + 1) == isalnum('z' + 1));
	checker(5, ft_isalnum('A') == isalnum('A'));
	checker(6, ft_isalnum('A' - 1) == isalnum('A' - 1));
	checker(7, ft_isalnum('Z') == isalnum('Z'));
	checker(8, ft_isalnum('Z' + 1) == isalnum('Z' + 1));

	checker(9, ft_isalnum('0') == isalnum('0'));
	checker(10, ft_isalnum('0' - 1) == isalnum('0' - 1));
	checker(11, ft_isalnum('9') == isalnum('9'));
	checker(12, ft_isalnum('9' + 1) == isalnum('9' + 1));

	checker(13, ft_isalnum(INT_MAX) == isalnum(INT_MAX));
	checker(14, ft_isalnum(INT_MIN) == isalnum(INT_MIN));
	checker(15, ft_isalnum(INT_MAX + 1) == isalnum(INT_MAX + 1));
	checker(16, ft_isalnum(INT_MIN - 1) == isalnum(INT_MIN - 1));

	printf("\nft_isascii: ");
	checker(1, ft_isascii(-1) == isascii(-1));
	checker(2, ft_isascii(31) == isascii(31));
	checker(3, ft_isascii(32) == isascii(32));
	checker(4, ft_isascii(128) == isascii(128));
	checker(5, ft_isascii(INT_MAX) == isascii(INT_MAX));
	checker(6, ft_isascii(INT_MIN) == isascii(INT_MIN));
	checker(7, ft_isascii(INT_MAX + 1) == isascii(INT_MAX + 1));
	checker(8, ft_isascii(INT_MAX - 1) == isascii(INT_MAX - 1));

	printf("\nft_isprint: ");
	checker(1, ft_isprint(-1) == isprint(-1));
	checker(2, ft_isprint(31) == isprint(31));
	checker(3, ft_isprint(32) == isprint(32));
	checker(4, ft_isprint(128) == isprint(128));
	checker(5, ft_isprint(INT_MAX) == isprint(INT_MAX));
	checker(6, ft_isprint(INT_MIN) == isprint(INT_MIN));
	checker(7, ft_isprint(INT_MAX + 1) == isprint(INT_MAX + 1));
	checker(8, ft_isprint(INT_MAX - 1) == isprint(INT_MAX - 1));

	printf("\nft_strlen:  ");
	checker(1, ft_strlen("") == strlen(""));
	checker(2, ft_strlen("aiueo") == strlen("abcde"));
	checker(3, ft_strlen("32") == strlen("32"));
	// これはどっちも segmentation fault
	// strlen(NULL);
	// ft_strlen(NULL);

	printf("\nft_strlcat:  ");
	char *strlcat_s = "aiueo12345";
	checker(1, ft_strlcat(strlcat_s, "67890", 0) == strlcat(strlcat_s, "67890", 0));
	checker(2, ft_strlcat(strlcat_s, "67890", 3) == strlcat(strlcat_s, "67890", 3));
	checker(3, ft_strlcat(strlcat_s, "67890", 5) == strlcat(strlcat_s, "67890", 5));
	checker(4, ft_strlcat(strlcat_s, "67890", 6) == strlcat(strlcat_s, "67890", 6));

	// illegal hardware instruction
	// strlcat(strlcat_s, "67890", 15);

	// bus error
	// ft_strlcat(strlcat_s, "67890", 15)

	// printf("\nft_memcpy:  ");
	// char	memcpy_s[20];

	// checker(1, ft_memcpy(memcpy_s, "", 0) == memcpy(memcpy_s, "", 0));
	// checker(2, ft_memcpy(memcpy_s, "", 5) == memcpy(memcpy_s, "", 5));
	// checker(3, ft_memcpy(memcpy_s, "12345", 0) == memcpy(memcpy_s, "12345", 0));
	// checker(4, ft_memcpy(memcpy_s, "12345", 3) == memcpy(memcpy_s, "12345", 3));
	// checker(5, ft_memcpy(memcpy_s, "12345", 5) == memcpy(memcpy_s, "12345", 5));
	// checker(6, ft_memcpy(memcpy_s, "12345", 10) == memcpy(memcpy_s, "12345", 10));
	// checker(7, ft_memcpy(memcpy_s, "01234567890123456789", 20) == memcpy(memcpy_s, "01234567890123456789", 20));
	// checker(8, ft_memcpy(memcpy_s, NULL, 0) == memcpy(memcpy_s, NULL, 0));
	// checker(9, ft_memcpy(NULL, NULL, 0) == memcpy(NULL, NULL, 0));
	// checker(10, ft_memcpy(NULL, "", 0) == memcpy(NULL, "", 0));

	// ft_は上書き。memcpyは illegal hardware instruction
	// ft_memcpy(memcpy_s, "01234567890123456789", 21);
	// memcpy(memcpy_s, "01234567890123456789", 21);

	// どっちも segmentation fault
	// ft_memcpy(memcpy_s, NULL, 10);
	// memcpy(memcpy_s, NULL, 10);
	// ft_memcpy(NULL, "", 10);
	// memcpy(NULL, "", 10);
	// ft_memcpy(NULL, "12345", 5);
	// memcpy(NULL, "12345", 5);

	// sanitizeのチェック
	printf("\nft_substr:  ");
	char *substr_s = "aiueo12345";
	checker(1, !strcmp(ft_substr(substr_s, 0, 0), ""));
	checker(2, !strcmp(ft_substr(substr_s, 0, SIZE_MAX), "aiueo12345"));
	checker(3, !strcmp(ft_substr(substr_s, 0, -1), "aiueo12345"));
	checker(4, !strcmp(ft_substr(substr_s, 100, 1), ""));
	checker(5, !strcmp(ft_substr(substr_s, 9, 100), "5"));
	checker(6, !strcmp(ft_substr(substr_s, 5, 10), "12345"));

	printf("\nft_strjoin:  ");
	char *strjoin_s = "aiueo12345";
	checker(1, !strcmp(ft_strjoin("", ""), ""));
	checker(2, !strcmp(ft_strjoin("", "67890"), "67890"));
	checker(3, !strcmp(ft_strjoin(strjoin_s, ""), "aiueo12345"));

	printf("\nft_strtrim:  ");
	char *strtrim_s = "  aiu eo12  345 ";
	checker(1, !strcmp(ft_strtrim("  aiu eo12  345 ", "aue"), "  aiu eo12  345 "));
	checker(2, !strcmp(ft_strtrim("  aiu eo12  345 ", " aue"), "iu eo12  345"));
	checker(3, !strcmp(ft_strtrim("aiu eo12  345aa ", " a12"), "iu eo12  345"));
	checker(4, !strcmp(ft_strtrim("  a  aaa a ", " a12"), ""));
	checker(5, !strcmp(ft_strtrim("abcdba", "bca"), "d"));

	printf("\nft_split:  ");
	char	*split_s = "  aiue o123 45  ";
	checker(1, !strcmp(ft_split(split_s, 'a')[0], "  "));
	checker(2, !strcmp(ft_split(split_s, 'a')[1], "iue o123 45  "));
	checker(3, !strcmp(ft_split(split_s, ' ')[0], "aiue"));
	checker(4, !strcmp(ft_split(split_s, ' ')[1], "o123"));
	checker(5, !strcmp(ft_split(split_s, ' ')[2], "45"));

	printf("\nft_itoa:  ");
	checker(1, !strcmp(ft_itoa(12345), "12345"));
	checker(2, !strcmp(ft_itoa(-12345), "-12345"));
	checker(3, !strcmp(ft_itoa(0), "0"));
	checker(4, !strcmp(ft_itoa(INT_MAX), "2147483647"));
	checker(5, !strcmp(ft_itoa(INT_MIN), "-2147483648"));
	checker(6, !strcmp(ft_itoa(INT_MAX + 1), "-2147483648"));
	checker(7, !strcmp(ft_itoa(INT_MIN - 1), "2147483647"));

	printf("\nft_strmapi:  ");
	checker(1, !strcmp(ft_strmapi("1234", add_index), "1357"));
	checker(2, !strcmp(ft_strmapi("", add_index), ""));

	printf("\nft_striteri:  ");
	{
		char	striteri_s[] = "1234";
		ft_striteri(striteri_s, ptr_add_index);
		checker(1, !strcmp(striteri_s, "1357"));
	}
	{
		char	striteri_s[] = "";
		ft_striteri(striteri_s, ptr_add_index);
		checker(2, !strcmp(striteri_s, ""));
	}

	// printf("\nft_putchar_fd:  ");
	// ft_putchar_fd('a', 0);
	// ft_putstr_fd("aiueo", 0);
	// ft_putendl_fd("aiueo", 0);

	printf("\nft_strchr:  ");
	char	*strchr_s = "aiueo12345";
	checker(1, ft_strchr(strchr_s, 'a') == strchr(strchr_s, 'a'));
	checker(2, ft_strchr(strchr_s, '5') == strchr(strchr_s, '5'));
	checker(3, ft_strchr(strchr_s, 'o') == strchr(strchr_s, 'o'));
	checker(4, ft_strchr(strchr_s, '\0') == strchr(strchr_s, '\0'));
	checker(5, ft_strchr(strchr_s, '\0') - 1 == strchr(strchr_s, '\0') - 1);

	// どっちも segmentation fault
	// ft_strchr(NULL, 'a');
	// strchr(NULL, 'a');

	printf("\nft_strnstr: ");
	char *hay = "aiueo12345";
	checker(1, ft_strnstr(hay, "abc", 0) == strnstr(hay, "abc", 0));
	checker(2, ft_strnstr(hay, "abc", 5) == strnstr(hay, "abc", 5));
	checker(3, ft_strnstr(hay, "abc", 20) == strnstr(hay, "abc", 20));
	checker(4, ft_strnstr(hay, "aiueo", 0) == strnstr(hay, "aiueo", 0));
	checker(5, ft_strnstr(hay, "aiueo", 5) == strnstr(hay, "aiueo", 5));
	checker(6, ft_strnstr(hay, "aiueo", 20) == strnstr(hay, "aiueo", 20));
	checker(7, ft_strnstr(hay, "aiueo12345", 0) == strnstr(hay, "aiueo12345", 0));
	checker(8, ft_strnstr(hay, "aiueo12345", 5) == strnstr(hay, "aiueo12345", 5));
	checker(9, ft_strnstr(hay, "aiueo12345", 20) == strnstr(hay, "aiueo12345", 20));
	checker(10, ft_strnstr(hay, "0", 0) == strnstr(hay, "0", 0));
	checker(11, ft_strnstr(hay, "0", 5) == strnstr(hay, "0", 5));
	checker(12, ft_strnstr(hay, "0", 20) == strnstr(hay, "0", 20));

	// どっちも segmentation fault
	// ft_strnstr(hay, NULL, 0);
	// strnstr(hay, NULL, 0));
	// ft_strnstr(NULL, NULL, 0);
	// strnstr(NULL, NULL, 0));

	// strcmpで segmentation fault
	// checker(4, !strcmp(ft_strjoin(NULL, "67890"), NULL));

	printf("\nft_strrchr:  ");
	char	*strrchr_s = "aiueo12345";
	checker(1, ft_strrchr(strrchr_s, 'a') == strrchr(strrchr_s, 'a'));
	checker(2, ft_strrchr(strrchr_s, '5') == strrchr(strrchr_s, '5'));
	checker(3, ft_strrchr(strrchr_s, 'o') == strrchr(strrchr_s, 'o'));
	checker(4, ft_strrchr(strrchr_s, '\0') == strrchr(strrchr_s, '\0'));
	checker(5, ft_strrchr(strrchr_s, '\0') - 1 == strrchr(strrchr_s, '\0') - 1);

	// write (1, "\n", 1);
	// write (1, "ft_putendl_fd\n", 11);
	// int fd = open("test", O_WRONLY);
	// ft_putendl_fd("12345", fd);

	// write (1, "\n", 1);
	// write (1, "ft_calloc\n", 11);
	// ft_calloc(INT_MIN, INT_MIN);
	// printf("%d\n", INT_MIN);
	//calloc(INT_MIN, INT_MIN);

	// write (1, "\n", 1);
	// write (1, "ft_putnbr_fd\n", 13);
	// int fd = open("test", O_RDWR | O_CREAT, 0777);
	// char s[42];
	// ft_putnbr_fd(INT_MIN, fd);

	// system("leaks a.out");

	// t_list *l = ft_lstnew((void*)1);
	// ft_lstadd_front(&l, ft_lstnew((void*)2));
}
