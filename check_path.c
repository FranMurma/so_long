/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:06:25 by frmurcia          #+#    #+#             */
/*   Updated: 2023/02/20 19:50:23 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

char	**copy_map(t_game *game)
{
	int		c;
	char	**copymap;

	c = 0;
	copymap = (char **)malloc(sizeof(char *) * (game->width + 1));
	if (!copymap)
		return (NULL);
	while (game->map[c])
	{
		copymap[c] = ft_strdup(game->map[c]);
		c++;
	}
	copymap[c] = NULL;
	return (copymap);
}

// Función para revisar todas las casillas en busca de un camino
// que vaya del Player al Exit, para ello iremos restando los coleccionables
// y buscando la  salida, eso significará que si ambas condiciones son exitosas
// el path es válido


int	ft_check_path(t_game *game, int x, int y)
{
	int	col;
	int	ex;

	ex = 1;
	col = game->collect;
//	printf("Esta es la X e Y del player: %d, %d \n", x, y);
//	printf("Esta es la cantidad de coleccionables: %d\n", col);
//	printf("Esta es la X y la Y en el copymap: %c\n", game->cp_map[x][y]);
//	printf("Esto es la width: %d\n", game->width);
//	printf("Esto es la height: %d\n", game->height);
	while (x + 1 < game->height && x - 1 > 0 && y + 1 < game->width && y - 1 > 0)
	{
		printf("Numero de colecccionables: %d\n", col);
		printf("Numero de puertas: %d\n", ex);
		printf("Entro 1\n");
		if ((game->cp_map[x + 1][y] == '1') && (game->cp_map[x - 1][y] == '1')
				&& (game->cp_map[x][y + 1] == '1') && (game->cp_map[x][y - 1] == '1'
					&& (col != 0 || ex != 0)))
			return (-1);
		else if (game->cp_map[x][y] == 'C' && col > 0)
		{
			printf("Me como un coleccionable\n");
			game->cp_map[x][y] = '1';
			col--;
		}
		else if (game->cp_map[x][y] == 'E')
		{
			printf("Me como la salida\n");
			game->cp_map[x][y] = '1';
			ex--;
		} 
		else if (game->cp_map[x][y] == '0')
		{
			printf("Me como un 0\n");
			game->cp_map[x][y] = '1';
		}
		if (game->cp_map[x + 1][y] != '1' && x + 1 <= game->height )
			ft_check_path(game, y, x + 1);
		if (game->cp_map[x - 1][y] != '1' && x - 1 >= 0)
			ft_check_path(game, y, x - 1);
		if (game->cp_map[x][y + 1] != '1' && y + 1 <= game->width)
			ft_check_path(game, y + 1, x);
		if (game->cp_map[x][y - 1] != '1' && y - 1 >= 0)
			ft_check_path(game, y - 1, x);
		if (ex == 0 && col == 0)
		{
			printf("FUNCIONA!!!!\nFUNCIONAAA!!!\nFUUUUNCCCCIOOOONAAA!!!");
			return (0);
		}
		else
			return (-1);
	}

	return (0);
}
