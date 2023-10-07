CC = cc
#CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I$(INC_DIR)
NAME = libftprintf.a

LIBFT_DIR = libft

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
$(SRC_DIR)/$(CONVERTER_DIR)/ft_uitoa.c\

PROCESSORS = $(SRC_DIR)/$(PROCESSOR_DIR)/process.c\
$(SRC_DIR)/$(PROCESSOR_DIR)/process2.c\

GETTERS = $(SRC_DIR)/$(GETTER_DIR)/get_value.c\
$(SRC_DIR)/$(GETTER_DIR)/get_value2.c\

COBJS = $(LIBFT_DIR)/ft_atoi.o\
$(LIBFT_DIR)/ft_bzero.o\
$(LIBFT_DIR)/ft_calloc.o\
$(LIBFT_DIR)/ft_isdigit.o\
$(LIBFT_DIR)/ft_itoa.o\
$(LIBFT_DIR)/ft_memcpy.o\
$(LIBFT_DIR)/ft_memset.o\
$(LIBFT_DIR)/ft_strchr.o\
$(LIBFT_DIR)/ft_strdup.o\
$(LIBFT_DIR)/ft_strjoin.o\
$(LIBFT_DIR)/ft_strlcat.o\
$(LIBFT_DIR)/ft_strlcpy.o\
$(LIBFT_DIR)/ft_strlen.o\

SRCS = ft_printf.c\
$(HANDLERS)\
$(BUFFER_HANDLERS)\
$(CONVERTERS)\
$(PROCESSORS)\
$(GETTERS)\

OBJS = $(SRCS:.c=.o) $(COBJS)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^
	ranlib $@

bonus: all

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
