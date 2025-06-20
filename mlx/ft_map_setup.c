/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:26:10 by prambaud          #+#    #+#             */
/*   Updated: 2024/12/16 10:03:23 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

#define BUFFER_SIZE 999999

char	**ft_get_map(char *fichier)
{
	int		fd;
	int		read_count;
	char	buf[BUFFER_SIZE + 1];
	char	**map;

	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		return (NULL);
	read_count = read(fd, buf, BUFFER_SIZE);
	if (read_count == -1)
		return (NULL);
	buf[read_count] = '\0';
	map = ft_split(buf, '\n');
	close(fd);
	return (map);
}

int	ft_blank_line_check(char *fichier)
{
	int		fd;
	int		read_count;
	char	buf[2];
	char	buf2[2];

	read_count = -1;
	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read_count != 0)
	{
		read_count = read(fd, buf, 1);
		if (read_count == -1)
			return (close(fd), 0);
		read_count = read(fd, buf2, 1);
		if (read_count == -1)
			return (close(fd), 0);
		buf[1] = ((buf[1] = '\0'));
		if (buf[0] == '\n' && buf2[0] == '\n')
			return (close(fd), 0);
	}
	close(fd);
	return (1);
}

void	ft_put_wall_1(char **map, t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->wind1, data->img1, j
					* 50, i * 50);
			if (map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->wind1, data->img2, j
					* 50, i * 50);
			if (map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->wind1, data->img3, j
					* 50, i * 50);
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_put_wall_2(char **map, t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->wind1, data->img5, j
					* 50, i * 50);
			if (map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->wind1, data->img4, j
					* 50, i * 50);
			j++;
		}
		i++;
		j = 0;
	}
	ft_put_wall_1(map, data);
}

int	ft_no_map_check(char *fichier)
{
	int		fd;
	int		read_count;
	char	buf[2];

	read_count = -1;
	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		return (0);
	read_count = read(fd, buf, 1);
	if (read_count == -1)
		return (close(fd), 0);
	if (read_count == 0)
		return (close(fd), 0);
	return (1);
}
