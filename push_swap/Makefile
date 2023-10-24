CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -g -fsanitize=address
ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += $(DEBUGFLAGS)
endif

IFLAGS  = -I$(INC_DIR)
NAME 	= push_swap
INC_DIR = includes
SRC_DIR = srcs
OBJ_DIR = objs

PRINTF_DIR = ft_printf
PRINTF = ${PRINTF_DIR}/libftprintf.a
LIB = -L $(PRINTF_DIR) -lftprintf

PROCESS_DIR = $(SRC_DIR)/processes
PROCESSES = $(PROCESS_DIR)/a_to_b.c\
$(PROCESS_DIR)/quick_sort_b.c\

UTILS_DIR = $(SRC_DIR)/utils
UTILS = $(UTILS_DIR)/stack_utils.c\
$(UTILS_DIR)/stack_utils2.c\
$(UTILS_DIR)/stack_utils3.c\
$(UTILS_DIR)/median_utils2.c\
$(UTILS_DIR)/move_utils.c\
$(UTILS_DIR)/move_utils2.c\
$(UTILS_DIR)/move_utils3.c\

BUTILS = $(UTILS_DIR)/utils_bonus.c

SRCS = $(SRC_DIR)/push_swap.c\
$(UTILS)\
$(PROCESSES)\

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
TMP_OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

BSRCS = $(SRC_DIR)/push_swap_bonus.c\
$(BUTILS)\

BOBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(BSRCS:.c=.o)))

ifeq ($(MAKECMDGOALS), bonus)
	OBJS = $(BOBJS)
endif

vpath %.c \
$(SRC_DIR) \
$(UTILS_DIR) \
$(PROCESS_DIR) \

all: $(PRINTF) $(OBJ_DIR) $(NAME)

$(PRINTF):
	@if [ "$(MAKECMDGOALS)" = "debug" ]; then \
		make debug -C $(PRINTF_DIR); \
	else \
		make -C $(PRINTF_DIR); \
	fi

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@if [ "$(MAKECMDGOALS)" = "" ]; then \
		if find $(OBJ_DIR) utils_bonus.o > /dev/null 2>&1; then \
			rm $(BOBJS); \
		fi; \
	elif [ "$(MAKECMDGOALS)" = "bonus" ]; then \
		if find $(OBJ_DIR) utils.o > /dev/null 2>&1; then \
			rm $(TMP_OBJS); \
		fi; \
	fi
	$(CC) $(CFLAGS) $(LIB) $^ -o $@

$(OBJ_DIR)/%.o: %.c $(INC_DIR)/push_swap.h
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

bonus: all

debug: all

clean:
	@make -C $(PRINTF_DIR) clean
	@rm -f $(OBJS) $(BOBJS)

fclean: clean
	@make -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus debug $(PRINTF)
