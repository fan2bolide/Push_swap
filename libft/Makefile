NAME = libft.a

SRC			=	ft_atoi.c			\
				ft_bzero.c			\
				ft_calloc.c			\
				ft_isalnum.c		\
				ft_isalpha.c		\
				ft_isascii.c		\
				ft_isdigit.c		\
				ft_isprint.c		\
				ft_isset.c			\
				ft_isspace.c		\
				ft_itoa.c			\
				ft_memalloc.c		\
				ft_memccpy.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_memcpy.c			\
				ft_memdel.c			\
				ft_memmove.c		\
				ft_memset.c			\
				ft_putchar.c		\
				ft_putchar_fd.c		\
				ft_putendl.c		\
				ft_putendl_fd.c		\
				ft_putnbr.c			\
				ft_putnbr_fd.c		\
				ft_putstr.c			\
				ft_putstr_fd.c		\
				ft_split.c			\
				ft_strcat.c			\
				ft_strchr.c			\
				ft_strclr.c			\
				ft_strcmp.c			\
				ft_strcpy.c			\
				ft_strdel.c			\
				ft_strdup.c			\
				ft_strequ.c			\
				ft_striter.c		\
				ft_striteri.c		\
				ft_strjoin.c		\
				ft_strlcat.c		\
				ft_strlcpy.c		\
				ft_strlen.c			\
				ft_strmap.c			\
				ft_strmapi.c		\
				ft_strncat.c		\
				ft_strncmp.c		\
				ft_strncpy.c		\
				ft_strndup.c		\
				ft_strnequ.c		\
				ft_strnew.c			\
				ft_strnstr.c		\
				ft_strrchr.c		\
				ft_strstr.c			\
				ft_strtrim.c		\
				ft_substr.c			\
				ft_tolower.c		\
				ft_toupper.c		\
				ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstadd_back.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_lstpop_back.c	\
				ft_lstpop_front.c	\
				get_next_line.c		\
				get_next_line_utils.c\
				ft_print_hexa.c		\
				ft_printf.c			\
				ft_print_int.c		\
				ft_putnbr_base_unsigned.c\
				

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all	: $(NAME) 

$(NAME): $(OBJ) $(BONUS_OBJ)
	ar -rcs $(NAME) $(OBJ) $(BONUS_OBJ)

%.o : %.c Makefile libft.h
	cc -Wall -Wextra -Werror -c $<

clean:
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re