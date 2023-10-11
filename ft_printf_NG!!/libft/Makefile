CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
INC = ../includes
SRCS = ft_atoi.c\
ft_bzero.c\
ft_calloc.c\
ft_isdigit.c\
ft_itoa.c\
ft_memset.c\
ft_memcpy.c\
ft_putchar_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_putstr_fd.c\
ft_strchr.c\
ft_strdup.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_strlen.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
