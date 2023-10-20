NAME	 = minitalk
SERVER	 = server
CLIENT	 = client
INC_DIR	 = includes
CC		 = cc
CFLAGS	 = -Wall -Werror -Wextra
PRINTF = ft_printf/libftprintf.a
LIB		 = -L ft_printf -lftprintf

SERVER_SRCS = server.c\
utils.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT_SRCS = client.c\
utils.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(PRINTF) $(CLIENT) $(SERVER)

$(SERVER): $(SERVER_OBJS)
	$(CC) -I$(INC_DIR) $(LIB) -o $@ $^

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -I$(INC_DIR) $(LIB) -o $@ $^

$(PRINTF):
	@make -C ft_printf

%.o: %.c  $(INC_DIR)/ft_minitalk.h
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@make clean -C ft_printf
	@rm -f $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	@make fclean -C ft_printf
	@rm -f $(SERVER) $(CLIENT)

bonus: all

re: fclean all

.PHONY: all clean fclean re bonus
