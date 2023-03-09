/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:25:58 by frmurcia          #+#    #+#             */
/*   Updated: 2023/03/09 18:18:09 by frmurcia         ###   ########.fr       */
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
	if (game->map)
	{
		while (game->map[c] && c < game->width)
		{
			free(game->map[c]);
			c++;
		}
		free(game->map);
	}
}

void	ft_free_cpmap(t_game *game)
{
	int	c;

	c = 0;
	if (game->cp_map)
	{
		while (game->cp_map[c] && c < game->width)
		{
			free(game->cp_map[c]);
			c++;
		}
		free(game->cp_map);
	}
}

void	ft_free_cpmap2(t_game *game)
{
	int	c;

	c = 0;
	if (game->cp_map2)
	{
		while (game->cp_map2[c] && c < game->width)
		{
			free (game->cp_map2[c]);
			c++;
		}
	}
	free(game->cp_map2);
}

int	ft_free_all(t_game *game)
{
	ft_close(game);
	if (game->map_raw)
		free(game->map_raw);
	if (game->map)
		ft_free_map(game);
	if (game->cp_map)
		ft_free_cpmap(game);
	if (game->cp_map2)
		ft_free_cpmap2(game);
	if (game->imgs)
		free(game->imgs);
	if (game->enemies)
		free(game->enemies);
	exit (1);
}
