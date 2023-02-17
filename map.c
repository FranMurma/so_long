/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:42:20 by frmurcia          #+#    #+#             */
/*   Updated: 2023/02/17 17:38:41 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

int	ft_read_map(char **argv, t_game *game)
{
	int		fd;
	char	*line;
	int		c;

	c = 0;
	printf("1\n");
	fd = open(argv[1], O_RDONLY);
	printf("2\n");
	if (fd == -1)
	{
		write(1, "Error\nBad filemap", 17);
		exit(-1);
	}
	printf("3\n");
	printf("fd is%d\n", fd);
	line = get_next_line(fd);
	printf("4\n");
	if (!line)
	{
		write(1, "Error\nNo map", 13);
		exit(-1);
	}
	printf("dp !line\n");
	game->map_raw = NULL;
	game->map_raw = ft_strdup(line);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map_raw = ft_strjoin(game->map_raw, line);
	}
	while (line)
	{
		printf("Entro estas veces en el While: %d\n", c);
		game->map_raw = ft_strjoin(game->map_raw, line);
		free (line);
		line = get_next_line(fd);
	}
	free(line);
	return (fd);
}
/*
int	ft_continue_reading(t_game *game, int fd, int i)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		exit(-1);
	game->map_raw = NULL;
	game->height = ft_strlen(line) - 1;
	while (line)
	{
		game->width = ft_strlen(line) - 1;
		game->map_raw = ft_strjoin(game->map_raw, line);
		free (line);
		line = get_next_line(fd);
		i++;
	}
	free (line);
	game->width = i - 1;
	return (fd);
}

int	ft_read_map(char **argv, t_game *game)
{
	int		fd;
	size_t	i;

	i = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nNo se puede abrir\n");
		exit(1);
	}
	fd = ft_continue_reading(game, fd, i);
	close(fd);
	return (0);
}*/

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
