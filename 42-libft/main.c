/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesawada <kesawada@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:44:25 by kesawada          #+#    #+#             */
/*   Updated: 2023/09/22 14:09:57 by kesawada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

char    nibai(unsigned int index, char c)
{
    c = index * c;
    return (c);
}

int	main(void)
{
	write (1, "ft_isalpha\n", 11);
	printf("c = %c, %d\n", 'a', ft_isalpha('a'));
	printf("c = %c, %d\n", 'a' - 1, ft_isalpha('a' - 1));
	printf("c = %c, %d\n", 'z', ft_isalpha('z'));
	printf("c = %c, %d\n", 'z' - 1, ft_isalpha('z' + 1));

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

	/*
	write (1, "\n", 1);
	write (1, "ft_memcpy\n", 11);
	printf("c = %s, %d\n", "", ft_memcpy(""));
	printf("c = %s, %d\n", "aie", ft_memcpy("aie"));
	printf("c = %s, %d\n", "weoifa", ft_memcpy("weoifa"));
	printf("c = %s, %d\n", "efwahf21893jfa", ft_memcpy("efwahf21893jfa"));
	*/

	write (1, "\n", 1);
	write (1, "ft_strchr\n", 11);
	printf("c = %s, %s\n", "\0", ft_strchr("aiueo", '\0') - 1);

	write (1, "\n", 1);
	write (1, "ft_strnstr\n", 11);
	printf("c = %s, %s\n", "a", ft_strnstr("abbbcdefg", "bbc", 20));

	write (1, "\n", 1);
	write (1, "ft_substr\n", 11);
	printf("c = %s, %s\n", "a", ft_substr("abcde", 1, 0));

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
	printf("c = %s, %d\n", "\0", memcmp(d, f, 100));

	const char	str1[] = "hello world !";
	const char	str2[] = "l r";
	write (1, "\n", 1);
	write (1, "ft_strncmp\n", 11);
	printf("c = %s, %d\n", "\0", ft_strncmp(str1, str2, 4));
	printf("c = %s, %d\n", "\0", strncmp(str1, str2, 4));

	write (1, "\n", 1);
	write (1, "ft_split\n", 11);
	char	**result = ft_split("hello world ", 'o');
	int i = 0;
	while (i < 3)
	{
		printf("result[%d] = %s\n", i, result[i]);
		i++;
	}

	write (1, "\n", 1);
	write (1, "ft_itoa\n", 8);
	printf("ft_itoa: %s\n", ft_itoa(INT_MIN));

	write (1, "\n", 1);
	write (1, "ft_substr\n", 11);
	printf("c = %s, %s\n", "a", ft_substr("abcde", 5, 5));
	
	// write (1, "\n", 1);
	// write (1, "ft_strmapi\n", 11);
	// printf("ft_strmapi: %s\n", ft_strmapi("abcde", nibai));

	write (1, "\n", 1);
	write (1, "ft_strchr\n", 11);
	printf("c = %s, %s\n", "\0", ft_strchr("aiueo", 'i'));

	ft_putchar_fd('a', 0);
	ft_putstr_fd("aiueo", 0);
	ft_putendl_fd("aiueo", 0);

	write (1, "\n", 1);
	write (1, "ft_strtrim\n", 11);
	printf("ft_strtrim = %s\n", ft_strtrim("abcde", "d"));
	
	// write (1, "\n", 1);
	// write (1, "ft_strtrim\n", 11);
	// printf("ft_strtrim = %s\n", ft_strtrim("aiueo", "ie"));
	
	// while (1)
	// {
		
	// }
}
