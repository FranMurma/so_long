/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:39:52 by frmurcia          #+#    #+#             */
/*   Updated: 2023/02/17 17:27:34 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.count = 0;
	ft_check_errors_arg(argc, argv);
	ft_read_map(argv, &game);
//	ft_map_measures(&game);
//	if (ft_check_surroended(&game) == -1)
//	{
//		ft_free_map(&game);
//		write (2, "Error\nThe map is not surroended by 1s\n", 38);
//		exit(-1);
//	}
//	if (ft_check_items(&game) == -1 || ft_check_symbols(&game) == -1)
//	{
//		ft_free_map(&game);
//		write (2, "Error\nThe map has not the correct items or symbols\n", 40);
//		exit(-1);
//	}
//	ft_check_square(&game);
// INICIAR JUEGO
//	game.mlx_ptr = mlx_init();
// CARGA LAS IMAGENES
//	ft_upload_img(&game);
// PONER EN PANTALLA LA VENTANA DEL JUEGO
//	game.win_ptr = mlx_new_window(game.mlx_ptr, game.width * SIZE,
//			game.height * SIZE, "Pacoman");
// PRINTAR EL MAPA
//	ft_print_map(&game);
// LLAMAR A LOS MOVIMIENTOS
//	mlx_hook(game.win_ptr, 2, 0, ft_move, &game);
// HABILITAR SCAPE Y LIBERAR MEMORIA
//	mlx_hook(game.win_ptr, 17, 0, ft_free_all, &game);
// BUCLE PARA MANTENER EL JUEGO ABIERTO UNA VEZ SE INICIA
//	mlx_loop(game.mlx_ptr);
//	ft_free_all(&game);
	return (0);
}
