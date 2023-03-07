/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:01:35 by frmurcia          #+#    #+#             */
/*   Updated: 2023/02/28 15:23:05 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"

void	ft_upload_img(t_game *game)
{
	int		height;
	int		width;

	game->imgs = malloc(sizeof(t_img) * 5);
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
			ft_o_position(count1, count2, game);
		else if (game->map[count1][count2] == '1')
			ft_wall_position(count1, count2, game);
		else if (game->map[count1][count2] == 'E')
			ft_exit_position(count1, count2, game);
		else if (game->map[count1][count2] == 'P')
			ft_player_position(count1, count2, game);
		else if (game->map[count1][count2] == 'C')
			ft_collect_position(count1, count2, game);
		count1++;
		if (count1 == game->height)
		{
			count2++;
			count1 = 0;
		}
	}
	return (0);
}
