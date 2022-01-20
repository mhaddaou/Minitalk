# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 14:36:03 by mhaddaou          #+#    #+#              #
#    Updated: 2022/01/19 14:38:16 by mhaddaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = "library.a"

FILES = ft_putchar.c ft_putnbr.c ft_putstr.c ft_to_dic.c

OBJECTS = ft_putchar.o ft_putnbr.o ft_putstr.o ft_to_dic.o

all:
	@gcc -c -Wall -Wextra -Werror $(FILES)
	@cd libft && make all
	@ar rcs $(NAME) $(OBJECTS) libft/*.o

clean:
	@rm -f $(OBJECTS)
	@cd libft && make clean

fclean: clean
	@rm -f $(NAME)
	@cd libft && make fclean

re: fclean all
