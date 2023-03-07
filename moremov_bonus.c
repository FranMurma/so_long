/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moremov_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:22:42 by frmurcia          #+#    #+#             */
/*   Updated: 2023/03/07 18:14:19 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"

void	ft_win(t_game *game)
{
	int	c;

	c = 0;
//	game->end = 1;
	game->count = game->count +1;
	mlx_string_put(game->mlx_ptr, game->win_ptr, (game->width * 32 / 2 -64),
		(game->height *32 / 2), 0xff00, "YOOOUUU WIIINNN!!!\n");
	mlx_do_sync(game->mlx_ptr);
	while (c < 1000000000)
		c++;
	while (c > 0)
		c--;
	ft_free_all(game);
//	exit(-1);
}

void ft_lost(t_game *game) 
{
	game->end = 1;
    mlx_string_put(game->mlx_ptr, game->win_ptr, (game->width * 32 / 2 -64),
        (game->height *32 / 2), 0xff00, "YOOOUUU ARE A LOOOSER!!!\nINVADERS WIN!!");
	game->map[game->player_x][game->player_y] = '2';
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
        game->imgs[0].img_ptr, (game->player_y * SIZE), (game->player_x * SIZE));
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
        game->imgs[13].img_ptr, (game->player_y * SIZE), (game->player_x * SIZE));
//	ft_no_move(keycode);
//		exit(1);
//	while (c < 40000000)
//		c++;
//	while (c > 0)
//		c--;
//	usleep(100000);
//	ft_free_all(game);
//	exit (-1);*/
}
