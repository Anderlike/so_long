/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:34:55 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/03/09 13:34:55 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return ;
}

int	retrieve_line_number(char *path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error:\nMap couldn't be opened.\n");
		exit(0);
	}
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (line_count);
}

void	put_input_in_map(size_t row, size_t column, int i, t_data *data)
{
	char	*line;

	line = get_next_line(data->map.fd);
	while (line != NULL)
	{
		data->map.map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->map.map[row])
			return (ft_free(data->map.map));
		while (line[i] != '\0')
			data->map.map[row][column++] = line[i++];
		data->map.map[row++][column] = '\0';
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(data->map.fd);
	}
	data->map.map[row] = NULL;
	close(data->map.fd);
}

void	create_map(char *path, t_data *data)
{
	int		i;
	size_t	row;
	size_t	column;

	i = 0;
	row = 0;
	column = 0;
	data->steps_count = 0;
	data->map.line_count = retrieve_line_number(path);
	data->map.path = path;
	data->map.map = ft_calloc(data->map.line_count + 1, sizeof(char *));
	if (!(data->map.map))
	{
		ft_printf("Error\nMap calloc failed.\n");
		exit(0);
	}
	ext_checker(path, data);
	put_input_in_map(row, column, i, data);
	data->win_height = data->map.line_count * IMG_SIZE;
	data->win_width = (ft_strlen(data->map.map[0]) - 1) * IMG_SIZE;
}

void	init_player(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (data->map.map[i])
	{
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'P')
			{
				data->p_x = i;
				data->p_y = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
