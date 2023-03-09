/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_img_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:42:05 by frmurcia          #+#    #+#             */
/*   Updated: 2023/03/09 18:51:23 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"

void	ft_up_moremore(t_game *game, int height, int width)
{
	game->imgs[10].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/dead1.xpm", &width, &height);
	game->imgs[10].data = (int *)mlx_get_data_addr(game->imgs[10].img_ptr,
			&game->imgs[10].bpp, &game->imgs[10].size_l,
			&game->imgs[10].endian);
	game->imgs[11].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/dead2.xpm", &width, &height);
	game->imgs[11].data = (int *)mlx_get_data_addr(game->imgs[11].img_ptr,
			&game->imgs[11].bpp, &game->imgs[11].size_l,
			&game->imgs[11].endian);
	game->imgs[12].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/dead3.xpm", &width, &height);
	game->imgs[12].data = (int *)mlx_get_data_addr(game->imgs[12].img_ptr,
			&game->imgs[12].bpp, &game->imgs[12].size_l,
			&game->imgs[12].endian);
	game->imgs[13].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/dead4.xpm", &width, &height);
	game->imgs[13].data = (int *)mlx_get_data_addr(game->imgs[13].img_ptr,
			&game->imgs[13].bpp, &game->imgs[13].size_l,
			&game->imgs[13].endian);
}

void	ft_upload_more(t_game *game, int height, int width)
{
	game->imgs[5].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/invader2.xpm", &width, &height);
	game->imgs[5].data = (int *)mlx_get_data_addr(game->imgs[5].img_ptr,
			&game->imgs[5].bpp, &game->imgs[5].size_l, &game->imgs[5].endian);
	game->imgs[6].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/player_w.xpm", &width, &height);
	game->imgs[6].data = (int *)mlx_get_data_addr(game->imgs[6].img_ptr,
			&game->imgs[6].bpp, &game->imgs[6].size_l, &game->imgs[6].endian);
	game->imgs[7].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/player_s.xpm", &width, &height);
	game->imgs[7].data = (int *)mlx_get_data_addr(game->imgs[7].img_ptr,
			&game->imgs[7].bpp, &game->imgs[7].size_l, &game->imgs[7].endian);
	game->imgs[8].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/player_a.xpm", &width, &height);
	game->imgs[8].data = (int *)mlx_get_data_addr(game->imgs[8].img_ptr,
			&game->imgs[8].bpp, &game->imgs[8].size_l, &game->imgs[8].endian);
	game->imgs[9].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/player_d.xpm", &width, &height);
	game->imgs[9].data = (int *)mlx_get_data_addr(game->imgs[9].img_ptr,
			&game->imgs[9].bpp, &game->imgs[9].size_l, &game->imgs[9].endian);
	ft_up_moremore(game, height, width);
}

void	ft_upload_img(t_game *game)
{
	int		height;
	int		width;

	game->imgs = malloc(sizeof(t_img) * 14);
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
			"imgs/collect.xpm", &width, &height);
	game->imgs[3].data = (int *)mlx_get_data_addr(game->imgs[3].img_ptr,
			&game->imgs[3].bpp, &game->imgs[3].size_l, &game->imgs[3].endian);
	game->imgs[4].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"imgs/invader1.xpm", &width, &height);
	game->imgs[4].data = (int *)mlx_get_data_addr(game->imgs[4].img_ptr,
			&game->imgs[4].bpp, &game->imgs[4].size_l, &game->imgs[4].endian);
	ft_upload_more(game, height, width);
}

int	ft_print_more(int count1, int count2, t_game *game)
{
	if (game->map[count1][count2] == '0')
		ft_o_position(count1, count2, game);
	if (game->map[count1][count2] == '1')
		ft_wall_position(count1, count2, game);
	else if (game->map[count1][count2] == 'E')
		ft_exit_position(count1, count2, game);
	else if (game->map[count1][count2] == 'P')
		ft_player_position(count1, count2, game);
	else if (game->map[count1][count2] == 'N')
		ft_enemy_position(count1, count2, game);
	else if (game->map[count1][count2] == 'C')
		ft_collect_position(count1, count2, game);
	return (0);
}

int	ft_print_map(t_game *game)
{
	int		count1;
	int		count2;
	char	*count_mov;

	count_mov = ft_itoa(game->count);
	count1 = 0;
	count2 = 0;
	while (count1 <= game->height && count2 <= game->width)
	{
		ft_print_more(count1, count2, game);
		count1++;
		mlx_string_put(game->mlx_ptr, game->win_ptr, 15,
			15, 0xff00, count_mov);
		if (game->end == 1)
			mlx_string_put(game->mlx_ptr, game->win_ptr,
				(game->width * 32 / 2 -64), (game->height * 32 / 2),
				0xff00, "YOOOUUU ARE A LOOOSER!!!\nINVADERS WIN!!");
		if (count1 == game->height)
		{
			count2++;
			count1 = 0;
		}
	}
	free(count_mov);
	return (0);
}
