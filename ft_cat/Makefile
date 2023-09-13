CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_cat
SRC = srcs
INC = includes
SRCS = $(SRC)/main.c $(SRC)/ft_func.c $(SRC)/ft_cat.c
OBJS = $(SRCS:.c=.o)
HEADERS = $(INC)/ft_cat.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INC) $(OBJS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
