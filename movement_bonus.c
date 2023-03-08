/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:55:49 by frmurcia          #+#    #+#             */
/*   Updated: 2023/03/08 16:16:23 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"

int	ft_move_w(t_game *game)
{
	char		*count2;

	count2 = ft_itoa(game->count);
	game->play_dir = 'W';
	if ((game->map[game->player_x -1][game->player_y] != '1')
		&& (game->map[game->player_x -1][game->player_y] != 'E')
		&& (game->map[game->player_x -1][game->player_y] != 'N'))
	{
		if (game->map[game->player_x -1][game->player_y] == 'C')
			game->collect = game->collect -1;
		game->map[game->player_x][game->player_y] = '0';
		game->player_x = game->player_x -1;
		game->map[game->player_x][game->player_y] = 'P';
		game->count = game->count +1;
		ft_print_map(game);
	}
	else if (game->collect == 0 && (game->map[game->player_x -1]
			[game->player_y] == 'E'))
		ft_win(game);
	else if (game->map[game->player_x -1][game->player_y] == 'N')
	{
		game->map[game->player_x][game->player_y] = '0';
		game->end = 1;
		ft_lost(game);
	}
//	free(count2);
	return (0);
}

int	ft_move_s(t_game *game)
{
	char		*count2;

	count2 = ft_itoa(game->count);
	game->play_dir = 'S';
	if ((game->map[game->player_x +1][game->player_y] != '1')
		&& (game->map[game->player_x +1][game->player_y] != 'E')
		&& (game->map[game->player_x +1][game->player_y] != 'N'))
	{
		if (game->map[game->player_x +1][game->player_y] == 'C')
			game->collect = game->collect -1;
		game->map[game->player_x][game->player_y] = '0';
		game->player_x = game->player_x +1;
		game->map[game->player_x][game->player_y] = 'P';
		game->count = game->count +1;
		ft_print_map(game);
	}
	else if (game->collect == 0 && (game->map[game->player_x +1]
			[game->player_y] == 'E'))
		ft_win(game);
	else if (game->map[game->player_x +1][game->player_y] == 'N')
	{
		game->map[game->player_x][game->player_y] = '0';
		game->end = 1;
		ft_lost(game);
	}
//	free(count2);
	return (0);
}

int	ft_move_a(t_game *game)
{
	char		*count2;

	count2 = ft_itoa(game->count);
	game->play_dir = 'A';
	if ((game->map[game->player_x][game->player_y -1] != '1')
		&& (game->map[game->player_x][game->player_y -1] != 'E')
		&& (game->map[game->player_x][game->player_y -1] != 'N'))
	{
		if (game->map[game->player_x][game->player_y -1] == 'C')
			game->collect = game->collect -1;
		game->map[game->player_x][game->player_y] = '0';
		game->player_y = game->player_y -1;
		game->map[game->player_x][game->player_y] = 'P';
		game->count = game->count +1;
		ft_print_map(game);
	}
	else if (game->collect == 0 && (game->map[game->player_x]
			[game->player_y -1] == 'E'))
	{
//		free(count2);
		ft_win(game);
	}
	else if (game->map[game->player_x][game->player_y -1] == 'N')
	{
		game->map[game->player_x][game->player_y] = '0';
		game->end = 1;
//		free(count2);
		ft_lost(game);
	}
	return (0);
}

int	ft_move_d(t_game *game)
{
	char		*count2;

	count2 = ft_itoa(game->count);
	game->play_dir = 'D';
	if ((game->map[game->player_x][game->player_y +1] != '1')
		&& (game->map[game->player_x][game->player_y +1] != 'E')
		&& (game->map[game->player_x][game->player_y +1] != 'N'))
	{
		if (game->map[game->player_x][game->player_y +1] == 'C')
			game->collect = game->collect -1;
		game->map[game->player_x][game->player_y] = '0';
		game->player_y = game->player_y +1;
		game->map[game->player_x][game->player_y] = 'P';
		game->count = game->count +1;
		ft_print_map(game);
	}
	else if (game->collect == 0 && (game->map[game->player_x]
			[game->player_y +1] == 'E'))
		ft_win(game);
	else if (game->map[game->player_x][game->player_y +1] == 'N')
	{
		game->map[game->player_x][game->player_y] = '0';
		game->end = 1;
		ft_lost(game);
	}
//	free(count2);
	return (0);
}

int	ft_move(int keycode, t_game *game)
{
	if (keycode == 13 && game->end == 1)
		ft_free_all(game);
	if (keycode == 13 && game->end != 1)
		ft_move_w(game);
	if (keycode == 0 && game->end == 1)
		ft_free_all(game);
	if (keycode == 0 && game->end != 1)
		ft_move_a(game);
	if (keycode == 1 && game->end == 1)
		ft_free_all(game);
	if (keycode == 1 && game->end != 1)
		ft_move_s(game);
	if (keycode == 2 && game->end == 1)
		ft_free_all(game);
	if (keycode == 2 && game->end != 1)
		ft_move_d(game);
	if (keycode == 53)
		ft_free_all(game);
	return (0);
}
