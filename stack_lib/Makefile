# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 01:32:11 by bajeanno          #+#    #+#              #
#    Updated: 2022/12/14 09:54:24 by bajeanno         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = stack_lib.a

LIBFT_PATH = ../libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC			=	stack_print.c	\
				stack_utils.c	\
				stack_index.c	\
				instructions.c	\

OBJ				:=		$(addprefix obj/,$(SRC:.c=.o))
DEPENDS			:=		$(addprefix obj/,$(SRC:.c=.d))

all	: create_obj_folder $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

obj/%.o : src/%.c Makefile
	cc -Wall -Wextra -Werror -c $< -MD -I $(LIBFT_PATH)/headers -I headers -o $@

create_obj_folder :
	mkdir -p obj

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) -f $(OBJ)
	$(RM) -f $(DEPENDS)
	$(RM) -r obj

fclean: clean
	make clean -C $(LIBFT_PATH)
	$(RM) -f $(NAME)

re: fclean
	make fclean -C $(LIBFT_PATH)
	$(MAKE) all

.PHONY : all bonus clean fclean re lib

-include $(DEPENDS)