#include <stdlib.h>
#include "libft.h"

static int is_set_char(char c, const char *set)
{
    while (*set)
    {
        if (c == *set)
            return (1);
        set++;
    }
    return (0);
}

static int get_first(const char *s1, const char *set)
{
    int i;

    i = 0;
    while (s1[i] && is_set_char(s1[i], set))
        i++;
    return (i);
}

static int get_last(const char *s1, const char *set)
{
    int len;

    len = ft_strlen(s1) - 1;
    while (len >= 0 && is_set_char(s1[len], set))
        len--;
    return (len + 1);
}

char *ft_strtrim(char const *s1, char const *set)
{
    char *ret;
    int start;
    int end;
    int len;

    if (!s1 || !set)
        return (NULL);

    if (*set == '\0')
    {
        ret = (char *)malloc(ft_strlen(s1) + 1);
        if (ret)
            ft_strlcpy(ret, s1, ft_strlen(s1) + 1);
        return (ret);
	}
    start = get_first(s1, set);
    end = get_last(s1, set);
    len = end - start;

    if (len <= 0)
    {
        ret = (char *)malloc(1);
        if (ret)
            *ret = '\0';
        return (ret);
    }

    ret = (char *)malloc(len + 1);
    if (!ret)
        return (NULL);

    ft_memcpy(ret, s1 + start, len);
    ret[len] = '\0';
    return (ret);
}
