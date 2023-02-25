#include "so_long_bonus.h"
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"

void	ft_win(t_game *game)
{
	int	c;

	c = 0;
	game->count = game->count +1;
	ft_printf("Movements number: %d\n", game->count);
	mlx_string_put(game->mlx_ptr, game->win_ptr, (game->width * 32 / 2 -64),
		(game->height *32 / 2), 0xff00, "YOOOUUU WIIINNN!!!\n");
	mlx_do_sync(game->mlx_ptr);
	while (c < 1000000000)
		c++;
	ft_free_all(game);
	exit(-1);
}
