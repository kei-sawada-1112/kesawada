/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei <kei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:44:25 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/25 10:26:49 by kei              ###   ########.fr       */
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

// ANSI escape codes
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

void	checker(int result) {
	if (result) {
		printf(GREEN "OK" RESET "\n");
    } else {
		printf(RED "NG" RESET "\n");
	}
}

int	main(void)
{
	write (1, "ft_isalpha\n", 11);
	checker(ft_isalpha('a') == 1);
	checker(ft_isalpha('a' - 1) == 0);
	checker(ft_isalpha('z') == 1);
	checker(ft_isalpha('z' + 1) == 0);

	write (1, "\n", 1);
	write (1, "ft_isdigit\n", 11);
	printf("c = %c, %d\n", '0', ft_isdigit('0'));
	printf("c = %c, %d\n", '0' - 1, ft_isdigit('0' - 1));
	printf("c = %c, %d\n", '9', ft_isdigit('9'));
	printf("c = %c, %d\n", '9' + 1, ft_isdigit('9' + 1));

	write (1, "\n", 1);
	write (1, "ft_isalnum\n", 11);
	printf("c = %c, %d\n", '0', ft_isalnum('0'));
	printf("c = %c, %d\n", '0' - 1, ft_isalnum('0' - 1));
	printf("c = %c, %d\n", '9', ft_isalnum('9'));
	printf("c = %c, %d\n", '9' + 1, ft_isalnum('9' + 1));

	write (1, "\n", 1);
	write (1, "ft_isascii\n", 11);
	printf("c = %c, %d\n", -1, ft_isascii(-1));
	printf("c = %c, %d\n", 31, ft_isascii(31));
	printf("c = %c, %d\n", 32, ft_isascii(32));
	printf("c = %c, %d\n", 128, ft_isascii(128));

	write (1, "\n", 1);
	write (1, "ft_isprint\n", 11);
	printf("c = %c, %d\n", -1, ft_isprint(-1));
	printf("c = %c, %d\n", 31, ft_isprint(31));
	printf("c = %c, %d\n", 32, ft_isprint(32));
	printf("c = %c, %d\n", 128, ft_isprint(128));

	write (1, "\n", 1);
	write (1, "ft_strlen\n", 11);
	printf("c = %s, %zu\n", "", ft_strlen(""));
	printf("c = %s, %zu\n", "aie", ft_strlen("aie"));
	printf("c = %s, %zu\n", "weoifa", ft_strlen("weoifa"));
	printf("c = %s, %zu\n", "efwahf21893jfa", ft_strlen("efwahf21893jfa"));

	write (1, "\n", 1);
	write (1, "ft_memcpy\n", 11);
	char	dst[100];
	char	*src = NULL;
	size_t	n = 0;
	printf("dst = %s\n", (char *)ft_memcpy(dst, NULL, n));
	//printf("dst = %s\n", (char *)memcpy(dst, NULL, n));


	write (1, "\n", 1);
	write (1, "ft_strchr\n", 11);
	printf("c = %s, %s\n", "\0", ft_strchr("aiueo", '\0') - 1);

	write (1, "\n", 1);
	write (1, "ft_strnstr\n", 11);
	printf("c = %s, %s\n", "a", ft_strnstr("abbbcdefg", "bbc", 20));

	write (1, "\n", 1);
	printf("ft_substr = %s\n", ft_substr("BONJOUR LES HARICOTS !", 8, 14));

	write (1, "\n", 1);
	write (1, "ft_strlcat\n", 11);
	printf("c = %s, %zu\n", "a", ft_strlcat("abcde", "123", 3));

	write (1, "\n", 1);
	write (1, "ft_strjoin\n", 11);
	printf("c = %s, %s\n", "a", ft_strjoin("aiueo", "12345"));

	write (1, "\n", 1);
	write (1, "ft_strrchr\n", 11);
	printf("c = %s, %s\n", "\0", ft_strrchr("aiueo", '\0'));

	int		d[] = {1, 2, 3};
	int		f[] = {1, 2, 2};

	write (1, "\n", 1);
	write (1, "ft_memcmp\n", 11);
	printf("c = %s, %d\n", "\0", ft_memcmp(d, f, 100));
	//printf("c = %s, %d\n", "\0", memcmp(d, f, 100));

	const char	str1[] = "hello world !";
	const char	str2[] = "l r";
	write (1, "\n", 1);
	write (1, "ft_strncmp\n", 11);
	printf("c = %s, %d\n", "\0", ft_strncmp(str1, str2, 4));
	printf("c = %s, %d\n", "\0", strncmp(str1, str2, 4));

	write (1, "\n", 1);
	write (1, "ft_split\n", 11);
	char	**result = ft_split("  Tripo uille  ", ' ');
	int i = 0;
	while (i < 3)
	{
		printf("result[] = %s\n", result[0]);
		i++;
	}

	write (1, "\n", 1);
	write (1, "ft_itoa\n", 8);
	printf("ft_itoa: %s\n", ft_itoa(INT_MIN));

	write (1, "\n", 1);
	write (1, "ft_substr\n", 11);
	printf("c = %s, %s\n", "a", ft_substr("abcde", 5, 5));

	write (1, "\n", 1);
	write (1, "ft_strmapi\n", 11);
	printf("ft_strmapi: %s\n", ft_strmapi("abcde", nibai));

	write (1, "\n", 1);
	write (1, "ft_strchr\n", 11);
	printf("c = %s, %s\n", "\0", ft_strchr("aiueo", 'i'));

	ft_putchar_fd('a', 0);
	ft_putstr_fd("aiueo", 0);
	ft_putendl_fd("aiueo", 0);

	write (1, "\n", 1);
	write (1, "ft_strtrim\n", 11);
	printf("ft_strtrim = %s\n", ft_strtrim("abcdba", "acb"));

	write (1, "\n", 1);
	write (1, "ft_putendl_fd\n", 11);
	int fd = open("test", O_WRONLY);
	ft_putendl_fd("12345", fd);

	write (1, "\n", 1);
	write (1, "ft_calloc\n", 11);
	ft_calloc(INT_MIN, INT_MIN);
	//calloc(INT_MIN, INT_MIN);

	/*---------- リークが後検出される件について----------- */
	// 4611686014132420609 は INT_MAX * INT_MAX。
	// INT_MIN を size_t として出力すると、このように判定される↓
	// printf("%zu\n", INT_MIN) → INT_MAX
	// まさかの INT_MAX の値が出力される。int として符号を消す処理が先に行われたのちに出力されるようだ。
	// しかし関数の引数として与えた場合は、size_tにキャストした後に符号がなくなり、SIZE_MAX + INT_MIN の馬鹿でかい値として処理される。
	// おそらくメモリリークのテスターは INT_MIN が INT_MAX に変換されると判断しており、INT_MAX * INT_MAX は SIZE_MAX をこえずにメモリを確保するものとしている。
	// 一方、実際の関数内では SIZE_MAX を超えると判定され、NULL が返される。これは正しい挙動であり機械判定でもOKがでる。
	// つまりリークを判定する関数内では、INT_MIN が INT_MAX に変換されると判定している可能性が非常に高い。
	// よってこのエラーは実際の関数内での挙動とは異なる判定をしており、無視して良いはず。

	write (1, "\n", 1);
	write (1, "ft_putnbr_fd\n", 11);
	fd = open("test", O_RDWR | O_CREAT, 0777);
	char s[42];
	ft_putnbr_fd(10, fd);

	t_list *l = ft_lstnew((void*)1);
	ft_lstadd_front(&l, ft_lstnew((void*)2));
}
