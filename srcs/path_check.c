/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:25:28 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/03/10 15:51:14 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	ft_free_array(char **ar1, char **ar2, int i)
{
	while (i > 0)
	{
		free(ar1[i]);
		free(ar2[i]);
		i--;
	}
	free(ar1);
	free(ar2);
	return (0);
}

void	scan_player(t_data *data)
{
	data->p_y = 0;
	data->p_x = 0;
	while (data->p_y < data->y)
	{
		while (data->p_x < data->x)
		{
			if (data->map.map[data->p_y][data->p_x] == 'P')
				break ;
			data->p_x++;
		}
		if (data->map.map[data->p_y][data->p_x] == 'P')
			break ;
		data->p_x = 0;
		data->p_y++;
	}
}

void	move_on_paths(int y, int x, t_data *data)
{
	char	type;

	ft_printf("P_Y: %d\nP_X: %d\nY: %d\nX: %d" , y, x, data->x, data->y);
	if (y < 0 || x < 0 || x >= data->x || y >= data->y)
		return;

	type = data->map.copy[y][x];
	if (type == 'C')
	{
		data->map.count_c -= 1;
		data->map.copy[y][x] = '1';
	}
	else if (type == 'E')
	{
		data->map.count_e -= 1;
		data->map.copy[y][x] = '1';
	}
	else if (type == '0' || type == 'P')
		data->map.copy[y][x] = '1';
	else
		return ;
	move_on_paths(y + 1, x, data);
	move_on_paths(y - 1, x, data);
	move_on_paths(y, x + 1, data);
	move_on_paths(y, x - 1, data);
}

void	check_path(t_data *data)
{
	if (!data || !data->map.map || !data->map.copy)
	{
		ft_printf("Error:\nInvalid map data.\n");
		exit(1);
	}

	data->map.count_c = data->map.c;
	data->map.count_e = data->map.e;
	scan_player(data);
	move_on_paths(data->p_y, data->p_x, data);

	if (data->map.count_c != 0 || data->map.count_e >= data->map.e)
	{
		ft_printf("Error:\nMap can't be finished with all coins collected.\n");
		ft_free_array(data->map.map, data->map.copy, data->y);
		exit(0);
	}
}
