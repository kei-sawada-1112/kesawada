CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -g -fsanitize=address
ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += $(DEBUGFLAGS)
endif

NAME = libftprintf.a
INC_DIR = srcs
SRC_DIR = srcs
OBJ_DIR = objs
IFLAGS = -I$(INC_DIR)

LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a

VALUE_HANDLER_DIR = $(SRC_DIR)/value_handler
VALUE_HANDLERS = $(VALUE_HANDLER_DIR)/value_handler.c

CONVERTER_DIR = $(SRC_DIR)/converter
CONVERTERS = $(CONVERTER_DIR)/hex_converter.c

PROCESSOR_DIR = $(SRC_DIR)/processor
PROCESSORS = $(PROCESSOR_DIR)/process.c\
$(PROCESSOR_DIR)/process2.c

GETTER_DIR = $(SRC_DIR)/getter
GETTERS = $(GETTER_DIR)/get_value.c\
$(GETTER_DIR)/get_value2.c

UTILS_DIR = $(SRC_DIR)/utils
UTILS = $(UTILS_DIR)/utils.c

WRITER_DIR = $(SRC_DIR)/writer
WRITER = $(WRITER_DIR)/putstr_and_padding.c

SRCS = ft_printf.c\
$(VALUE_HANDLERS)\
$(CONVERTERS)\
$(PROCESSORS)\
$(GETTERS)\
$(UTILS)\
$(WRITER)\

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c \
$(SRC_DIR) \
$(VALUE_HANDLER_DIR) \
$(CONVERTER_DIR) \
$(PROCESSOR_DIR) \
$(GETTER_DIR) \
$(WRITER_DIR) \
$(UTILS_DIR)

all: $(LIBFT) $(OBJ_DIR) $(NAME)

$(LIBFT):
	@if [ "$(MAKECMDGOALS)" = "debug" ]; then \
		make debug -C $(LIBFT_DIR); \
	else \
		make -C $(LIBFT_DIR); \
	fi

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@if [ ! -e $(NAME) ]; then \
        cp $(LIBFT) $(NAME); \
	fi
	ar rcs $@ $(OBJS)

$(OBJ_DIR)/%.o: %.c $(INC_DIR)/ft_printf.h
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

debug: all

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug $(LIBFT)
