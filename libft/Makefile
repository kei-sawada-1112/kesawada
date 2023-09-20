CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
NAME = libft.a
SRC = srcs
INC = includes
SRCS = $(SRC)/ft_alphabet.c $(SRC)/ft_string.c $(SRC)/ft_string2.c $(SRC)/ft_string3.c $(SRC)/ft_string4.c $(SRC)/ft_string5.c $(SRC)/ft_string6.c $(SRC)/ft_string7.c $(SRC)/ft_string8.c $(SRC)/ft_memory.c $(SRC)/ft_memory2.c $(SRC)/ft_ctype.c $(SRC)/ft_ctype2.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean:
	rm -r $(OBJS)

fclean: clean
	rm -r $(NAME)

re: fclean all

.PHONY: all clean fclean re
