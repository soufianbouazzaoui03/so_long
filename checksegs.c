/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksegs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 02:31:41 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/02 21:36:36 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int	checkimgs(t_data *data)
{
	int	i;

	i = 0;
	if(!data)
		return (1);
	while(i <= 5)
	{
		if(!data->img_ptr[i])
			return (1);
		i++;
	}
	i = 0;
	while(i < 9)
	{
		if(!data->gate_img[i])
			return (1);
		i++;
	}
	while(i <= 9)
	{
		if(!data->gold_img[i])
			return (1);
		i++;
	}
	return (0);
}


void    check_gold_imgs(t_data *data, int ex)
{
	int i;

	i = 0;
	while(i < 10)
	{
		if(!data->gold_img[i])
		{
			ft_destroy_gold(data, i - 1);
			exit(ex);
		}
		i++;
	}
}
void    check_gate_imgs(t_data *data, int ex)
{
	int i;

	i = 0;
	while(i < 9)
	{
		if(!data->gate_img[i])
		{
			ft_destroy_gold(data, 9);
			ft_destroy_img(data, 4);
			ft_destroy_gate(data, i - 1);
			exit(ex);
		}
		i++;
	}
	
}
void    check_ptr_imgs(t_data *data, int ex)
{
	int i;

	i = 0;
	while(i < 5)
	{
		if(!data->img_ptr[i])
		{
			printf("%d", i);
			ft_destroy_gold(data, 9);
			ft_destroy_img(data, i - 1);
			exit(ex);
		}
		i++;
	}
}