/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:38:40 by frmurcia          #+#    #+#             */
/*   Updated: 2023/03/09 19:00:48 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf/ft_printf.h"

int	ft_check_errors_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Error\nIncorrect arguments number", 31);
		exit(-1);
	}
	if (open(argv[1], O_RDONLY) == -1)
	{
		write(2, "Error\nIncorrect file reading", 28);
		exit(-1);
	}
	if (open(argv[1], O_RDONLY) == 0)
	{
		write(2, "Error\nIncorrect empty file", 26);
		exit(-1);
	}
	if (ft_file_term(argv[1], ".ber") == -1)
	{
		write(2, "Error\nIncorrect file name", 25);
		exit(-1);
	}
	return (0);
}

int	ft_check_surroended(t_game *game)
{
	int	count;

	count = 0;
	while (count < game->width)
	{
		if (game->map[0][count] != '1')
			return (-1);
		if (game->map[game->height -1][count] != '1')
			return (-1);
		count++;
	}
	count = 0;
	while (count < game->height)
	{
		if (game->map[count][0] != '1')
			return (-1);
		if (game->map[count][game->width -1] != '1')
			return (-1);
		count++;
	}
	return (0);
}

int	ft_check_items(t_game *game)
{
	int	count1;
	int	count2;
	int	e;
	int	p;

	count1 = 0;
	count2 = 0;
	e = 0;
	p = 0;
	while (count1 <= game->height && count2 <= game->width)
	{
		if (game->map[count1][count2] == 'E')
			e++;
		if (game->map[count1][count2] == 'P')
			p++;
		count1++;
		if (count1 == game->height)
		{
			count2++;
			count1 = 0;
		}
	}
	if (e != 1 || p != 1)
		return (-1);
	return (0);
}

int	ft_check_symbols(t_game *game)
{
	int	c1;
	int	c2;
	int	c;

	c1 = 0;
	c2 = 0;
	c = 0;
	while (c1 < game->height && c2 < game->width)
	{
		if (game->map[c1][c2] == 'C')
			c++;
		else if (game->map[c1][c2] != 'P' && game->map[c1][c2] != 'E'
			&& game->map[c1][c2] != '1' && game->map[c1][c2] != '0')
			return (-1);
		c1++;
		if (c1 == game->height)
		{
			c2++;
			c1 = 0;
		}
	}
	game->collect = c;
	game->collect_cp = c;
	return (0);
}

int	ft_check_square(t_game *game)
{
	int	c1;
	int	a;
	int	b;

	c1 = 0;
	a = ft_strlen(game->map[c1]);
	b = a;
	while (c1 < game->height)
	{
		b = ft_strlen(game->map[c1]);
		if (b == a)
			c1++;
		else if (b != a)
		{
			ft_free_map(game);
			write (2, "Error\nThe map is not a square", 29);
			exit(-1);
		}
	}
	return (0);
}
