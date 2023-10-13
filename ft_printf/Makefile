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

VALUE_HANDLER_DIR = value_handler
BONUS_VALUE_HANDLERS = $(SRC_DIR)/$(VALUE_HANDLER_DIR)/value_handler_bonus.c\

CONVERTER_DIR = converter
BONUS_CONVERTERS = $(SRC_DIR)/$(CONVERTER_DIR)/hex_converter_bonus.c\

PROCESSOR_DIR = processor
BONUS_PROCESSORS = $(SRC_DIR)/$(PROCESSOR_DIR)/process_bonus.c\
$(SRC_DIR)/$(PROCESSOR_DIR)/process2_bonus.c\

GETTER_DIR = getter
BONUS_GETTERS = $(SRC_DIR)/$(GETTER_DIR)/get_value_bonus.c\
$(SRC_DIR)/$(GETTER_DIR)/get_value2_bonus.c\

UTILS_DIR = utils
BONUS_UTILS = $(SRC_DIR)/$(UTILS_DIR)/utils_bonus.c\
$(SRC_DIR)/$(UTILS_DIR)/utils2_bonus.c\
$(SRC_DIR)/$(UTILS_DIR)/utils3_bonus.c\
$(SRC_DIR)/$(UTILS_DIR)/utils4_bonus.c

WRITER_DIR = writer
BONUS_WRITER = $(SRC_DIR)/$(WRITER_DIR)/putstr_and_padding_bonus.c

SRCS = ft_printf.c\
ft_putfunc.c\
ft_putfunc2.c

BONUS_SRCS = ft_printf_bonus.c\
$(BONUS_VALUE_HANDLERS)\
$(BONUS_CONVERTERS)\
$(BONUS_PROCESSORS)\
$(BONUS_GETTERS)\
$(BONUS_UTILS)\
$(BONUSWRITER)\

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
ifeq ($(MAKECMDGOALS), bonus)
	OBJS += $(BONUS_OBJS)
endif

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^

#$(NAME): $(OBJS)
#	$(CC) $(CFLAGS) $(IFLAGS) $^ -o $@

bonus: all

debug: fclean bonus

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus debug
