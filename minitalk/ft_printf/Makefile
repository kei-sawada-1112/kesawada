CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -g -fsanitize=address
ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += $(DEBUGFLAGS)
endif

IFLAGS = -I$(INC_DIR)
NAME = libftprintf.a
INC_DIR = srcs
SRC_DIR = srcs
OBJ_DIR = objs

LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a

VALUE_HANDLER_DIR = $(SRC_DIR)/value_handler
VALUE_HANDLERS = $(VALUE_HANDLER_DIR)/value_handler.c
BVALUE_HANDLERS = $(VALUE_HANDLER_DIR)/value_handler_bonus.c\

CONVERTER_DIR = $(SRC_DIR)/converter
CONVERTERS = $(CONVERTER_DIR)/hex_converter.c
BCONVERTERS = $(CONVERTER_DIR)/hex_converter_bonus.c\

PROCESSOR_DIR = $(SRC_DIR)/processor
PROCESSORS = $(PROCESSOR_DIR)/process.c\
$(PROCESSOR_DIR)/process2.c
BPROCESSORS = $(PROCESSOR_DIR)/process_bonus.c\
$(PROCESSOR_DIR)/process2_bonus.c\

GETTER_DIR = $(SRC_DIR)/getter
GETTERS = $(GETTER_DIR)/get_value.c\
$(GETTER_DIR)/get_value2.c
BGETTERS = $(GETTER_DIR)/get_value_bonus.c\
$(GETTER_DIR)/get_value2_bonus.c\

UTILS_DIR = $(SRC_DIR)/utils
UTILS = $(UTILS_DIR)/utils.c
BUTILS = $(UTILS_DIR)/utils_bonus.c\

WRITER_DIR = $(SRC_DIR)/writer
WRITER = $(WRITER_DIR)/putstr_and_padding.c
BWRITER = $(WRITER_DIR)/putstr_and_padding_bonus.c

SRCS = ft_printf.c\
$(VALUE_HANDLERS)\
$(CONVERTERS)\
$(PROCESSORS)\
$(GETTERS)\
$(UTILS)\
$(WRITER)\

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
TMP_OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

BSRCS = ft_printf_bonus.c\
$(BVALUE_HANDLERS)\
$(BCONVERTERS)\
$(BPROCESSORS)\
$(BGETTERS)\
$(BUTILS)\
$(BWRITER)\

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

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@if [ ! -e $(NAME) ]; then \
		cp $(LIBFT) $(NAME); \
	fi
	@if [ "$(MAKECMDGOALS)" = "" ]; then \
		if ar t $(NAME) | grep -q ft_printf_bonus.o; then \
			ar d $(NAME) $(notdir $(BOBJS)); \
			rm $(BOBJS); \
		fi; \
	elif [ "$(MAKECMDGOALS)" = "bonus" ]; then \
		if ar t $(NAME) | grep -q ft_printf.o; then \
			ar d $(NAME) $(notdir $(TMP_OBJS)); \
			rm $(TMP_OBJS); \
		fi; \
	fi
	ar rcs $@ $(OBJS)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

bonus: all

debug: fclean bonus

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS) $(BOBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus debug $(LIBFT)
