# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 07:25:14 by bajeanno          #+#    #+#              #
#    Updated: 2023/01/16 19:36:28 by bajeanno         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Werror -Wall -Wextra -I stack_lib/headers -I libft/headers -I ./headers

DEBUG_FLAGS = -fsanitize=address -g3

LIBFT = libft/libft.a

STACK_LIB = stack_lib/stack_lib.a

SRC =	parsing.c push_swap_big.c push_swap_little.c push_swap.c main.c

BONUS_SRC = push_swap_viewer.c

DEPENDS	:=	$(addprefix obj/,$(SRC:.c=.d)) $(addprefix obj/,${BONUS_SRC:.c=.d})

OBJ = $(addprefix obj/,$(SRC:.c=.o))

BONUS_OBJ = $(addprefix obj/,$(BONUS_SRC:.c=.o))

all : create_obj_folder .mandatory 
	@$(MAKE) lib_stacks
	@$(MAKE) $(NAME)

.mandatory :
	@touch .mandatory
	@$(RM) .viewer

$(NAME) : $(OBJ) .mandatory $(LIBFT) $(STACK_LIB)
	$(CC) $(OBJ) $(LIBFT) $(STACK_LIB) $(FLAGS) -o $(NAME)

bonus : create_obj_folder lib lib_stacks .viewer

.viewer : $(BONUS_OBJ) $(OBJ)
	$(CC) obj/parsing.o $(BONUS_OBJ) $(LIBFT) $(STACK_LIB) $(FLAGS) -o viewer
	touch .viewer
	$(RM) .mandatory

create_obj_folder :
	@mkdir -p obj

obj/%.o : src/%.c Makefile
	$(CC) $(FLAGS) -c $< -MD -o $@

debug : lib lib_stacks
	$(CC) $(OBJ) $(STACK_LIB) $(LIBFT) $(FLAGS) $(DEBUG_FLAGS)

lib_stacks : 
	@$(MAKE) -C stack_lib

run : all
	./a.out

clean :
	$(RM) $(OBJ) $(BONUS_OBJ) $(DEPENDS)
	$(RM) -r push_swap.dSYM
	$(MAKE) clean -C stack_lib
	$(MAKE) clean -C libft
	$(RM) -r obj
	
fclean : clean
	$(RM) $(NAME)
	$(RM) viewer
	$(RM) $(BONUS_SRC:.c=.d)
	$(RM) .mandatory .viewer
	$(MAKE) fclean -C stack_lib
	$(MAKE) fclean -C libft

re : fclean
	$(MAKE) all

.PHONY : all lib run re clean fclean bonus

-include $(DEPENDS)