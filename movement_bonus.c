#include "so_long_bonus.h"
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"

int	ft_move_w(t_game *game)
{
	long int	count;
	char		*count2;

	count = 1;
	count2 = ft_itoa(game->count); 
	if ((game->map[game->player_x -1][game->player_y] != '1')
		&& (game->map[game->player_x -1][game->player_y] != 'E'))
	{
		if (game->map[game->player_x -1][game->player_y] == 'C')
			game->collect = game->collect -1;
		game->map[game->player_x][game->player_y] = '0';
		game->player_x = game->player_x -1;
		game->map[game->player_x][game->player_y] = 'P';
		game->count = game->count +1;
		ft_print_map(game);
		mlx_string_put(game->mlx_ptr, game->win_ptr, 15,
			15, 66000000, count2);
//		ft_printf("Movements number: %d\n", game->count);
	}
	else if (game->collect == 0 && (game->map[game->player_x -1]
			[game->player_y] == 'E'))
		ft_win(game);
	return (0);
}

int	ft_move_s(t_game *game)
{
	long int	count;
	char		*count2;

	count = 1;
	count2 = ft_itoa(game->count);
	if ((game->map[game->player_x +1][game->player_y] != '1')
		&& (game->map[game->player_x +1][game->player_y] != 'E'))
	{
		if (game->map[game->player_x +1][game->player_y] == 'C')
			game->collect = game->collect -1;
		game->map[game->player_x][game->player_y] = '0';
		game->player_x = game->player_x +1;
		game->map[game->player_x][game->player_y] = 'P';
		game->count = game->count +1;
		ft_print_map(game);
		mlx_string_put(game->mlx_ptr, game->win_ptr, 15,
			15, 66000000, count2);
//		ft_printf("Movements number: %d\n", game->count);
	}
	else if (game->collect == 0 && (game->map[game->player_x +1]
			[game->player_y] == 'E'))
		ft_win(game);
	return (0);
}

int	ft_move_a(t_game *game)
{
	long int	count;
	char		*count2;

	count = 1;
	count2 = ft_itoa(game->count);
	if ((game->map[game->player_x][game->player_y -1] != '1')
		&& (game->map[game->player_x][game->player_y -1] != 'E'))
	{
		if (game->map[game->player_x][game->player_y -1] == 'C')
			game->collect = game->collect -1;
		game->map[game->player_x][game->player_y] = '0';
		game->player_y = game->player_y -1;
		game->map[game->player_x][game->player_y] = 'P';
		game->count = game->count +1;
		ft_print_map(game);
		mlx_string_put(game->mlx_ptr, game->win_ptr, 15,
			15, 66000000, count2);
//		ft_printf("Movements number: %d\n", game->count);
	}
	else if (game->collect == 0 && (game->map[game->player_x]
			[game->player_y -1] == 'E'))
		ft_win(game);
	return (0);
}

int	ft_move_d(t_game *game)
{
	long int	count;
	char		*count2;

	count = 0;
	count2 = ft_itoa(game->count);
	if ((game->map[game->player_x][game->player_y +1] != '1')
		&& (game->map[game->player_x][game->player_y +1] != 'E'))
	{
		if (game->map[game->player_x][game->player_y +1] == 'C')
			game->collect = game->collect -1;
				game->map[game->player_x][game->player_y] = '0';
		game->player_y = game->player_y +1;
		game->map[game->player_x][game->player_y] = 'P';
		game->count = game->count +1;
		ft_print_map(game);
		mlx_string_put(game->mlx_ptr, game->win_ptr, 15,
			15, 66000000, count2);
//		ft_printf("Movements number: %d\n", game->count);
	}
	else if (game->collect == 0 && (game->map[game->player_x]
			[game->player_y +1] == 'E'))
		ft_win(game);
	return (0);
}

int	ft_move(int keycode, t_game *game)
{
	if (keycode == 13)
		ft_move_w(game);
	if (keycode == 0)
		ft_move_a(game);
	if (keycode == 1)
		ft_move_s(game);
	if (keycode == 2)
		ft_move_d(game);
	if (keycode == 53)
		exit(1);
	return (0);
}
