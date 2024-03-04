/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:06:08 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/04 20:33:59 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	parsnew_line(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\n')
	{
		ft_putstr_fd("EMPTY LINE!\n", 2);
		exit_free_line(line);
	}
	while (line[i] && line[i + 1])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
		{
			ft_putstr_fd("EMPTY LINE!\n", 2);
			exit_free_line(line);
		}
		i++;
	}
	if (line[i] == '\n')
	{
		ft_putstr_fd("EMPTY LINE!\n", 2);
		exit_free_line(line);
	}
}

void	check_element(int p, int e, int c, char *line)
{
	if (e != 1 || p != 1 || c < 1)
	{
		ft_putstr_fd("ELEMENTS ERROR!\n", 2);
		exit_free_line(line);
	}
}

void	pars_element(char *line)
{
	int			i;
	static int	p;
	static int	e;
	static int	c;

	i = -1;
	while (line[++i])
	{
		if ((line[i] != '0' && line[i] != '1' && line[i] != 'E' && line[i]
				!= 'C' && line[i] != 'P' && line[i] != 'N' && line[i] != '\n'))
		{
			ft_putstr_fd("EXTRA ELEMENTS\n", 2);
			exit_free_line(line);
		}
		if (line[i] == 'E')
			e++;
		else if (line[i] == 'C')
			c++;
		else if (line[i] == 'P')
			p++;
	}
	check_element(p, e, c, line);
}

void	check_ones(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][i])
	{
		if (map[0][i++] != '1')
			exit_free(map);
	}
	i = 0;
	while (map[i])
		i++;
	while (map[i - 1][j])
	{
		if (map[i - 1][j] != '1')
			exit_free(map);
		j++;
	}
}

void	check_argv(char *map)
{
	int	i;

	if (!map)
	{
		ft_putstr_fd("INVALID ARGS!\n", 2);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (map[i])
		i++;
	if (ft_strncmp(&map[i - 4], ".ber", 4))
	{
		ft_putstr_fd("INVALID FILE NAME!\n", 2);
		exit(EXIT_FAILURE);
	}
}
