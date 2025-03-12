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

void	main_helper(t_data data)
{
	init_window(&data);
	init_images(&data);
	render(&data);
	loop_images(data);
	destroy_images(data);
	free(data.mlx);
	if (data.map.map)
		ft_free(data.map.map);
}

void	init_map(t_data *data)
{
	data->mlx = NULL;
	data->x = 0;
	data->y = 0;
	data->map.count_p = 0;
	data->map.count_e = 0;
	data->map.count_c = 0;
	data->map.collected = 0;
	data->map.can_exit = 0;
	data->img.height = IMG_SIZE;
	data->img.width = IMG_SIZE;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		data.map.fd = open(argv[1], O_RDONLY);
		if (data.map.fd < 0)
		{
			ft_printf("Error\nMap couldn't be opened.\n");
			exit(0);
		}
		init_map(&data);
		create_map(argv[1], &data);
		check_map(&data);
		data.mlx = mlx_init();
		if (!data.mlx)
			ft_error(data, "Minilibx error.");
		init_player(&data);
		main_helper(data);
		return (0);
	}
	ft_printf("Error\nIncorrect amount of args.\n");
}
