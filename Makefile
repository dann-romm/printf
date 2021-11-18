CC			= gcc
AR			= ar
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
ARFLAGS		= rcs

NAME		= libftprintf.a

LIBFTDIR	= ./libft
LIBFTNAME	= $(LIBFTDIR)/libft.a
LIBFTHEADER	= $(LIBFTDIR)/libft.h

SRCDIR		= ./srcs/
SRC			= ft_printf.c handle_flags.c write_argument.c \
	utils_int_hex.c utils_write.c utils_str.c \
	print_decimal.c print_char.c print_str.c \
	print_hex.c print_pointer.c print_percent.c
CFILES		= $(addprefix $(SRCDIR), $(SRC))
OBJ			= $(CFILES:.c=.o)

all: $(NAME)

$(LIBFTNAME): $(LIBFTHEADER)
	make bonus -C $(LIBFTDIR)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -MMD -O2

$(NAME): $(OBJ) $(LIBFTNAME)
	cp $(LIBFTNAME) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

clean:
	make clean -C $(LIBFTDIR)
	$(RM) $(patsubst %.c, %.d, $(CFILES))
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFTDIR)
	$(RM) $(LIBFTNAME)
	$(RM) $(NAME)

re: fclean all

bonus: $(NAME)

-include $(patsubst %.o, %.d, $(OBJ))

.PHONY: all bonus clean fclean re
