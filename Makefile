# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 19:34:18 by frmurcia          #+#    #+#              #
#    Updated: 2023/03/08 16:12:03 by frmurcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
GREEN			:= \033[32m
BLUE			:= \033[34m 
YELLOW			:= \033[1m\033[33m
NC				:= \033[m

NAME = so_long

BONUS = so_long_bonus

CC = gcc

SRC = so_long.c aux.c check.c check_path.c exit.c get_next_line.c map.c movement.c moremov.c position.c split.c upload_img.c

SRC_BONUS = so_long_bonus.c aux_bonus.c check_bonus.c check_path_bonus.c death_bonus.c enemies_bonus.c exit_bonus.c get_next_line_bonus.c map_bonus.c mov_en_bonus.c movement_bonus.c moremov_bonus.c position_bonus.c split_bonus.c upload_img_bonus.c

FLAGS = -Wall -Werror -Wextra 
#-fsanitize=address

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

HEADER = so_long.h

HEADER_BONUS = so_long_bonus.h

FT_PRINTFDIR = ft_printf/

FT_PRINTF = $(FT_PRINTFDIR)libftprintf.a

RM = rm -f

%.o : %.c
	$(CC) -c $(FLAGS) -Imlx/ -Ift_printf/ $< -o $@

all :
	$(MAKE) ft_printf
	$(MAKE) -C mlx/
	$(MAKE) $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -Lft_printf -lftprintf $(OBJ) -o $(NAME)

bonus : $(OBJ_BONUS) $(HEADER_BONUS)
	$(MAKE) ft_printf
	$(MAKE) -C mlx/
	$(CC) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -Lft_printf -lftprintf $(OBJ_BONUS) -o $(BONUS) 

##bonus : $(BONUS) $(OBJ_BONUS) $(HEADER_BONUS)
##	$(CC) $(FLAGS) $(BOONUS) $(OBJ_BONUS)
##	touch $@ 

ft_printf :
	make -C $(FT_PRINTFDIR)

clean :
	@make clean -s -C $(FT_PRINTFDIR)
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean : clean
	$(RM) $(NAME) $(BONUS)
	make clean -C mlx
	make clean -C $(FT_PRINTFDIR)
	@echo "$(GREEN)$(NAME)$(NC) and $(YELLOW)$(BONUS)$(NC) cleaned!$(NC)"

leaks : leaks -atExit -- ./so_long_bonus maps/map_e1.ber

re : fclean all
norm :
	@norminette
.PHONY = all clean fclean re norm bonus leaks
