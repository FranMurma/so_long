/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:27:15 by frmurcia          #+#    #+#             */
/*   Updated: 2023/02/25 12:13:27 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"

int	ft_player_position(int count1, int count2, t_game *game)
{
	game->player_x = count1;
	game->player_y = count2;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[3].img_ptr, (count2 * SIZE), (count1 * SIZE));
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
		game->imgs[4].img_ptr, (count2 * SIZE), (count1 * SIZE));
	return (0);
}
