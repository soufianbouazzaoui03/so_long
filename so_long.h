/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:31:54 by soel-bou          #+#    #+#             */
/*   Updated: 2024/02/12 21:16:53 by soel-bou         ###   ########.fr       */
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
	void		*textures[5];
	t_map		*map;
}	t_data;

t_map	*map_demontion(int fd);
void    *set_window(void *mlx, t_map *map);
void	set_map(t_data *data, int fd);
void	set_texture(t_data *data, char c, int *x, int *y);

#endif