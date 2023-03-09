/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_en_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:33:29 by frmurcia          #+#    #+#             */
/*   Updated: 2023/03/09 18:32:38 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"

int	ft_move_right(t_game *game, int count_e)
{
	if (game->map[game->enemies[count_e].e_x][game->enemies[count_e].e_y -1]
		== '0')
	{
		game->map[game->enemies[count_e].e_x][game->enemies[count_e].e_y] = '0';
		game->enemies[count_e].e_y = game->enemies[count_e].e_y -1;
		game->map[game->enemies[count_e].e_x][game->enemies[count_e].e_y] = 'N';
	}
	else if (game->map[game->enemies[count_e].e_x]
		[game->enemies[count_e].e_y -1] == 'P')
	{
		game->end = 1;
		ft_lost(game);
	}
	else
		game->enemies[count_e].direction = 2;
	return (count_e);
}

int	ft_move_left(t_game *game, int count_e)
{
	if (game->map[game->enemies[count_e].e_x][game->enemies[count_e].e_y +1]
		== '0')
	{
		game->map[game->enemies[count_e].e_x][game->enemies[count_e].e_y] = '0';
		game->enemies[count_e].e_y = game->enemies[count_e].e_y +1;
		game->map[game->enemies[count_e].e_x][game->enemies[count_e].e_y] = 'N';
	}
	else if (game->map[game->enemies[count_e].e_x]
		[game->enemies[count_e].e_y +1] == 'P')
	{
		game->end = 1;
		ft_lost(game);
	}
	else
		game->enemies[count_e].direction = 1;
	return (count_e);
}

int	ft_real_move(t_game *game, int count_e)
{
	while (count_e < game->enem_nb)
	{
		if (game->enemies[count_e].direction == 1)
			ft_move_right(game, count_e);
		else if (game->enemies[count_e].direction == 2)
			ft_move_left(game, count_e);
		count_e++;
	}
	return (count_e);
}

int	ft_mov_en(t_game *game)
{
	int	count_e;

	count_e = 0;
	if (game->tmp_mov % 10 == 0 && game->end != 1)
		if (ft_real_move(game, count_e) == -1)
			ft_lost(game);
	if (game->end == 1)
	{
		mlx_string_put(game->mlx_ptr, game->win_ptr, (game->width * 32 / 2 -64),
			(game->height * 32 / 2), 0xff00,
			"YOOOUUU ARE A LOOOSER!!!\nINVADERS WIN!!");
	}
	ft_print_map(game);
	game->tmp_mov++;
	return (1);
}
