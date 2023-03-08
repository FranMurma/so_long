#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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

typedef struct s_enem
{
	int		e_x;
	int		e_y;
	int		direction;
}	t_enem;

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
	int		play_dir;
	int		end;
	t_img	*imgs;
	t_enem	*enemies;
	int		tmp_mov;
	void	*mlx_ptr;
	void	*win_ptr;
	int		enem_nb;
	int		next_mov;
	int		count;
	int		collect;
	int		collect_cp;
	int		exit;
}	t_game;

//Auxiliar functions 1 (En aux_bonus.c)
size_t	ft_strlen(const char *s);
int		ft_file_term(char *file_name, char *file_end);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);

//Other auxiliar
//split_bonus.c
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
//Get_next_line_bonus.c
char	*get_next_line(int fd);

//Error functions 1 (En check_bonus.c)
int		ft_check_errors_arg(int argc, char **argv);
int		ft_check_surroended(t_game *game);
int		ft_check_items(t_game *game);
int		ft_check_symbols(t_game *game);
int		ft_check_square(t_game *game);
// Check enemy in map (En enemies_bonus.c  (enemies = 'N')
void	ft_count_enemies(t_game *game);
void	ft_enemies_pos(t_game *game);
int		ft_put_enemies(t_game *game);

//Print enemy
int		ft_enemy_position(int count1, int count2, t_game *game);
int		ft_put_enemies(t_game *game);

// Check path (En check_path_bonus.c)
char	**ft_copy_map(t_game *game);
int		ft_check_path(t_game *game, int x, int y);
int		ft_check_exit(t_game *game, int x, int y);

// Leer mapa y poner height y width (En map_bonus.c)
int		ft_player_post(t_game *game);
int		ft_read_map(char **argv, t_game *game);
void	ft_map_measures(t_game	*game);

// Cargar y printar imagenes (en upload_img_bonus.c)
void	ft_upload_img(t_game *game);
void	ft_upload_more(t_game *game, int height, int width);
void	ft_up_moremore(t_game *game, int height, int width);
int		ft_print_map(t_game *game);
int		ft_print_more(int count1, int count2, t_game *game);
// Printar imagenes (en position_bonus.c)
int		ft_player_position(int count1, int count2, t_game *game);
int		ft_o_position(int count1, int count2, t_game *game);
int		ft_wall_position(int count1, int count2, t_game *game);
int		ft_exit_position(int count1, int count2, t_game *game);
int		ft_collect_position(int count1, int count2, t_game *game);
// Printar muerte (en death_bonus.c)
int		ft_death(int count1, int count2, t_game *game);
int		ft_death_2(int count1, int count2, t_game *game);
int		ft_death_3(int count1, int count2, t_game *game);
int		ft_death_4(int count1, int count2, t_game *game);

// Hacer los movimientos (En movement_bonus.c)
int		ft_move(int keycode, t_game *game);
int		ft_move_w(t_game *game);
int		ft_move_s(t_game *game);
int		ft_move_a(t_game *game);
int		ft_move_d(t_game *game);
char	ft_go(int keycode);

// En moremov_bonus.c
void	ft_win(t_game *game);
void	ft_lost(t_game *game);

// Movimientos enemigos n (mov_en_bonus.c)
int		ft_mov_en(t_game *game);
int		ft_real_move(t_game *game, int count_e);
int		ft_move_right(t_game *game, int count_e);
int		ft_move_left(t_game *game, int count_e);

// Liberar memoria y salir (en exit_bonus.c)
void	ft_close(t_game *game);
int		ft_free_all(t_game *game);
void	ft_free_map(t_game *game);

#endif
