/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:31:56 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/07 22:26:26 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*get_map_line(char *file)
{
	char	*map_line;
	char	*new_line;
	char	*tmp;
	int		fd;

	map_line = ft_strdup("");
	if (!map_line)
		exit(1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	while (1)
	{
		new_line = get_next_line(fd);
		if (!new_line)
			break ;
		tmp = ft_strjoin(map_line, new_line);
		free(map_line);
		free(new_line);
		new_line = NULL;
		map_line = NULL;
		map_line = tmp;
	}
	return (close(fd), map_line);
}

char	**get_map_from_line(char *line)
{
	char	**map;
	int		i;
	size_t	len;

	i = 0;
	map = ft_split(line, '\n');
	free (line);
	if (!map)
		exit(1);
	check_ones(map);
	i = 0;
	len = ft_strlen(map[0]);
	if (len > 40)
		exit_free_erro(map);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1'
				|| ft_strlen(map[i++]) != len || i > 22)
			exit_free_erro(map);
	}
	return (map);
}

char	**get_map(char *file)
{
	char	*line;
	char	*line2;
	char	**map;
	char	**mapcpy;

	line = get_map_line(file);
	parsnew_line(line);
	pars_element(line);
	map = get_map_from_line(line);
	line2 = get_map_line(file);
	mapcpy = get_map_from_line(line2);
	if (checkfor_c(mapcpy))
	{
		freemap(mapcpy);
		ft_putstr_fd("Error\nUNPLAYABLE MAP!\n", 2);
		exit_free(map);
	}
	freemap(mapcpy);
	return (map);
}

t_map	map_demontion(t_data *data)
{
	t_map	demontion;

	demontion.x = 0;
	demontion.y = 0;
	while (data->map[demontion.y][demontion.x])
		demontion.x++;
	while (data->map[demontion.y])
		demontion.y++;
	return (demontion);
}

void	floodfill(char **map, int i, int j)
{
	if (map[i - 1][j] == 'C' || map[i - 1][j] == '0' || map[i - 1][j] == 'E')
	{
		map[i - 1][j] = 'V';
		floodfill(map, i - 1, j);
	}
	if (map[i + 1][j] == 'C' || map[i + 1][j] == '0' || map[i + 1][j] == 'E')
	{
		map[i + 1][j] = 'V';
		floodfill(map, i + 1, j);
	}
	if (map[i][j - 1] == 'C' || map[i][j - 1] == '0' || map[i][j - 1] == 'E')
	{
		map[i][j - 1] = 'V';
		floodfill(map, i, j - 1);
	}
	if (map[i][j + 1] == 'C' || map[i][j + 1] == '0' || map[i][j + 1] == 'E')
	{
		map[i][j + 1] = 'V';
		floodfill(map, i, j + 1);
	}
}
