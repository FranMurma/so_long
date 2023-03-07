/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:48:30 by frmurcia          #+#    #+#             */
/*   Updated: 2023/03/07 14:51:58 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"

int	ft_player_position(int count1, int count2, t_game *game)
{
	game->player_x = count1;
	game->player_y = count2;
	if (game->play_dir == 'W')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[6].img_ptr, (count2 * SIZE), (count1 * SIZE));
	else if (game->play_dir == 'S')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[7].img_ptr, (count2 * SIZE), (count1 * SIZE));
	else if (game->play_dir == 'A')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[8].img_ptr, (count2 * SIZE), (count1 * SIZE));
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[9].img_ptr, (count2 * SIZE), (count1 * SIZE));
	return (0);
}

int	ft_o_position(int count1, int count2, t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[0].img_ptr, (count2 * SIZE), (count1 * SIZE));
	return (0);
}

int	ft_wall_position(int count1, int count2, t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[1].img_ptr, (count2 * SIZE), (count1 * SIZE));
	return (0);
}

int	ft_exit_position(int count1, int count2, t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[2].img_ptr, (count2 * SIZE), (count1 * SIZE));
	return (0);
}

int	ft_collect_position(int count1, int count2, t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[3].img_ptr, (count2 * SIZE), (count1 * SIZE));
	return (0);
}
