/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:28:15 by aaleixo-          #+#    #+#             */
/*   Updated: 2024/12/28 18:28:15 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/so_long.h"

void	ft_initializer(t_data *data, t_map *map)
{
	char	*path;
    int img_size;
	t_img	*img;

	data->map = map;
	img = malloc(sizeof(t_img));
	if (!img)
        ft_error(data, "Error: Malloc Failed.\n", 0);
	data->img = img;
    data->step_counter = 0;
	data->collectables = 0;
	path = "textures/player.xpm";
	data->img->player = mlx_xpm_file_to_image(data->mlx, path, &img_size, &img_size);
	if (!data->img->player)
	{
        free(img);
        ft_error(data, "Error: Player texture file not found.\n", 1);
    }
}
