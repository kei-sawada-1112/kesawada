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

SRCS = ft_printf.c\
$(SRC_DIR)/$(HANDLER_DIR)/op_handler.c\
$(SRC_DIR)/$(HANDLER_DIR)/op_handler2.c\
$(SRC_DIR)/$(CONVERTER_DIR)/hex_converter.c\

OBJS = $(SRCS:.c=.o)
BONUS =
BOBJS = $(BONUS:.c=.o)
ifdef WITH_BONUS
OBJS += $(BOBJS)
endif

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^
	ranlib $@

bonus: $(NAME)
	@make WITH_BONUS=1

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
