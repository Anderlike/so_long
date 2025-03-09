/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:25:28 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/03/09 19:01:03 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	ft_free_int(int **tab, int size)
{
	int	i;

	for (i = 0; i < size; i++)
		free(tab[i]);
	free(tab);
	tab = NULL;
	return ;
}

int	is_valid_position(t_data *data, int x, int y, int **visited)
{
	if (x < 0 || x >= data->map.line_count || y < 0 || y >= (int)ft_strlen(data->map.map[0]))
		return (0);
	if (data->map.map[x][y] == '1' || visited[x][y])
		return (0);
	return (1);
}

int	dfs(t_data *data, int x, int y, int **visited, int *collectable_count)
{
	int	stack[data->map.line_count * ft_strlen(data->map.map[0])][2];
	int	top = -1;

	stack[++top][0] = x;
	stack[top][1] = y;

	while (top >= 0)
	{
		int	curr_x = stack[top][0];
		int	curr_y = stack[top--][1];

		printf("Visiting: (%d, %d)\n", curr_x, curr_y);

		if (data->map.map[curr_x][curr_y] == 'E' && (*collectable_count) == data->map.count_c)
			return (1);
		if (data->map.map[curr_x][curr_y] == 'C')
			(*collectable_count)++;

		visited[curr_x][curr_y] = 1;

		if (is_valid_position(data, curr_x + 1, curr_y, visited))
		{
			stack[++top][0] = curr_x + 1;
			stack[top][1] = curr_y;
		}
		if (is_valid_position(data, curr_x - 1, curr_y, visited))
		{
			stack[++top][0] = curr_x - 1;
			stack[top][1] = curr_y;
		}
		if (is_valid_position(data, curr_x, curr_y + 1, visited))
		{
			stack[++top][0] = curr_x;
			stack[top][1] = curr_y + 1;
		}
		if (is_valid_position(data, curr_x, curr_y - 1, visited))
		{
			stack[++top][0] = curr_x;
			stack[top][1] = curr_y - 1;
		}
	}
	return (0);
}

int	check_path(t_data *data)
{
	int	**visited;
	int	i;
	int	collectable_count = 0;
	int	curr_x = data->p_i;
	int	curr_y = data->p_j;

	visited = malloc(data->map.line_count * sizeof(int *));
	if (!visited)
		return (0);
	for (i = 0; i < data->map.line_count; i++)
	{
		visited[i] = ft_calloc(ft_strlen(data->map.map[0]), sizeof(int));
		if (!visited[i])
		{
			ft_free_int(visited, i);
			return (0);
		}
	}

	if (!dfs(data, curr_x, curr_y, visited, &collectable_count))
	{
		ft_free_int(visited, data->map.line_count);
		return (0);
	}

	ft_free_int(visited, data->map.line_count);
	return (1);
}