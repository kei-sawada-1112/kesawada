CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -g -fsanitize=address
ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += $(DEBUGFLAGS)
endif

IFLAGS = -I$(INC_DIR)
NAME = libftprintf.a
INC_DIR = src
SRC_DIR = src
OBJ_DIR = obj

LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a

VALUE_HANDLER_DIR = $(SRC_DIR)/value_handler
VALUE_HANDLERS = $(VALUE_HANDLER_DIR)/value_handler.c\

CONVERTER_DIR = $(SRC_DIR)/converter
CONVERTERS = $(CONVERTER_DIR)/hex_converter.c\

PROCESSOR_DIR = $(SRC_DIR)/processor
PROCESSORS = $(PROCESSOR_DIR)/process.c\
$(PROCESSOR_DIR)/process2.c\

GETTER_DIR = $(SRC_DIR)/getter
GETTERS = $(GETTER_DIR)/get_value.c\
$(GETTER_DIR)/get_value2.c\

UTILS_DIR = $(SRC_DIR)/utils
UTILS = $(UTILS_DIR)/utils.c\

WRITER_DIR = $(SRC_DIR)/writer
WRITER = $(WRITER_DIR)/putstr_and_padding.c

COMMON_SRCS = $(VALUE_HANDLERS)\
$(CONVERTERS)\
$(PROCESSORS)\
$(GETTERS)\
$(UTILS)\
$(WRITER)\

SRCS = $(COMMON_SRCS) \
ft_printf.c

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

BSRCS = $(COMMON_SRCS) \
ft_printf_bonus.c

BOBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(BSRCS:.c=.o)))

ifeq ($(MAKECMDGOALS), bonus)
	OBJS = $(BOBJS)
endif

vpath %.c \
$(SRC_DIR) \
$(VALUE_HANDLER_DIR) \
$(CONVERTER_DIR) \
$(PROCESSOR_DIR) \
$(GETTER_DIR) \
$(WRITER_DIR) \
$(UTILS_DIR)

all: $(LIBFT) $(OBJ_DIR) $(NAME)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@if [ ! -e $(NAME) ]; then \
        cp $(LIBFT) $(NAME); \
	fi
	@if [ "$(MAKECMDGOALS)" = "" ]; then \
		if ar t $(NAME) | grep -q ft_printf_bonus.o; then \
			ar d $(NAME) ft_printf_bonus.o; \
			rm $(OBJ_DIR)/ft_printf_bonus.o; \
		fi; \
	elif [ "$(MAKECMDGOALS)" = "bonus" ]; then \
		if ar t $(NAME) | grep -q ft_printf.o; then \
			ar d $(NAME) ft_printf.o; \
			rm $(OBJ_DIR)/ft_printf.o; \
		fi; \
	fi
	ar rcs $@ $(OBJS)

bonus: all

$(OBJ_DIR):
	@makdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

debug: fclean bonus

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS) $(BOBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus debug
