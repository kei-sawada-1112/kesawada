CC = cc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I$(INC_DIR)
NAME = libftprintf.a

LIBFT_DIR = lib
LIBFT = $(LIBFT_DIR)/libft.a

INC_DIR = includes
SRC_DIR = srcs
HANDLER_DIR = op_handler
CONVERTER_DIR = converter
PROCESSOR_DIR = processor
BUFFER_HANDLER_DIR = buffer_handler
GETTER_DIR = getter

HANDLERS = $(SRC_DIR)/$(HANDLER_DIR)/op_handler.c\

BUFFER_HANDLERS = $(SRC_DIR)/$(BUFFER_HANDLER_DIR)/buffer_handler.c\

CONVERTERS = $(SRC_DIR)/$(CONVERTER_DIR)/hex_converter.c\

PROCESSORS = $(SRC_DIR)/$(PROCESSOR_DIR)/process.c\
$(SRC_DIR)/$(PROCESSOR_DIR)/process2.c\

GETTERS = $(SRC_DIR)/$(GETTER_DIR)/get_value.c

SRCS = ft_printf.c\
$(HANDLERS)\
$(BUFFER_HANDLERS)\
$(CONVERTERS)\
$(PROCESSORS)\
$(GETTERS)\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^
	ranlib $@

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
