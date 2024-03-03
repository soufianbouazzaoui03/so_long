/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:12:40 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/03 22:21:59 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int checklastline(char *file)
{
	int 	y;
	char	*line;
	int 	fd;
	int i;

	i = 0;
	fd = open(file, O_RDONLY);
	if(fd < 0 || (y = map_demontion(file).y) == 0)
		return (1);
	while(1)
	{
		line = get_next_line(fd);
		if(y == 0)
			break;
		else
			free(line);
		y--;
	}
	while(line && line[i])
	{
		if(line[i++] == '\n')
			return(free(line), close(fd), 1);
	}
	return (free(line), close(fd), 0);
}

int		checklen(char **map)
{
	int 	i;
	size_t 	le;

	if (!map || !*map)
		return (1);
	le = ft_strlen(map[1]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != le)
			return (1);
		i++;
	}
	return (0);
}

int	checkone(char **map)
{
	int i;

	i = 0;
	if (!map || !*map)
		return (1);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int checkelement(char **map)
{
	t_element elem;

	elem.e = 0;
	elem.c = 0;
	elem.i = -1;
	elem.p = 0;
	while(map[++elem.i])
	{
		elem.j = -1;
		while(map[elem.i][++elem.j])
		{
			if(map[elem.i][elem.j] == 'C')
				elem.c++;
			else if(map[elem.i][elem.j] == 'P')
				elem.p++;
			else if(map[elem.i][elem.j] == 'E')
				elem.e++;
			else if(map[elem.i][elem.j] != '1' && map[elem.i][elem.j] != '0' 
					 && map[elem.i][elem.j] != 'N')
				return (1);
		}
	}
	if(elem.c < 1 || elem.p != 1 || elem.e != 1)
			return (1);
	return (0);
}

int checkones(char **map, char *file)
{
	int y;
	int	i;

	i = 0;
	y = map_demontion(file).y;
	while (map[0][i] && map[y][i])
	{
		if (map[0][i] != '1' || map[y][i++] != '1')
			return (1);
	}
	return (0);
}