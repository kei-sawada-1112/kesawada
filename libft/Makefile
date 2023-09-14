CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
NAME = libft
SRC = srcs
INC = includes
SRCS = $(SRC)/main.c $(SRC)/ft_alphabet.c $(SRC)/ft_checker.c $(SRC)/ft_string.c $(SRC)/ft_string2.c $(SRC)/ft_string3.c $(SRC)/ft_string4.c $(SRC)/ft_memory.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean:
	rm -r $(OBJS)

fclean: clean
	rm -r $(NAME)

re: fclean all

.PHONY: all clean fclean re
