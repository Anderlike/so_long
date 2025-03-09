/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:48:26 by marvin            #+#    #+#             */
/*   Updated: 2024/12/28 15:48:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./ft_printf/ft_printf.h"
# include "./ft_printf/get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"

# define PLAYER "textures/player.xpm"
# define EXIT "textures/exit.xpm"
# define WALL "textures/wall.xpm"
# define GROUND "textures/ground.xpm"
# define COIN "textures/coin.xpm"
# define IMG_SIZE 64

typedef struct s_map
{
	int		fd;
	int		line_count;
	size_t	line_len;
	int		count_p;
	int		count_e;
	int		count_c;
	char	*path;
	char	**map;
	int		can_exit;
	int		collected;

}				t_map;

typedef struct s_im
{
	void	*mlx_img;
	int		width;
	int		height;
	void	*wall;
	void	*exit;
	void	*ground;
	void	*player;
	int		line_length;
	void	*coin;

}	t_im;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		steps_count;
	int		p_i;
	int		p_j;
	int		i;
	int		j;
	int		win_height;
	int		win_width;
	t_im	img;
	t_map	map;

}				t_data;

int		retrieve_line_number(char *path);
void	create_map(char *path, t_data *data);
void	put_input_in_map(int row, int column, int i, t_data *data);
void	ft_free(char **tab);
void 	ft_error(t_data *data, char *error, int bool);
void	init_map(t_data *data);
void	init_player(t_data *data);
int		check_map(t_data *data);
int		check_chars(t_data *data);
int		check_rectangle(t_data *data);
int		check_edges(int line_count, char **map);
int		check_top_bot(int row, char **map);
int		render(t_data *data);
void	chars(t_data *data, int width, int i, int j);
int		init_window(t_data *data);
void	init_images(t_data *data);
void	loop_images(t_data data);
void	destroy_images(t_data data);
int		handle_resize(t_data *data);
void	loop_images(t_data data);
int		handle_keypress(int keysym, t_data *data);
int		handle_btnrealease(t_data *data);
void	move_msg(t_data *data);
void	move_player(t_data *data, char direction);
void	collect_coins(t_data *data, char direction);
int		win_game(t_data *data);
int		check_next_tile(t_data *data, char direction, char tile);
int	check_path(t_data *data);

#endif