CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=2147483647
NAME = get_next_line

SRCS = get_next_line.c\
get_next_line_utils.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
