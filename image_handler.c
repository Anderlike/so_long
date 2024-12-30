/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:02:03 by aaleixo-          #+#    #+#             */
/*   Updated: 2024/12/28 16:02:03 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/so_long.h"

void player_image(t_data *data)
{
    int img_x;
    int img_y;
    data->player_x = data->map->x;
    data->player_y = data->map->y;
    data->img->player = mlx_xpm_file_to_image(data->mlx, "textures/player.xpm", &img_x, &img_y);
	if (!data->img->player)
		ft_error(data, "Error: xpm to image error (Player).\n", 1);
    mlx_put_image_to_window(data->mlx, data->window, data->img->player, (data->player_x * IMG_SIZE), (data->player_y * IMG_SIZE));
}

//Error: xpm to image error (obj).
void obj_image(t_data *data, char *path)
{
    int img_x;
    int img_y;
    data->map->obj = mlx_xpm_file_to_image(data->mlx, path, &img_x, &img_y);
    if(!data->map->obj)
        ft_error(data, "Error: xpm to image error (obj).\n", 1);
    mlx_put_image_to_window(data->mlx, data->window, data->map->obj, data->map->x * IMG_SIZE, data->map->y * IMG_SIZE);
}