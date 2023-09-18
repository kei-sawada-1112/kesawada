CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
SRC = srcs
INC = includes ../libft/includes
INC_FLAGS = $(addprefix -I,$(INC))
LIB = ../libft
NAME = ft_hexdump
SRCS = $(SRC)/ft_hexdump.c $(SRC)/ft_hexdump_func.c $(SRC)/display_lines.c $(SRC)/parse_options.c $(SRC)/main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC_FLAGS) -L$(LIB) -lft $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

clean:
	rm -r $(OBJS)

fclean: clean
	rm -r $(NAME)

re: fclean all

.PHONY: all clean fclean re
