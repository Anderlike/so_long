/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:31:41 by aaleixo-          #+#    #+#             */
/*   Updated: 2024/12/12 16:31:41 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/so_long.h"

int main(int argc, char **argv)
{
    t_data data;
    t_map map;

    if(argc != 2)
        ft_error(&data, "Error: Map missing, or too many maps.\n", 0);
    data.mlx = mlx_init();
    if(!data.mlx)
        ft_error(&data, "Error: mlx_init() has failed.\n", 0);
    window_definer(&data, argv);
    check_fd(argv[1]);
    map.map = ft_calloc(data.window_y + 1, sizeof(char *));
    if(!map.map)
        ft_error(&data, "Error: Calloc error.\n", 0);
    ft_initializer(&data, &map);
    ber_to_array(&data, argv);
    //need to check path to exit
    data.window = mlx_new_window(data.mlx, data.window_x, data.window_y, "Boa Sorte!");
    map_creator(&data);
    //mlx_hook(data->window, 17, 1L << 2, ft_exit, data);
    //mlx_key_hook(data->window, ft_key_hook, data);
    mlx_loop(data.mlx);
    ft_error(&data, "Error: Game failed to loop.\n", 0);
}