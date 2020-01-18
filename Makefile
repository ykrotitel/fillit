# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 18:23:19 by vabraham          #+#    #+#              #
#    Updated: 2019/10/19 21:30:46 by vabraham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = src/check_n.c src/dop.c src/main.c src/fillit.c src/mod.c src/help.c
LIB = includes/libft/libft.a
NAME = fillit
OBJ = $(patsubst %.c,%.o,$(FILES))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C includes/libft re
	@gcc -Wall -Wextra -Werror -L includes/libft -lft $(FILES) -I includes/libft -I src/fillit.h -o $(NAME)
%.o: %.c
	@gcc -Wall -Werror -Wextra -I src/fillit.h $< -c -o $@

clean:
	@rm -rf $(OBJ)
	@make -C includes/libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C includes/libft fclean

re: fclean all

.PHONY: all clean fclean re
