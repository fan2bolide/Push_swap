# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 07:25:14 by bajeanno          #+#    #+#              #
#    Updated: 2023/01/24 01:22:56 by bajeanno         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Werror -Wall -Wextra -I stack_lib/headers -I libft/headers -I ./headers

DEBUG_FLAGS = -fsanitize=address -g3

LIBFT = libft/libft.a

STACK_LIB = stack_lib/stack_lib.a

SRC =	parsing.c push_swap_big.c push_swap_little.c push_swap.c main.c

BONUS_SRC = 

DEPENDS	:=	$(addprefix obj/,$(SRC:.c=.d)) $(addprefix obj/,${BONUS_SRC:.c=.d})

OBJ = $(addprefix obj/,$(SRC:.c=.o))

BONUS_OBJ = $(addprefix obj/,$(BONUS_SRC:.c=.o))

all : create_obj_folder
	@$(MAKE) lib_stacks
	@$(MAKE) $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(STACK_LIB)
	$(CC) $(OBJ) $(LIBFT) $(STACK_LIB) $(FLAGS) -o $(NAME)

bonus :

create_obj_folder :
	@mkdir -p obj

obj/%.o : src/%.c Makefile
	$(CC) $(FLAGS) -c $< -MD -o $@

lib_stacks : 
	@$(MAKE) -C stack_lib

run : all
	./$(NAME)

clean :
	$(RM) $(OBJ) $(BONUS_OBJ) $(DEPENDS)
	$(RM) -r push_swap.dSYM
	$(RM) $(BONUS_SRC:.c=.d)
	$(MAKE) clean -C stack_lib
	$(MAKE) clean -C libft
	$(RM) -r obj
	
fclean : clean
	$(RM) $(NAME)
	$(MAKE) fclean -C stack_lib
	$(MAKE) fclean -C libft

re : fclean
	$(MAKE) all

.PHONY : all debug lib_stacks run re clean fclean bonus create_obj_folder

-include $(DEPENDS)