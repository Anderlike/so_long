/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:43:51 by aaleixo-          #+#    #+#             */
/*   Updated: 2024/12/28 15:43:51 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/so_long.h"

int	ft_line_length(int fd)
{
    char buffer[1];
    int length;
    int bytes;

    length = 0;
    while ((bytes = read(fd, buffer, 1)) > 0)
    {
        if (buffer[0] == '\n')
            break;
        length++;
    }
    return (length);
}

int	ft_count_lines(int fd)
{
    char buffer[1];
    int lines;
    int bytes;

    lines = 0;
    while ((bytes = read(fd, buffer, 1)) > 0)
    {
        if (buffer[0] == '\n')
            lines++;
    }
    return (lines);
}

void free_map(t_data *data)
{
    int i;

    i = 0;
    while(data->map->map[i])
        i++;
    while(i >= 0)
        free(data->map->map[i--]);
    free(data->map->map);
    free(data->img);
}

void ft_error(t_data *data, char *str, int num)
{
    if(num == 1)
        free_map(data);
    perror(str);
    exit(EXIT_FAILURE);
}

void check_fd(char *fd)
{
    fd = fd + (ft_strlen(fd) - 4);
    if(ft_strncmp(fd, ".ber", 4))
    {
        perror("Error: Wrong file extension.\n");
        exit(EXIT_FAILURE);
    }
}