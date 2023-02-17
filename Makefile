# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 16:17:33 by frmurcia          #+#    #+#              #
#    Updated: 2023/02/16 17:18:00 by frmurcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# COLORS
GREEN			:= \033[32m
NC				:= \033[m

NAME = so_long

CC = gcc
SRC = so_long.c aux.c check.c exit.c get_next_line.c map.c movement.c split.c upload_img.c

FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
HEADER = so_long.h

RM = rm -f

%.o : %.c
	make -C mlx 
		$(CC) -c $(FLAGS) -Imlx -I mlx/mlx.h $< -o $@

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)


all : $(NAME)


clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)
	make clean -C mlx	
	@echo "$(GREEN)$(NAME) cleaned!$(NC)"

re : fclean all
norm : 
	@norminette
.PHONY = all clean fclean re norm bonus
