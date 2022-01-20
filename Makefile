# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 10:58:45 by mhaddaou          #+#    #+#              #
#    Updated: 2022/01/19 14:24:01 by mhaddaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@cd library && make all
	@gcc -Wall -Wextra -Werror src/ft_server.c library/library.a -o server
	@gcc -Wall -Wextra -Werror src/ft_client.c library/library.a -o client

clean:
	@cd library && make clean
	@rm -f server
	@rm -f client

fclean: clean
	@cd library && make fclean

re: fclean all

bonus: fclean
	@cd library && make all
	@gcc  -Wall -Wextra -Werror "src_b/ft_server_bonus.c" library/library.a -o server
	@gcc -Wall -Wextra -Werror "src_b/ft_client_bonus.c" library/library.a -o client
