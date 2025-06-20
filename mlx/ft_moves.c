/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:38:58 by prambaud          #+#    #+#             */
/*   Updated: 2024/12/11 12:08:42 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"
#include <X11/keysym.h>

void	ft_move_dragon_a(t_data *data)
{
	if (data->map[data->dragon_y][data->dragon_x - 1] == '0')
	{
		data->map[data->dragon_y][data->dragon_x - 1] = 'P';
		data->map[data->dragon_y][data->dragon_x] = '0';
		data->dragon_x = data->dragon_x - 1;
		data->move_count++;
		ft_put_wall_2(data->map, data);
	}
	else if (data->map[data->dragon_y][data->dragon_x - 1] == 'C')
	{
		data->map[data->dragon_y][data->dragon_x - 1] = 'P';
		data->map[data->dragon_y][data->dragon_x] = '0';
		data->dragon_x = data->dragon_x - 1;
		data->gold_collected++;
		data->move_count++;
		ft_put_wall_2(data->map, data);
		ft_printf("De l oooor!\n");
	}
	else if (data->map[data->dragon_y][data->dragon_x - 1] == 'E'
		&& data->gold_collected == data->gold_total)
	{
		data->move_count++;
		ft_free(data);
	}
	ft_printf("%d deplacements!\n", data->move_count);
}

void	ft_move_dragon_d(t_data *data)
{
	if (data->map[data->dragon_y][data->dragon_x + 1] == '0')
	{
		data->map[data->dragon_y][data->dragon_x + 1] = 'P';
		data->map[data->dragon_y][data->dragon_x] = '0';
		data->dragon_x = data->dragon_x + 1;
		data->move_count++;
		ft_put_wall_2(data->map, data);
	}
	else if (data->map[data->dragon_y][data->dragon_x + 1] == 'C')
	{
		data->map[data->dragon_y][data->dragon_x + 1] = 'P';
		data->map[data->dragon_y][data->dragon_x] = '0';
		data->dragon_x = data->dragon_x + 1;
		data->gold_collected++;
		data->move_count++;
		ft_put_wall_2(data->map, data);
		ft_printf("De l oooor!\n");
	}
	else if (data->map[data->dragon_y][data->dragon_x + 1] == 'E'
		&& data->gold_collected == data->gold_total)
	{
		data->move_count++;
		ft_free(data);
	}
	ft_printf("%d deplacements!\n", data->move_count);
}

void	ft_move_dragon_w(t_data *data)
{
	if (data->map[data->dragon_y - 1][data->dragon_x] == '0')
	{
		data->map[data->dragon_y - 1][data->dragon_x] = 'P';
		data->map[data->dragon_y][data->dragon_x] = '0';
		data->dragon_y = data->dragon_y - 1;
		data->move_count++;
		ft_put_wall_2(data->map, data);
	}
	else if (data->map[data->dragon_y - 1][data->dragon_x] == 'C')
	{
		data->map[data->dragon_y - 1][data->dragon_x] = 'P';
		data->map[data->dragon_y][data->dragon_x] = '0';
		data->dragon_y = data->dragon_y - 1;
		data->gold_collected++;
		data->move_count++;
		ft_put_wall_2(data->map, data);
		ft_printf("De l oooor!\n");
	}
	else if (data->map[data->dragon_y - 1][data->dragon_x] == 'E'
		&& data->gold_collected == data->gold_total)
	{
		data->move_count++;
		ft_free(data);
	}
	ft_printf("%d deplacements!\n", data->move_count);
}

void	ft_move_dragon_s(t_data *data)
{
	if (data->map[data->dragon_y + 1][data->dragon_x] == '0')
	{
		data->map[data->dragon_y + 1][data->dragon_x] = 'P';
		data->map[data->dragon_y][data->dragon_x] = '0';
		data->dragon_y = data->dragon_y + 1;
		data->move_count++;
		ft_put_wall_2(data->map, data);
	}
	else if (data->map[data->dragon_y + 1][data->dragon_x] == 'C')
	{
		data->map[data->dragon_y + 1][data->dragon_x] = 'P';
		data->map[data->dragon_y][data->dragon_x] = '0';
		data->dragon_y = data->dragon_y + 1;
		data->gold_collected++;
		data->move_count++;
		ft_put_wall_2(data->map, data);
		ft_printf("De l oooor!\n");
	}
	else if (data->map[data->dragon_y + 1][data->dragon_x] == 'E'
		&& data->gold_collected == data->gold_total)
	{
		data->move_count++;
		ft_free(data);
	}
	ft_printf("%d deplacements!\n", data->move_count);
}
