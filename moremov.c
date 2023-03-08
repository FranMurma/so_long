/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moremov.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:47:09 by frmurcia          #+#    #+#             */
/*   Updated: 2023/03/08 18:40:41 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"

void	ft_win(t_game *game)
{
	int	c;

	c = 0;
	game->count = game->count +1;
	ft_printf("Movements number: %d\n", game->count);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 15,
		15, 66000000, "CONGRATULATIONS\n");
	mlx_do_sync(game->mlx_ptr);
	while (c < 1000000000)
		c++;
	ft_free_all(game);
	exit(-1);
}
