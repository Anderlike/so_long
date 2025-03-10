/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:36:03 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/03/09 13:36:03 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	check_chars(t_data *data)
{
	while (data->map.map[data->x])
	{
		while (data->map.map[data->x][data->y])
		{
			if (data->map.map[data->x][data->y] == 'P')
			{
				data->p_x = data->x;
				data->p_y = data->y;
				data->map.count_p++;
			}
			else if (data->map.map[data->x][data->y] == 'E')
				data->map.count_e++;
			else if (data->map.map[data->x][data->y] == 'C')
				data->map.count_c++;
			data->y++;
		}
		data->y = 0;
		data->x++;
	}
	if (!data->map.count_c || data->map.count_p != 1
		|| data->map.count_e != 1)
		return (1);
	else
		return (0);
}

int	check_top_bot(int row, char **map)
{
	int	i;

	i = 0;
	while (map[row][i] && map[row][i] != '\n')
	{
		if (map[row][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_edges(int line_count, char **map)
{
	int	i;

	i = 1;
	if (check_top_bot(0, map) == 1
		|| check_top_bot(line_count, map) == 1)
		return (1);
	while (i < line_count)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 2] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_rectangle(t_data *data)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	data->map.line_len = ft_strlen(data->map.map[i]) - 1;
	while (data->map.map[i])
	{
		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
			j++;
		if (j != data->map.line_len)
			return (1);
		j = 0;
		i++;
	}
	return (0);
}

int	check_map(t_data *data)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (data->map.map[i])
	{
		while (j < ft_strlen(data->map.map[i]) - 1)
		{
			if (ft_strchr("01CEP", data->map.map[i][j]) == NULL)
				ft_error(data, "Map is invalid.", 1);
			j++;
		}
		j = 0;
		i++;
	}
	if (check_chars(data) == 1)
		ft_error(data, "Incorrect amount of objectives(C,P,E).", 1);
	if (check_rectangle(data) == 1)
		ft_error(data, "Map needs to be a horizontal rectangle.", 1);
	if (check_edges(data->map.line_count - 1, data->map.map) == 1)
		ft_error(data, "Map needs to be surrounded by walls.", 1);
	if (check_path(data))
		ft_error(data, "Map doesn't have a valid path.", 1);
	return (0);
}
