# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 07:25:14 by bajeanno          #+#    #+#              #
#    Updated: 2022/12/04 13:18:38 by bajeanno         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

FLAGS = -Werror -Wall -Wextra -o push_swap
DEBUG_FLAGS = -fsanitize=address -g3

all : lib
	$(CC) $(FLAGS) -o push_swap *.c stack_lib/*.c libft/libft.a -I stack_lib -I libft -I .

debug : lib
	$(CC) $(FLAGS) $(DEBUG_FLAGS) -o push_swap *.c stack_lib/*.c libft/libft.a -I stack_lib -I libft -I .

lib : libft/libft.a

libft/libft.a :
	$(MAKE) -C libft

run : all
	./a.out

clean :
	$(RM) *.o
	$(RM) -r push_swap.dSYM
	$(MAKE) clean -C libft
	
fclean :
	$(RM) push_swap
	$(MAKE) fclean -C libft

re : fclean all

.PHONY : all lib run re clean fclean