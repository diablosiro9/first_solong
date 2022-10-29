# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 14:59:45 by dojannin          #+#    #+#              #
#    Updated: 2022/10/29 20:01:18 by dojannin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

OBJ = $(SRCS:.c=.o)

CFLAGS += -Wall -Wextra -Werror #-g -fsanitize=address

SRCS = 	Parsing/checking_map.c \
		Parsing/ft_split.c \
		Parsing/flood_fill.c \
		tools_map.c \
		main2.c \
		lib_tools2.c \
		lib_tools.c \
		
%.o: %.c
	$(CC) -Wall -Wextra -Werror -D BUFFER_SIZE=4096 -Imlx -c $< -o $@
	
$(NAME):		$(OBJ)
					$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all:			$(NAME)

clean:			
				rm -f $(OBJ)

fclean:			clean
					rm -f $(NAME)

norme:
					norminette -R CheckForbiddenSourceHeader $(SRCS) 

re:				fclean all

.PHONY :		all clean fclean re
