/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:32:55 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/03/09 13:32:55 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	init_map(t_data *data)
{
	data->x = 0;
	data->y = 0;
	data->map.count_p = 0;
	data->map.count_e = 0;
	data->map.count_c = 0;
	data->map.collected = 0;
	data->map.can_exit = 0;
	data->win_height = data->map.line_count * IMG_SIZE;
	data->win_width = (ft_strlen(data->map.map[0]) - 1) * IMG_SIZE;
	data->img.height = IMG_SIZE;
	data->img.width = IMG_SIZE;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		data.mlx = mlx_init();
		if (!data.mlx)
		{
			ft_printf("Error:\nMinilibx not initiated correctly.\n");
			exit(1);
		}
		create_map(argv[1], &data);
		init_map(&data);
		check_map(&data);
		init_player(&data);
		init_window(&data);
		init_images(&data);
		render(&data);
		loop_images(data);
		destroy_images(data);
		free(data.mlx);
		if (data.map.map)
			ft_free(data.map.map);
	}
}
