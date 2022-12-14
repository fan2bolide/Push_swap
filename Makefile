# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 07:25:14 by bajeanno          #+#    #+#              #
#    Updated: 2022/12/14 01:47:25 by bajeanno         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Werror -Wall -Wextra -o $(NAME) -I stack_lib -I libft/ -I .

DEBUG_FLAGS = -fsanitize=address -g3

LIBFT = libft/libft.a

STACK_LIB = stack_lib/stack_lib.a

SRC =	parsing.c push_swap_big.c push_swap_little.c push_swap.c

BONUS_SRC = push_swap_viewer.c

DEPENDS	:=	$(SRC:.c=.d)

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all : lib lib_stacks $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(STACK_LIB) $(FLAGS)

%.o : %.c Makefile
	cc -Wall -Wextra -Werror -c $< -MD -I stack_lib -I libft/ -I .

debug : lib
	$(CC) $(SRC) $(LIBFT) $(FLAGS) $(DEBUG_FLAGS)

lib : 
	$(MAKE) -C libft

lib_stacks :
	$(MAKE) -C stack_lib

run : all
	./a.out

clean :
	$(RM) $(OBJ) $(BONUS_OBJ) $(DEPENDS)
	$(RM) -r push_swap.dSYM
	$(MAKE) clean -C libft
	
fclean : clean
	$(RM) $(NAME)
	$(MAKE) fclean -C stack_lib
	$(MAKE) fclean -C libft

re : fclean all

.PHONY : all lib run re clean fclean

-include $(DEPENDS)