#include "so_long_bonus.h"
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"

void	ft_copy_map(t_game *game)
{
	int		c;

	c = 0;
	game->cp_map = (char **)malloc(sizeof(char *) * (game->width + 1));
	game->cp_map2 = (char **)malloc(sizeof(char *) * (game->width + 1));
	if (!game->cp_map)
		return ;
	while (game->map[c])
	{

        game->cp_map2[c] = ft_strdup(game->map[c]);
		game->cp_map[c] = ft_strdup(game->map[c]);
		c++;
	}
	game->cp_map[c] = NULL;
	game->cp_map2[c] = NULL;
	game->exit = 1;
}

// Función para revisar todas las casillas en busca de un camino
// que vaya del Player al Exit, para ello iremos restando los coleccionables
// y buscando la  salida. Si recogemos todos los coleecionables
// eso significará que el path es válido

int	ft_check_path(t_game *game, int x, int y)
{
	if ((game->cp_map[x][y] == 'V') || (game->cp_map[x][y] == '1'
			|| game->cp_map[x][y] == 'E'))
		return (-1);
	if (game->cp_map[x][y] == 'C')
	{
		game->collect_cp--;
		game->cp_map[x][y] = 'V';
	}
	game->cp_map[x][y] = 'V';
	ft_check_path(game, x, y + 1);
	ft_check_path(game, x, y - 1);
	ft_check_path(game, x + 1, y);
	ft_check_path(game, x - 1, y);
	return (-1);
}

//HAY QUE  COPIAR FT_CHECK_PATH PERO BUSCANDO SOLO LA SALIDA
int	ft_check_exit(t_game *game, int x, int y)
{
	if ((game->cp_map2[x][y] == 'V') || (game->cp_map2[x][y] == '1'))
		return (-1);
	if (game->cp_map2[x][y] == 'E')
	{
		game->cp_map2[x][y] = 'V';
		game->exit--;
	}
	game->cp_map2[x][y] = 'V';
	ft_check_exit(game, x -1, y);
	ft_check_exit(game, x, y +1);
	ft_check_exit(game, x +1, y);
	ft_check_exit(game, x, y -1);
	return (-1);
}
