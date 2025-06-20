/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:24:23 by prambaud          #+#    #+#             */
/*   Updated: 2024/12/10 11:03:14 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

int	ft_rectangle_check(const char **map)
{
	size_t	i;
	size_t	size;

	if (!map)
		return (0);
	i = 1;
	size = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != size)
			return (0);
		i++;
	}
	return (1);
}

int	ft_walls_check_1(const char **map)
{
	size_t	i;
	size_t	size2;

	if (!map || !ft_rectangle_check(map))
		return (0);
	i = 0;
	size2 = ft_strlen_dim2(map);
	while (map[0][i] && map[size2 - 1][i])
	{
		if (map[0][i] != '1' || map[size2 - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_walls_check_2(const char **map)
{
	size_t	j;
	size_t	size;

	if (!map || !ft_rectangle_check(map))
		return (0);
	j = 0;
	size = ft_strlen(map[0]);
	while (map[j])
	{
		if (map[j][0] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (map[j])
	{
		if (map[j][size - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	ft_dragon_check(const char **map, t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	p;

	i = 0;
	j = 0;
	p = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				p++;
				data->dragon_y = i;
				data->dragon_x = j;
			}
			j++;
		}
		i++;
		j = 0;
	}
	if (p != 1)
		return (0);
	return (1);
}

int	ft_gold_exit_check(const char **map, t_data *data)
{
	size_t	i;
	size_t	c;
	size_t	j;
	size_t	e;

	i = ((j = 0));
	e = 0;
	c = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				e++;
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
		j = 0;
	}
	data->gold_total = c;
	if (e != 1 || c < 1)
		return (0);
	return (1);
}
