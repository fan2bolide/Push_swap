# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 07:25:14 by bajeanno          #+#    #+#              #
#    Updated: 2022/12/02 07:43:20 by bajeanno         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

FLAGS = -fsanitize=address -g

all : lib
	$(CC) $(FLAGS) *.c stack_lib/*.c libft/libft.a -I stack_lib -I libft -I .

lib : libft/libft.a

libft/libft.a :
	$(MAKE) -C libft

run : all
	./a.out

clean :
	$(RM) *.o
	$(MAKE) clean -C libft
	
fclean :
	$(RM) a.out
	$(MAKE) fclean -C libft

re : fclean all

.PHONY : all lib run re clean fclean