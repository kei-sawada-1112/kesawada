/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:30:43 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/25 20:30:47 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>

char    nibai(unsigned int index, char c)
{
    c = index * c;
    return (c);
}

void	checker(int result) {
	if (result) {
		printf("OK ");
    } else {
		printf("NG ");
	}
}

int	main(void)
{
	// setbuf(stdout, NULL);
	
	// write (1, "ft_isalpha\n", 11);
	// checker(ft_isalpha('a') == 1);
	// checker(ft_isalpha('a' - 1) == 0);
	// checker(ft_isalpha('z') == 1);
	// checker(ft_isalpha('z' + 1) == 0);

	// write (1, "\n", 1);
	// write (1, "ft_isdigit\n", 11);
	// printf("c = %c, %d\n", '0', ft_isdigit('0'));
	// printf("c = %c, %d\n", '0' - 1, ft_isdigit('0' - 1));
	// printf("c = %c, %d\n", '9', ft_isdigit('9'));
	// printf("c = %c, %d\n", '9' + 1, ft_isdigit('9' + 1));

	// write (1, "\n", 1);
	// write (1, "ft_isalnum\n", 11);
	// printf("c = %c, %d\n", '0', ft_isalnum('0'));
	// printf("c = %c, %d\n", '0' - 1, ft_isalnum('0' - 1));
	// printf("c = %c, %d\n", '9', ft_isalnum('9'));
	// printf("c = %c, %d\n", '9' + 1, ft_isalnum('9' + 1));

	// write (1, "\n", 1);
	// write (1, "ft_isascii\n", 11);
	// printf("c = %c, %d\n", -1, ft_isascii(-1));
	// printf("c = %c, %d\n", 31, ft_isascii(31));
	// printf("c = %c, %d\n", 32, ft_isascii(32));
	// printf("c = %c, %d\n", 128, ft_isascii(128));

	// write (1, "\n", 1);
	// write (1, "ft_isprint\n", 11);
	// printf("c = %c, %d\n", -1, ft_isprint(-1));
	// printf("c = %c, %d\n", 31, ft_isprint(31));
	// printf("c = %c, %d\n", 32, ft_isprint(32));
	// printf("c = %c, %d\n", 128, ft_isprint(128));

	// write (1, "\n", 1);
	// write (1, "ft_strlen\n", 11);
	// printf("c = %s, %zu\n", "", ft_strlen(""));
	// printf("c = %s, %zu\n", "aie", ft_strlen("aie"));
	// printf("c = %s, %zu\n", "weoifa", ft_strlen("weoifa"));
	// printf("c = %s, %zu\n", "efwahf21893jfa", ft_strlen("efwahf21893jfa"));

	// write (1, "\n", 1);
	// write (1, "ft_memcpy\n", 11);
	// char	dst[100];
	// char	*src = NULL;
	// size_t	n = 0;
	// printf("dst = %s\n", (char *)ft_memcpy(dst, NULL, n));
	// //printf("dst = %s\n", (char *)memcpy(dst, NULL, n));


	// write (1, "\n", 1);
	// write (1, "ft_strchr\n", 11);
	// printf("c = %s, %s\n", "\0", ft_strchr("aiueo", '\0') - 1);

	write (1, "\n", 1);
	write (1, "ft_strnstr\n", 11);
	printf("c = %s, %s\n", "a", ft_strnstr((void *)0, "fake", 0));
	printf("c = %s, %s\n", "a", strnstr((void *)0, "fake", 0));

//	printf("c = %s, %s\n", "a", ft_strnstr("abbbcdefg", "bbc", 20));


	write (1, "\n", 1);
	char *s = "libft-test-tokyo";
	printf("1 = %s\n", ft_substr(s, 0, 42000));
	printf("2 = %s\n", ft_substr(s, 100, 1));
	printf("3 = %s\n", ft_substr(s, 15, 100));
	printf("4 = %s\n", ft_substr(s, 5, 10));

	// write (1, "\n", 1);
	// write (1, "ft_strlcat\n", 11);
	// printf("c = %s, %zu\n", "a", ft_strlcat("abcde", "123", 3));

	// write (1, "\n", 1);
	// write (1, "ft_strjoin\n", 11);
	// printf("c = %s, %s\n", "a", ft_strjoin("aiueo", "12345"));

	// write (1, "\n", 1);
	// write (1, "ft_strrchr\n", 11);
	// printf("c = %s, %s\n", "\0", ft_strrchr("aiueo", '\0'));

	// int		d[] = {1, 2, 3};
	// int		f[] = {1, 2, 2};

	// write (1, "\n", 1);
	// write (1, "ft_memcmp\n", 11);
	// printf("c = %s, %d\n", "\0", ft_memcmp(d, f, 100));
	// //printf("c = %s, %d\n", "\0", memcmp(d, f, 100));

	// const char	str1[] = "hello world !";
	// const char	str2[] = "l r";
	// write (1, "\n", 1);
	// write (1, "ft_strncmp\n", 11);
	// printf("c = %s, %d\n", "\0", ft_strncmp(str1, str2, 4));
	// printf("c = %s, %d\n", "\0", strncmp(str1, str2, 4));

	// write (1, "\n", 1);
	// write (1, "ft_split\n", 11);
	// char	**result = ft_split("  Tripo uille  ", ' ');
	// int i = 0;
	// while (i < 3)
	// {
	// 	printf("result[] = %s\n", result[0]);
	// 	i++;
	// }

	// write (1, "\n", 1);
	// write (1, "ft_itoa\n", 8);
	// printf("ft_itoa: %s\n", ft_itoa(0));
	// printf("ft_itoa: %s\n", ft_itoa(INT_MIN));
	// printf("ft_itoa: %s\n", ft_itoa(INT_MAX));
	

	// write (1, "\n", 1);
	// write (1, "ft_substr\n", 11);
	// printf("c = %s, %s\n", "a", ft_substr("abcde", 5, 5));

	// write (1, "\n", 1);
	// write (1, "ft_strmapi\n", 11);
	// printf("ft_strmapi: %s\n", ft_strmapi("abcde", nibai));

	// write (1, "\n", 1);
	// write (1, "ft_strchr\n", 11);
	// printf("c = %s, %s\n", "\0", ft_strchr("aiueo", 'i'));

	// ft_putchar_fd('a', 0);
	// ft_putstr_fd("aiueo", 0);
	// ft_putendl_fd("aiueo", 0);

	// write (1, "\n", 1);
	// write (1, "ft_strtrim\n", 11);
	// printf("ft_strtrim = %s\n", ft_strtrim("abcdba", "acb"));

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

	// t_list *l = ft_lstnew((void*)1);
	// ft_lstadd_front(&l, ft_lstnew((void*)2));
}
