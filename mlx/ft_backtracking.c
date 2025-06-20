/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:57:10 by prambaud          #+#    #+#             */
/*   Updated: 2024/12/12 10:41:48 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

int	ft_put_2a(char **map, int i, int j)
{
	int	count;

	count = 0;
	if (map[i][j + 1] == '0' || map[i][j + 1] == 'C' || map[i][j + 1] == 'E'
		|| map[i][j + 1] == 'P')
	{
		map[i][j + 1] = '2';
		count++;
	}
	if (map[i][j - 1] == '0' || map[i][j - 1] == 'C' || map[i][j - 1] == 'E'
		|| map[i][j - 1] == 'P')
	{
		map[i][j - 1] = '2';
		count++;
	}
	return (count);
}

int	ft_put_2(char **map, int i, int j)
{
	int	count;

	count = 0;
	if (map[i + 1][j] == '0' || map[i + 1][j] == 'C' || map[i + 1][j] == 'E'
		|| map[i + 1][j] == 'P')
	{
		map[i + 1][j] = '2';
		count++;
	}
	if (map[i - 1][j] == '0' || map[i - 1][j] == 'C' || map[i - 1][j] == 'E'
		|| map[i - 1][j] == 'P')
	{
		map[i - 1][j] = '2';
		count++;
	}
	count = ft_put_2a(map, i, j);
	return (count);
}

int	ft_fload_2a(char **map)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	k = 0;
	j = 1;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '2')
				k = k + ft_put_2(map, i, j);
			j++;
		}
		j = 1;
		i++;
	}
	return (k);
}

void	ft_fload_2b(char **map)
{
	int	i;
	int	j;
	int	k;

	k = 1;
	i = 1;
	j = 1;
	while (k != 0)
	{
		k = ft_fload_2a(map);
	}
}

int	ft_fload_check(char **map)
{
	size_t	i;
	size_t	c;
	size_t	j;

	i = ((j = 0));
	c = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				c++;
			if (map[i][j] == 'C')
				c++;
			if (map[i][j] == 'P')
				c++;
			j++;
		}
		i++;
		j = 0;
	}
	if (c != 0)
		return (0);
	return (1);
}
