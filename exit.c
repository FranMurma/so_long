/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:10:07 by frmurcia          #+#    #+#             */
/*   Updated: 2023/03/08 18:35:26 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
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
}

int	ft_free_all(t_game *game)
{
	if (game->map_raw)
		free(game->map_raw);
	if (game->map)
		ft_free_map(game);
	ft_close(game);
	return (1);
}
