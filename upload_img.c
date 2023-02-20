/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:01:35 by frmurcia          #+#    #+#             */
/*   Updated: 2023/02/20 16:13:13 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

int	ft_player_position(int count1, int count2, t_game *game)
{
	game->player_x = count1;
	game->player_y = count2;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[3].img_ptr, (count2 * SIZE), (count1 * SIZE));
	return (0);
}



void	ft_upload_img(t_game *game)
{
	int		height;
	int		width;

	game->imgs = malloc(sizeof(t_img) * 7);
	game->imgs[0].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/0.xpm", &width, &height);
	game->imgs[0].data = (int *)mlx_get_data_addr(game->imgs[0].img_ptr,
			&game->imgs[0].bpp, &game->imgs[0].size_l, &game->imgs[0].endian);
	game->imgs[1].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/1.xpm", &width, &height);
	game->imgs[1].data = (int *)mlx_get_data_addr(game->imgs[1].img_ptr,
			&game->imgs[1].bpp, &game->imgs[1].size_l, &game->imgs[1].endian);
	game->imgs[2].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/exit.xpm", &width, &height);
	game->imgs[2].data = (int *)mlx_get_data_addr(game->imgs[2].img_ptr,
			&game->imgs[2].bpp, &game->imgs[2].size_l, &game->imgs[2].endian);
	game->imgs[3].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/player.xpm", &width, &height);
	game->imgs[3].data = (int *)mlx_get_data_addr(game->imgs[3].img_ptr,
			&game->imgs[3].bpp, &game->imgs[3].size_l, &game->imgs[3].endian);
	game->imgs[4].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/collect.xpm", &width, &height);
	game->imgs[4].data = (int *)mlx_get_data_addr(game->imgs[4].img_ptr,
			&game->imgs[4].bpp, &game->imgs[4].size_l, &game->imgs[4].endian);
}

int	ft_print_map(t_game *game)
{
	int	count1;
	int	count2;

	count1 = 0;
	count2 = 0;
	while (count1 <= game->height && count2 <= game->width)
	{
		if (game->map[count1][count2] == '0')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->imgs[0].img_ptr, (count2 * SIZE), (count1 * SIZE));
		else if (game->map[count1][count2] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->imgs[1].img_ptr, (count2 * SIZE), (count1 * SIZE));
		else if (game->map[count1][count2] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->imgs[2].img_ptr, (count2 * SIZE), (count1 * SIZE));
		else if (game->map[count1][count2] == 'P')
			ft_player_position(count1, count2, game);
		else if (game->map[count1][count2] == 'C')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->imgs[4].img_ptr, (count2 * SIZE), (count1 * SIZE));
		count1++;
		if (count1 == game->height)
		{
			count2++;
			count1 = 0;
		}
	}
	return (0);
}
