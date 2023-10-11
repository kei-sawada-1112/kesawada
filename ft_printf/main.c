#include "ft_printf.h"

int	main(void)
{
	// スペース+数値のパターンがテストにない
	// %012s　みたいのもない?
	// それぞれの変数にNULL入れるパターン
	// 16以上でバグる
	// void *str = 0x1903150;
	ft_printf("%-3bd");
	printf("\n");
	printf("%-3bd");
	// ft_printf(" %1c %2c %3c\n", '0', 0, '1');
	// ft_printf(" %-1c %-2c %-3c\n", '0', 0, '1');
	// printf(" %1c %2c %3c\n", '0', 0, '1');
	// printf(" %-1c %-2c %-3c\n", '0', 0, '1');
	// ft_printf(" %#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// printf(" %#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	// ft_printf(" %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// char	*c = "aiueo";
	// ft_printf("str: %s, addr: %p", c, c);
	// unsigned int num = 123456;
	// int num = INT_MAX;
	// char *str = "12345";
	// ft_printf("aiueo%%sa\n");
	// printf("aiueo%%sa\n");
	// i = ft_printf("aiueo%ca\n", 0);
	// ft_printf("p: %p\n", 0);
	// printf("p: %p\n", 0);
	// i = printf("aiueo%ca\n", 0);
	// ft_printf("i: %d\n", i);
	// printf("aiueo%ca\n", 0);

	// ft_printf("aiueo%p\n", str);
	// printf("aiueo%p\n", str);

// 	// ft_printf("aaa%#15Xbbb\n", num);
// 	// printf("aaa%#15Xbbb\n", num);

// 	// ft_printf("aaa%100dbbb\n", num);
// 	// printf("aaa%100dbbb\n", num);

	//system("leaks a.out");
}
