/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:25:58 by frmurcia          #+#    #+#             */
/*   Updated: 2023/03/08 15:50:05 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"

void	ft_close(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
}

void	ft_free_map(t_game *game)
{
	int	c;

	c = 0;
	while (game->map[c])
	{
		free(game->map[c]);
		c++;
	}
	free(game->map);
	c = 0;
	while (game->cp_map[c])
	{
		free(game->cp_map[c]);
		c++;
	}
	free(game->cp_map);
	c = 0;
	while (game->cp_map2[c])
	{
		free (game->cp_map2[c]);
		c++;
	}
	free(game->cp_map2);
	free(game->enemies);
}

int	ft_free_all(t_game *game)
{
	if (game->map_raw)
		free(game->map_raw);
	if (game->map)
		ft_free_map(game);
	if (game->imgs)
		free(game->imgs);
	if (game->enemies)
		free(game->enemies);
	ft_close(game);
	exit (1);
}
