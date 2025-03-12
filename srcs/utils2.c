/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:10:05 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/03/12 18:28:50 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	ext_check(t_data *data)
{
	size_t	i;
	size_t	j;
	char	*ext;

	ext = ".ber";
	i = ft_strlen(data->map.path - 1);
	j = 0;
	while (i < ft_strlen(data->map.path))
	{
		ft_printf("%i", i);
		if (data->map.path[i] != ext[j])
			ft_error(*data, "No .ber file detected");
		i++;
		j++;
	}
}

void	ext_checker(char *path, t_data *data)
{
	if (!ft_strnstr(&path[ft_strlen(path) - 4], ".ber\0", 4))
	{
		ft_printf("Error\nNo \".ber\" file detected.\n");
		free(data->map.map);
		exit(0);
	}
	return ;
}
