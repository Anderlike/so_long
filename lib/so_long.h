/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:29:00 by aaleixo-          #+#    #+#             */
/*   Updated: 2024/12/12 16:29:00 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define IMG_SIZE 8

typedef struct s_img
{
    void *player;
    void *wall;
    void *collectable;
}   t_img;

typedef struct s_map
{
    char **map;
    void *obj;
    int x;
    int y;
    int collectables;
}   t_map;

typedef struct s_data
{
    void *mlx;
    void *window;
    int window_x;
    int window_y;
    int player_x;
    int player_y;
    int collectables;
    int step_counter;
    t_map *map;
    t_img *img;
}   t_data;

void ft_mlx_pixel_put(t_data *data, int x, int y, int color);
int	ft_line_length(int fd);
int	ft_count_lines(int fd);
void player_image(t_data *data);
void obj_image(t_data *data, char *path);
void window_definer(t_data *data, char **argv);
void map_creator(t_data *data);
void check_fd(char *fd);
int ft_char_count(const char *str, char c);
void ber_to_array(t_data *data, char **argv);
void ft_error(t_data *data, char *str, int num);
void	ft_initializer(t_data *data, t_map *map);

#endif