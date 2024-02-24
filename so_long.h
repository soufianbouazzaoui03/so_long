/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:31:54 by soel-bou          #+#    #+#             */
/*   Updated: 2024/02/24 02:06:36 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"  

typedef struct s_map
{
    int y;
    int x;
}   t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	void		*textures[5];
	char		**map;
}	t_data;


//PARSING:
// int checker(const char *file);
// int checklenght(const char *file);
// int checkline(int fd);
// int checkwall(const char *file);
// int checkborder(const char *file);
// int checkPE(const char *file, char c);
// int checkforletters(const char *file);
// int checkcoin(const char *file);


//moves
void	handlemoves(char **map, char key);
void	moveplayerD(char **map, int iscoins);
void	moveplayerA(char **map, int iscoins);
void	moveplayerW(char **map, int iscoins);
void	moveplayerS(char **map, int iscoins);


//map
char	**get_map(char *file);
t_map	map_demontion(char *file);
int		stillcoins(char **map);



void    *set_window(void *mlx, t_map map);
void	set_map(t_data *data);
void	set_texture(t_data *data, char c, int x, int y);


#endif