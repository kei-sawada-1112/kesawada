NAME	= minitalk
SERVER		= server
CLIENT		= client
INC_DIR		= includes
SRC_DIR 	= srcs
OBJ_DIR 	= objs
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
DEBUG_FLAGS = -g -fsanitize=address
ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += $(DEBUG_FLAGS)
endif
PRINTF_DIR  = ft_printf
PRINTF  	= $(PRINTF_DIR)/libftprintf.a
LIB			= -L ft_printf -lftprintf

SERVER_SRCS = $(SRC_DIR)/server.c\
$(SRC_DIR)/utils.c\
$(SRC_DIR)/utils2.c
SERVER_OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SERVER_SRCS:.c=.o)))
TMP_SERVER_OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SERVER_SRCS:.c=.o)))

BSERVER_SRCS = $(SRC_DIR)/server_bonus.c\
$(SRC_DIR)/utils_bonus.c\
$(SRC_DIR)/utils2_bonus.c
BSERVER_OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(BSERVER_SRCS:.c=.o)))

CLIENT_SRCS = $(SRC_DIR)/client.c\
$(SRC_DIR)/utils.c
CLIENT_OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(CLIENT_SRCS:.c=.o)))
TMP_CLIENT_OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(CLIENT_SRCS:.c=.o)))

BCLIENT_SRCS = $(SRC_DIR)/client_bonus.c\
$(SRC_DIR)/utils_bonus.c
BCLIENT_OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(BCLIENT_SRCS:.c=.o)))

ifeq ($(MAKECMDGOALS), bonus)
	SERVER_OBJS = $(BSERVER_OBJS)
	CLIENT_OBJS = $(BCLIENT_OBJS)
endif

vpath %.c\
$(SRC_DIR)

all: $(NAME)

$(NAME): $(PRINTF) $(OBJ_DIR) $(CLIENT) $(SERVER)
	@if [ "$(MAKECMDGOALS)" = "" ]; then \
		if [ -e $(OBJ_DIR)/server_bonus.o ]; then \
			rm $(BSERVER_OBJS) $(OBJ_DIR)/client_bonus.o; \
		fi; \
	elif [ "$(MAKECMDGOALS)" = "bonus" ]; then \
		if [ -e $(OBJ_DIR)/server.o ]; then \
			rm $(TMP_SERVER_OBJS) $(OBJ_DIR)/client.o; \
		fi; \
	fi

$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(LIB) -o $@ $^

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(LIB) -o $@ $^

$(PRINTF):
	@make $(MAKECMDGOALS) -C ft_printf

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c  $(INC_DIR)/ft_minitalk.h $(INC_DIR)/ft_minitalk_bonus.h
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@make clean -C ft_printf
	@rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(BSERVER_OBJS) $(BCLIENT_OBJS)

fclean: clean
	@make fclean -C ft_printf
	@rm -f $(SERVER) $(CLIENT)

bonus: all

debug: fclean all

re: fclean all

.PHONY: all clean fclean re bonus $(PRINTF)
