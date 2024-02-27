/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksegs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 02:31:41 by soel-bou          #+#    #+#             */
/*   Updated: 2024/02/27 02:37:25 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void    checkimgs(t_data *data)
{
    int i;

    i = 0;
    if(!data)
        exit(EXIT_FAILURE);
    while(i <= 5)
    {
        if(!data->img_ptr[i])
            exit(EXIT_FAILURE);
        i++;
    }
    i = 0;
    while(i < 9)
    {
        if(!data->gate_img[i])
            exit(EXIT_FAILURE);
        i++;
    }
    while(i <= 9)
    {
        if(!data->gold_img[i])
            exit(EXIT_FAILURE);
        i++;
    }
}
