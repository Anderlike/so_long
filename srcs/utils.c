/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:35:40 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/03/09 13:35:40 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	ft_error(t_data *data, char *error, int bool)
{
	if (data->map.map && bool == 1)
	{
		ft_free(data->map.map);
	}
	ft_printf("Error:\n%s\n", error);
	exit(1);
}

int	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (-1);
	data->win = mlx_new_window(data->mlx, data->win_width,
			data->win_height, "so_long - made by aaleixo-");
	if (data->win == NULL)
	{
		free(data->win);
		return (-1);
	}
	return (0);
}

void	init_images(t_data *data)
{
	data->img.ground = mlx_xpm_file_to_image(data->mlx, GROUND,
			&data->img.width, &data->img.height);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, EXIT,
			&data->img.width, &data->img.height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, PLAYER,
			&data->img.width, &data->img.height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, WALL,
			&data->img.width, &data->img.height);
	data->img.coin = mlx_xpm_file_to_image(data->mlx, COIN,
			&data->img.width, &data->img.height);
}

void	loop_images(t_data data)
{
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, ClientMessage, LeaveWindowMask,
		&handle_btnrelease, &data);
	mlx_loop(data.mlx);
}

void	destroy_images(t_data data)
{
	mlx_destroy_image(data.mlx, data.img.wall);
	mlx_destroy_image(data.mlx, data.img.ground);
	mlx_destroy_image(data.mlx, data.img.player);
	mlx_destroy_image(data.mlx, data.img.exit);
	mlx_destroy_image(data.mlx, data.img.coin);
	mlx_destroy_display(data.mlx);
}
