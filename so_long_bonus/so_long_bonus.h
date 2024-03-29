/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:31:54 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/08 16:56:42 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"

typedef struct s_element
{
	int	p;
	int	c;
	int	e;
	int	i;
	int	j;
}	t_element;

typedef struct s_map
{
	int	y;
	int	x;
}	t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr[5];
	void		*gate_img[9];
	void		*gold_img[10];
	void		*enemy_img[12];
	char		**map;
	int			player;
	int			gate;
	int			gold;
	int			enemy;
	int			moves;
	char		*moves_string;
}	t_data;

//parsing2
void	parsnew_line(char *line);
void	pars_element(char *line);
void	check_ones(char **map);
char	*get_map_line(char *file);
char	**get_map(char *file);
t_map	map_demontion(t_data *data);
void	floodfill(char **map, int i, int j);
t_map	get_player_pos(char **map);
int		checkfor_c(char **map);
void	check_argv(char *map);

int		close_win(t_data *data);
void	exit_free(char **map);
void	exit_free_line(char *line);
void	exit_free_erro(char **map);
void	freemap(char **map);
void	free_all(t_data *data);
void	ft_destroy_gold(t_data *data, int i);
void	ft_destroy_gate(t_data *data, int i);
void	ft_destroy_img(t_data *data, int i);

//moves
void	handlemoves(t_data *data, char **map, char key);
void	moveshandler(t_data *data, char move);
int		moveplayer_d(char **map, int iscoins);
int		moveplayer_a(char **map, int iscoins);
int		moveplayer_w(char **map, int iscoins);
int		moveplayer_s(char **map, int iscoins);
int		ft_anime(t_data *data);
int		ft_anime_gold(t_data *data);
int		ft_anime_gate(t_data *data);
int		ft_anime_enemy(t_data *data);

int		stillcoins(char **map);
int		ft_close(int key, t_data *data);
void	exitwindow(t_data *data);

void	set_gold_imgs(t_data *data);
void	*set_window(void *mlx, t_map map, t_data *data);
void	set_map(t_data *data);
void	set_texture(t_data *data, char c, int x, int y);
void	set_enemy_imgs(t_data *data);

void	check_gold_imgs(t_data *data, int ex);
void	check_gate_imgs(t_data *data, int ex);
void	check_ptr_imgs(t_data *data, int ex);

int		enemy_moves(t_data *data);
int		move_D(t_data *data, int i, int j);
int		move_A(t_data *data, int i, int j);
int		move_W(t_data *data, int i, int j);
int		move_S(t_data *data, int i, int j);

#endif