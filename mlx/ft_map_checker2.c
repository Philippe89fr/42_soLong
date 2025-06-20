/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:24:23 by prambaud          #+#    #+#             */
/*   Updated: 2024/12/15 19:31:47 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

int	ft_component_check(const char **map)
{
	size_t	i;
	size_t	j;
	size_t	p;

	i = 0;
	j = 0;
	p = 0;
	if (!map)
		return (0);
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != '1'
				&& map[i][j] != '0' && map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	ft_put_2_starta(char **map, int i, int j)
{
	int	count;

	count = 0;
	if (map[i][j + 1] == '0' || map[i][j + 1] == 'C' || map[i][j + 1] == 'P')
	{
		map[i][j + 1] = '2';
		count++;
	}
	if (map[i][j - 1] == '0' || map[i][j - 1] == 'C' || map[i][j - 1] == 'P')
	{
		map[i][j - 1] = '2';
		count++;
	}
	return (count);
}

int	ft_put_2_start(char **map, int i, int j)
{
	int	count;

	count = 0;
	if (map[i + 1][j] == '0' || map[i + 1][j] == 'C' || map[i + 1][j] == 'P')
	{
		map[i + 1][j] = '2';
		count++;
	}
	if (map[i - 1][j] == '0' || map[i - 1][j] == 'C' || map[i - 1][j] == 'P')
	{
		map[i - 1][j] = '2';
		count++;
	}
	count = ft_put_2_starta(map, i, j);
	return (count);
}
