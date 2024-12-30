/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:21:29 by aaleixo-          #+#    #+#             */
/*   Updated: 2024/12/28 15:21:29 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/so_long.h"

void window_definer(t_data *data, char **argv)
{
    int fd;

    fd = open(argv[1], O_RDONLY);
    if(fd < 0)
        ft_error(data, "Error: No map found at designated path.\n", 0);
    if(ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
        ft_error(data, "Error: Incorrect file format.\n", 0);
    data->window_x = (ft_line_length(fd) * IMG_SIZE);
    data->window_y = (ft_count_lines(fd) * IMG_SIZE);
}

void map_creator(t_data *data)
{
    data->map->x = 0;
    data->map->y = 0;
    while(data->map->y < (data->window_y / IMG_SIZE))
    {
        if(data->map->map[data->map->y][data->map->x] == 'P')
            player_image(data);
        else if(data->map->map[data->map->y][data->map->x] == '1')
            obj_image(data, "./textures/wall.xpm");
        else if(data->map->map[data->map->y][data->map->x] == 'C')
            obj_image(data, "./textures/collectable.xpm");
        else if(data->map->map[data->map->y][data->map->x] == 'E')
            obj_image(data, "./textures/exit.xpm");
        if(data->map->x < (data->window_x / IMG_SIZE))
            data->map->x++;
        else
        {
            data->map->y++;
            data->map->x = 0;
        }
    }
}

void map_check(t_data *data)
{
    int y;
    int player;
    int exit;

    player = 0;
    exit = 0;
    y = 0;
    data->map->collectables = 0;
    while(data->map->map && data->map->map[y])
    {
        player += ft_char_count(data->map->map[y], 'P');
        exit += ft_char_count(data->map->map[y], 'E');
        data->map->collectables += ft_char_count(data->map->map[y], 'C');
        y++;
    }
    if(player != 1)
        ft_error(data, "Error: Incorrect amount of starting areas.\n", 1);
    if(exit != 1)
        ft_error(data, "Error: Incorrect amount of exits.\n", 1);
    if(data->map->collectables == 0)
        ft_error(data, "Error: There are no collectables in this map.\n", 1);
}

void border_check(t_data *data)
{
    int x;
    int y;

    y = 0;
    while(y < (data->window_y / IMG_SIZE))
    {
        if((int)ft_strlen(data->map->map[y]) != data->window_x / IMG_SIZE)
            ft_error(data, "Error: Map isn't rectangular.\n", 1);
        x = 0;
        while(x < (data->window_y / IMG_SIZE))
        {
            if(ft_strchr("01CPE", data->map->map[y][x]) == NULL)
                ft_error(data, "Error: Map is Invalid.\n", 1);
            else if(((y == 0) || (x == 0)) && data->map->map[y][x] != '1')
                ft_error(data, "Error: Sides of map aren't completely walls.\n", 1);
            else if((y == (data->window_y / 7) || x == (data->window_x / 7)) && data->map->map[y][x] != '1')
                ft_error(data, "Error: Sides of map aren't completely walls.\n", 1);
            x++;
        }
        y++;
    }
}

void ber_to_array(t_data *data, char **argv)
{
    int fd;
    int i;
    int bytes;
    char buffer[2];
    char *temp;

    fd = open(argv[1], O_RDONLY);
    i = 0;
    bytes = 1;
    buffer[1] = '\0';
    while ((bytes = read(fd, buffer, 1)) == 1)
    {
        if (buffer[0] != '\n')
        {
            if (!data->map->map[i])
                data->map->map[i] = ft_strdup("");

            temp = ft_strjoin(data->map->map[i], buffer);
            if (!temp)
            {
                close(fd);
                ft_error(data, "Error: Memory allocation failed.\n", 1);
            }

            free(data->map->map[i]);
            data->map->map[i] = temp;
        }
        else
            i++;
    }
    if(data->window_x / i == IMG_SIZE)
        ft_error(data, "Error: Incorrect map size.\n", 1);
    map_check(data);
    border_check(data);
}