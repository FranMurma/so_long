/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:02:59 by frmurcia          #+#    #+#             */
/*   Updated: 2023/02/16 19:08:56 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

char	ft_go(int keycode)
{
	if (keycode == 13)
		return ('w');
	if (keycode == 0)
		return ('a');
	if (keycode == 1)
		return ('s');
	if (keycode == 2)
		return ('d');
	if (keycode == 53)
		return (-1);
	return (0);
}

int	ft_move_w(t_game *game)
{
	long int	count;

	count = 0;
	if (game->map[game->player_x -1][game->player_y] != '1')
	{
		if (game->map[game->player_x -1][game->player_y] == 'C')
		{
			printf("El numero de coleccionables es: %d\n", game->collect);
			game->collect = game->collect -1;
			printf("Despues de comertelo, el numero de coleccionables es: %d\n", game->collect);
		}
		else if (game->collect == 0 && (game->map[game->player_x -1]
				[game->player_y] == 'E'))
		{
			printf("Pues entramos en que el siguiente es E\n");
			mlx_string_put(game->mlx_ptr, game->win_ptr, 15,
				15, 66000000, "CONGRATULATIONS\n");
			ft_wait(game);
			exit(1);
		}
		game->map[game->player_x][game->player_y] = '0';
		game->player_x = game->player_x -1;
		game->map[game->player_x][game->player_y] = 'P';
		game->count = game->count +1;
		printf("Movements number: %d\n", game->count);
		ft_print_map (game);
	}
	return (0);
}

int	ft_move_s(t_game *game)
{
	long int	count;
	
	count = 0;
	if (game->map[game->player_x +1][game->player_y] != '1')
	{
		if (game->map[game->player_x +1][game->player_y] == 'C')
		{
			printf("El numero de coleccionables es: %d\n", game->collect);
			game->collect = game->collect -1;
			printf("Despues de comertelo, el numero de coleccionables es: %d\n", game->collect);
		}	
		else if (game->collect == 0 && (game->map[game->player_x +1]
				[game->player_y] == 'E'))
		{
			printf("Pues entramos en que el siguiente es E\n");
			mlx_string_put(game->mlx_ptr, game->win_ptr, 15,
				15, 66000000, "CONGRATULATIONS\n");
			ft_wait(game);
			exit(1);
		}
		game->map[game->player_x][game->player_y] = '0';
		game->player_x = game->player_x +1;
		game->map[game->player_x][game->player_y] = 'P';
		game->count = game->count +1;
		printf("Movements number: %d\n", game->count);
		ft_print_map (game);
	}
	return (0);
}

int	ft_move_a(t_game *game)
{
	long int	count;

	count  = 0;
	if (game->map[game->player_x][game->player_y -1] != '1')
	{
		if (game->map[game->player_x][game->player_y -1] == 'C')
		{
			printf("El numero de coleccionables es: %d\n", game->collect);
			game->collect = game->collect -1;
			printf("Despues de comertelo, el numero de coleccionables es: %d\n", game->collect);
		}
		else if (game->collect == 0 && (game->map[game->player_x]
				[game->player_y -1] == 'E'))
		{
			printf("SOY A. Pues entramos en que el siguiente es E\n");
			mlx_string_put(game->mlx_ptr, game->win_ptr, 15,
				15, 66000000, "CONGRATULATIONS\n");
			ft_wait(game);
			exit(1);
		}
		game->map[game->player_x][game->player_y] = '0';
		game->player_y = game->player_y -1;
		game->map[game->player_x][game->player_y] = 'P';
		game->count = game->count +1;
		printf("Movements number: %d\n", game->count);
		ft_print_map (game);
	}
	return (0);
}

int	ft_move_d(t_game *game)
{
	long int	count;

	count = 0;
	if (game->map[game->player_x][game->player_y +1] != '1')
	{
		if (game->map[game->player_x][game->player_y +1] == 'C')
		{
			printf("El numero de coleccionables es: %d\n", game->collect);
			game->collect = game->collect -1;
			printf("Despues de comertelo, el numero de coleccionables es: %d\n", game->collect);
		}
		else if (game->collect == 0 && (game->map[game->player_x]
				[game->player_y +1] == 'E'))
		{
			printf("Pues entramos en que el siguiente es E\n");
			mlx_string_put(game->mlx_ptr, game->win_ptr, 15,
				15, 66000000, "CONGRATULATIONS\n");
			ft_wait(game);
			exit(1);
		}
		game->map[game->player_x][game->player_y] = '0';
		game->player_y = game->player_y +1;
		game->map[game->player_x][game->player_y] = 'P';
		game->count = game->count +1;
		printf("Movements number: %d\n", game->count);
		ft_print_map (game);
	}
	return (0);
}

int	ft_move(int keycode, t_game *game)
{
	game->next_mov = ft_go(keycode);
	if (game->next_mov == -1)
		ft_free_all(game);
	if (game->next_mov == 'w')
		ft_move_w(game);
	if (game->next_mov == 's')
		ft_move_s(game);
	if (game->next_mov == 'a')
		ft_move_a(game);
	if (game->next_mov == 'd')
		ft_move_d(game);
	return (0);
}

void	ft_wait(t_game *game)
{
	long int	c;

	c = 0;
	while (c < 100000)
	{
		mlx_string_put(game->mlx_ptr, game->win_ptr, 15,
				15, 66000000, "CONGRATULATIONS\n");
		c++;
	}
}
