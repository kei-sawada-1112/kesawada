CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -g -fsanitize=address
ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += $(DEBUGFLAGS)
endif

IFLAGS = -I$(INC_DIR)
NAME = libftprintf.a
INC_DIR = includes
SRC_DIR = srcs

LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a

VALUE_HANDLER_DIR = value_handler
VALUE_HANDLERS = $(SRC_DIR)/$(VALUE_HANDLER_DIR)/value_handler.c\

CONVERTER_DIR = converter
CONVERTERS = $(SRC_DIR)/$(CONVERTER_DIR)/hex_converter.c\

PROCESSOR_DIR = processor
PROCESSORS = $(SRC_DIR)/$(PROCESSOR_DIR)/process.c\
$(SRC_DIR)/$(PROCESSOR_DIR)/process2.c\

GETTER_DIR = getter
GETTERS = $(SRC_DIR)/$(GETTER_DIR)/get_value.c\
$(SRC_DIR)/$(GETTER_DIR)/get_value2.c\

UTILS_DIR = utils
UTILS = $(SRC_DIR)/$(UTILS_DIR)/utils.c\

WRITER_DIR = writer
WRITER = $(SRC_DIR)/$(WRITER_DIR)/putstr_and_padding.c

SRCS = ft_printf.c\
$(VALUE_HANDLERS)\
$(CONVERTERS)\
$(PROCESSORS)\
$(GETTERS)\
$(WRITER)\
$(UTILS)\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(INC_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@if [ ! -e $(NAME) ]; then \
        cp $(LIBFT) $(NAME); \
	fi
	ar rcs $@ $(OBJS)

bonus: all

debug: fclean bonus

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus debug
