/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:42:44 by frmurcia          #+#    #+#             */
/*   Updated: 2023/03/01 17:06:05 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

//Definicion de cada celda de movimiento
# define SIZE 32
# define BUFFER_SIZE 1

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_game
{
	char	*map_raw;
	char	**map;
	char	**cp_map;
	char	**cp_map2;
	int		height;
	int		width;
	int		player_x;
	int		player_y;
	t_img	*imgs;
	void	*mlx_ptr;
	void	*win_ptr;
	int		next_mov;
	int		count;
	int		collect;
	int		collect_cp;
	int		exit;
}	t_game;

//Auxiliar functions 1 (En aux.c)
size_t	ft_strlen(const char *s);
int		ft_file_term(char *file_name, char *file_end);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
//Otras auxiliares
//split.c
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);

//get_next_line.c
char	*get_next_line(int fd);
char	*ft_itoa(int n);

//Check errores en el so_long.c
int		ft_errors(t_game *game);

//Error functions 1 (En check.c)
int		ft_check_errors_arg(int argc, char **argv);
int		ft_check_surroended(t_game *game);
int		ft_check_items(t_game *game);
int		ft_check_symbols(t_game *game);
int		ft_check_square(t_game *game);
// Check path (En check_path.c)
char	**copy_map(t_game *game);
int		ft_check_path(t_game *game, int x, int y);
int		ft_check_exit(t_game *game, int x, int y);

// Leer mapa y poner height y width (En map.c)
int		ft_player_post(t_game *game);
int		ft_read_map(char **argv, t_game *game);
void	ft_map_measures(t_game	*game);

// Cargar y printar imagenes (en upload_img.c)
void	ft_upload_img(t_game *game);
int		ft_print_map(t_game *game);
int		ft_print_more(int count1, int count2, t_game *game);
// Printar imagenes (en position.c)
int		ft_player_position(int count1, int count2, t_game *game);
int		ft_o_position(int count1, int count2, t_game *game);
int		ft_wall_position(int count1, int count2, t_game *game);
int		ft_exit_position(int count1, int count2, t_game *game);
int		ft_collect_position(int count1, int count2, t_game *game);

// Hacer los movimientos (En movement.c)
int		ft_move(int keycode, t_game *game);
int		ft_move_w(t_game *game);
int		ft_move_s(t_game *game);
int		ft_move_a(t_game *game);
int		ft_move_d(t_game *game);
char	ft_go(int keycode);
// En moremov.c
void	ft_win(t_game *game);
void	ft_lost(t_game *game);

// Liberar memoria y salir
void	ft_close(t_game *game);
int		ft_free_all(t_game *game);
void	ft_free_map(t_game *game);
void	ft_wait(t_game *game);

#endif
