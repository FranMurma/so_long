/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:39:52 by frmurcia          #+#    #+#             */
/*   Updated: 2023/03/08 18:14:07 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"

int	ft_errors(t_game *game)
{
	if (ft_check_surroended(game) == -1)
	{
		ft_free_map(game);
		write (2, "Error\nThe map is not surroended by 1s\n", 38);
		exit(-1);
	}
	if (ft_check_items(game) == -1 || ft_check_symbols(game) == -1)
	{
		ft_free_map(game);
		write (2, "Error\nThe map has not the correct items or symbols\n", 40);
		exit(-1);
	}
	ft_check_square(game);
	ft_player_post(game);
	ft_check_path(game, game->player_x, game->player_y);
	if (game->collect_cp != 0)
	{
		write (2, "Error\nNot path between the player and the exit\n", 47);
		exit (-1);
	}
	ft_check_exit(game, game->player_x, game->player_y);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.count = 0;
	ft_check_errors_arg(argc, argv);
	ft_read_map(argv, &game);
	ft_map_measures(&game);
	game.cp_map = copy_map(&game);
	game.cp_map2 = copy_map(&game);
	ft_errors(&game);
	if (game.exit != 0)
	{
		write (2, "Error\nThere's not a path between the p and the exit\n", 57);
		exit (-1);
	}
	game.mlx_ptr = mlx_init();
	ft_upload_img(&game);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.width * SIZE,
			game.height * SIZE, "Pacoman");
	ft_print_map(&game);
	mlx_hook(game.win_ptr, 2, 0, ft_move, &game);
	mlx_hook(game.win_ptr, 17, 0, ft_free_all, &game);
	mlx_loop(game.mlx_ptr);
	ft_free_all(&game);
	return (0);
}
