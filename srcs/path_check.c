/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:25:28 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/03/12 17:15:08 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	flood_fill(t_data *data, int x, int y, int **visited)
{
	if (x < 0 || y < 0 || x >= data->map.line_count
		|| y >= (int)(ft_strlen(data->map.map[0]) - 1)
		|| data->map.map[x][y] == '1' || visited[x][y])
		return ;
	visited[x][y] = 1;
	flood_fill(data, x + 1, y, visited);
	flood_fill(data, x - 1, y, visited);
	flood_fill(data, x, y + 1, visited);
	flood_fill(data, x, y - 1, visited);
}

void	free_visited(int **visited, int line_count)
{
	while (line_count--)
		free(visited[line_count]);
	free(visited);
}

int	is_unreachable(t_data *data, int **visited)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.line_count)
	{
		j = 0;
		while (j < (int)(ft_strlen(data->map.map[0]) - 1))
		{
			if ((data->map.map[i][j] == 'C' || data->map.map[i][j] == 'E')
			&& !visited[i][j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_path(t_data *data)
{
	int	**visited;
	int	i;

	i = 0;
	visited = (int **)ft_calloc(data->map.line_count, sizeof(int *));
	while (i < data->map.line_count)
		visited[i++] = (int *)ft_calloc(ft_strlen(data->map.map[0]) - 1, 4);
	flood_fill(data, data->p_x, data->p_y, visited);
	if (is_unreachable(data, visited))
	{
		free_visited(visited, data->map.line_count);
		ft_error(*data, "Not all objectives are reachable.");
		return (1);
	}
	free_visited(visited, data->map.line_count);
	return (0);
}
