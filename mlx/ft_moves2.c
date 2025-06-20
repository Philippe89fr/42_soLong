/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:38:58 by prambaud          #+#    #+#             */
/*   Updated: 2024/12/11 12:40:09 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"
#include <X11/keysym.h>

void	ft_free(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img1);
	mlx_destroy_image(data->mlx, data->img2);
	mlx_destroy_image(data->mlx, data->img3);
	mlx_destroy_image(data->mlx, data->img4);
	mlx_destroy_image(data->mlx, data->img5);
	mlx_destroy_window(data->mlx, data->wind1);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_liberator_max(data->map);
	ft_liberator_max(data->map1);
	exit(0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_free(data);
	else if (keysym == XK_a)
	{
		ft_move_dragon_a(data);
	}
	else if (keysym == XK_d)
	{
		ft_move_dragon_d(data);
	}
	else if (keysym == XK_w)
	{
		ft_move_dragon_w(data);
	}
	else if (keysym == XK_s)
	{
		ft_move_dragon_s(data);
	}
	return (0);
}

int	handle_close(t_data *data)
{
	ft_printf("Fermeture du jeu\n");
	ft_free(data);
	exit(0);
}
