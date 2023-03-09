/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:36:15 by frmurcia          #+#    #+#             */
/*   Updated: 2023/03/09 16:43:54 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"

static void	ft_write_error(void)
{
	write(1, "Error\nBad filemap", 17);
	exit(-1);
}

int	ft_player_post(t_game *game)
{
	int	count1;
	int	count2;

	count1 = 0;
	count2 = 0;
	while (count1 <= game->height && count2 <= game->width)
	{
		if (game->map[count1][count2] == 'P')
		{
			game->player_x = count1;
			game->player_y = count2;
		}
		count1++;
		if (count1 == game->height)
		{
			count2++;
			count1 = 0;
		}
	}
	return (0);
}

int	ft_read_map(char **argv, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_write_error();
	line = get_next_line(fd);
	if (!line)
		ft_write_error();
	game->map_raw = ft_strdup(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map_raw = ft_strjoin(game->map_raw, line);
	}
	free(line);
	return (fd);
}

void	ft_map_measures(t_game	*game)
{
	int	count1;
	int	count2;

	count1 = 0;
	count2 = 0;
	game->map = ft_split(game->map_raw, '\n');
	while (game->map[0][count1])
		count1++;
	game->width = count1;
	while (game->map[count2])
		count2++;
	game->height = count2;
}
