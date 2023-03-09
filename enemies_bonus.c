/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:48:00 by frmurcia          #+#    #+#             */
/*   Updated: 2023/03/09 18:16:56 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"

// Desde el main lanzamos ft_count_enemies, que es necesaria para 
// poder hacer el malloc en ft_put_enemies (tambien hace el check de enmies en 
// el mapa), y a su vez el malloc (ft_put_enemies) es condicion 
// de posibilidad de la funcion para poner las coordenadas 
// a cada enemigo (ft_enemies_pos)
void	ft_count_enemies(t_game *game)
{
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	while (c1 < game->height && c2 < game->width)
	{
		if (game->map[c1][c2] == 'N')
		{
			game->enem_nb++;
		}
		c1++;
		if (c1 == game->height)
		{
			c1 = 0;
			c2++;
		}
	}
	if (game->enem_nb < 1)
	{
		ft_printf("Error\nNo correct number of enemies in the map!");
		exit(-1);
	}
	ft_put_enemies(game);
}

void	ft_enemies_pos(t_game *game)
{
	int	c1;
	int	c2;
	int	e;

	c1 = 0;
	c2 = 0;
	e = 0;
	while (c1 < game->height && c2 < game->width)
	{
		if (game->map[c1][c2] == 'N')
		{
			game->enemies[e].e_x = c1;
			game->enemies[e].e_y = c2;
			e++;
		}
		c1++;
		if (c1 == game->height)
		{
			c1 = 0;
			c2++;
		}
	}
}

int	ft_enemy_position(int count1, int count2, t_game *game)
{
	if (game->enemies->e_y % 2 == 0)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[4].img_ptr, (count2 * SIZE), (count1 * SIZE));
	else if (game->enemies->e_y % 2 == 1)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[5].img_ptr, (count2 * SIZE), (count1 * SIZE));
	return (0);
}

int	ft_put_enemies(t_game *game)
{
	int	count;

	count = 0;
	game->enemies = malloc(sizeof(t_enem) * (game->enem_nb +1));
	if (!game->enemies)
		return (0);
	while (count < game->enem_nb)
	{
		game->enemies[count].direction = 1;
		count++;
	}
	ft_enemies_pos(game);
	return (0);
}
