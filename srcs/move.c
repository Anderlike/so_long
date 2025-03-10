/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:34:06 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/03/09 13:34:06 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	move_msg(t_data *data)
{
	printf("Moves counter : %d\n", data->steps_count);
}

int	check_next_tile(t_data *data, char direction, char tile)
{
	if ((direction == 'd' && data->map.map[data->p_x][data->p_y + 1] == tile)
		|| (direction == 'a' && data->map.map[data->p_x][data->p_y - 1] == tile)
		|| (direction == 's' && data->map.map[data->p_x + 1][data->p_y] == tile)
		|| (direction == 'w' && data->map.map[data->p_x - 1][data->p_y] == tile)
		)
		return (0);
	else
		return (1);
}

void	collect_coins(t_data *data, char direction)
{
	if ((direction == 'd' && data->map.map[data->p_x][data->p_y + 1] == 'C')
		|| (direction == 'a' && data->map.map[data->p_x][data->p_y - 1] == 'C')
		|| (direction == 's' && data->map.map[data->p_x + 1][data->p_y] == 'C')
		|| (direction == 'w' && data->map.map[data->p_x - 1][data->p_y] == 'C'))
		data->map.collected++;
}

int	win_game(t_data *data)
{
	if (data->map.can_exit == 1)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		return (0);
	}
	else
		return (1);
}

void	move_player(t_data *data, char direction)
{
	if (check_next_tile(data, direction, '1') == 0
		|| (data->map.can_exit == 0
			&& check_next_tile(data, direction, 'E') == 0))
		return ;
	data->steps_count++;
	collect_coins(data, direction);
	if (data->map.collected == data->map.count_c)
		data->map.can_exit = 1;
	data->map.map[data->p_x][data->p_y] = '0';
	if (direction == 'd')
		data->p_y++;
	else if (direction == 'a')
		data->p_y--;
	else if (direction == 's')
		data->p_x++;
	else if (direction == 'w')
		data->p_x--;
	move_msg(data);
	if (data->map.can_exit == 1 && data->map.map[data->p_x][data->p_y] == 'E')
		win_game(data);
	data->map.map[data->p_x][data->p_y] = 'P';
}