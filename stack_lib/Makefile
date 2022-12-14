# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 01:32:11 by bajeanno          #+#    #+#              #
#    Updated: 2022/12/14 02:06:59 by bajeanno         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = stack_lib.a

LIBFT_PATH = ../libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC			=	stack_print.c	\
				stack_utils.c	\
				stack_index.c	\
				instructions.c	\

OBJ = $(SRC:.c=.o)
DEPENDS        :=        $(SRC:.c=.d)

all	: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o : %.c Makefile
	cc -Wall -Wextra -Werror -c $< -MD -I $(LIBFT_PATH) -I .

clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(OBJ)
	rm -f $(DEPENDS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re lib

-include $(DEPENDS)