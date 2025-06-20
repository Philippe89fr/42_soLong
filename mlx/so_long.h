/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:03:06 by vincent           #+#    #+#             */
/*   Updated: 2024/12/16 09:52:22 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>

typedef struct s_data
{
	void	*mlx;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*wind1;
	char	*data1;
	int		bpp1;
	int		sl1;
	int		endian1;
	int		xpm1_x;
	int		xpm1_y;
	int		dragon_x;
	int		dragon_y;
	char	**map;
	char	**map1;
	int		gold_total;
	int		gold_collected;
	int		move_count;
}			t_data;
char		**ft_get_map(char *fichier);
int			ft_dragon_check(const char **map, t_data *data);
int			ft_gold_exit_check(const char **map, t_data *data);
int			ft_rectangle_check(const char **map);
int			ft_walls_check_1(const char **map);
int			ft_walls_check_2(const char **map);
void		ft_put_wall(char **map, t_data *data);
void		ft_put_wall_1(char **map, t_data *data);
void		ft_put_wall_2(char **map, t_data *data);
int			handle_input(int keysym, t_data *data);
int			handle_close(t_data *data);
int			ft_images_load_1(t_data *data);
int			ft_images_load_2(t_data *data);
int			ft_images_load_3(t_data *data);
int			ft_window_load(t_data *data);
void		ft_free(t_data *data);
int			handle_input(int keysym, t_data *data);
int			handle_close(t_data *data);
void		ft_move_dragon_a(t_data *data);
void		ft_move_dragon_d(t_data *data);
void		ft_move_dragon_w(t_data *data);
void		ft_move_dragon_s(t_data *data);
int			ft_put_2(char **map, int i, int j);
int			ft_put_2_start(char **map, int i, int j);
int			ft_blank_line_check(char *fichier);
int			ft_fload_2a(char **map);
void		ft_fload_2b(char **map);
int			ft_fload_check(char **map);
int			ft_component_check(const char **map);
int			ft_no_map_check(char *fichier);
#endif
