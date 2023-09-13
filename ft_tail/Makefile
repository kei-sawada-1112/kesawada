CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
NAME = ft_tail
SRC = srcs
INC = includes
SRCS = $(SRC)/main.c $(SRC)/ft_func.c $(SRC)/ft_func2.c $(SRC)/ft_func3.c $(SRC)/ft_tail.c $(SRC)/ft_tail_func.c $(SRC)/memory.c $(SRC)/file_controller.c $(SRC)/display_contents.c $(SRC)/parse_options.c $(SRC)/useful_func.c
OBJS = $(SRCS:.c=.o)
HEADERS = $(INC)/ft_tail.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INC) $(OBJS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean:
	rm -r $(OBJS)

fclean: clean
	rm -r $(NAME)

re: fclean all

.PHONY: all clean fclean re
