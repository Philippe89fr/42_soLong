/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images_load.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:15:25 by prambaud          #+#    #+#             */
/*   Updated: 2024/12/11 15:10:34 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

int	ft_window_load(t_data *data)
{
	int	width;
	int	hight;

	hight = ft_strlen_dim2((const char **)data->map) * 50;
	width = ft_strlen((const char *)data->map[0]) * 50;
	data->mlx = mlx_init();
	data->move_count = 0;
	data->gold_collected = 0;
	if (!data->mlx)
	{
		ft_printf("Erreur: mlx_init a échoué.\n");
		ft_liberator_max(data->map);
		ft_liberator_max(data->map1);
		return (0);
	}
	data->wind1 = mlx_new_window(data->mlx, width, hight, "My 1st window");
	if (!data->wind1)
	{
		ft_printf("Erreur: mlx_new_window a échoué.\n");
		free(data->mlx);
		ft_liberator_max(data->map);
		ft_liberator_max(data->map1);
		return (0);
	}
	return (1);
}

int	ft_images_load_1(t_data *data)
{
	data->img3 = mlx_xpm_file_to_image(data->mlx, "mlx/gold.xpm", &data->xpm1_x,
			&data->xpm1_y);
	if (!data->img3)
	{
		mlx_destroy_image(data->mlx, data->img1);
		mlx_destroy_image(data->mlx, data->img2);
		mlx_destroy_window(data->mlx, data->wind1);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_liberator_max(data->map);
		ft_liberator_max(data->map1);
		return (0);
	}
	data->img2 = mlx_xpm_file_to_image(data->mlx, "mlx/herbe.xpm",
			&data->xpm1_x, &data->xpm1_y);
	if (!data->img2)
	{
		mlx_destroy_image(data->mlx, data->img1);
		mlx_destroy_window(data->mlx, data->wind1);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_liberator_max(data->map);
		return (ft_liberator_max(data->map1), 0);
	}
	return (1);
}

int	ft_images_load_2(t_data *data)
{
	data->img1 = mlx_xpm_file_to_image(data->mlx, "mlx/wall2.xpm",
			&data->xpm1_x, &data->xpm1_y);
	if (!data->img1)
	{
		mlx_destroy_window(data->mlx, data->wind1);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_liberator_max(data->map);
		ft_liberator_max(data->map1);
		return (0);
	}
	data->img4 = mlx_xpm_file_to_image(data->mlx, "mlx/player.xpm",
			&data->xpm1_x, &data->xpm1_y);
	if (!data->img4)
	{
		mlx_destroy_image(data->mlx, data->img1);
		mlx_destroy_image(data->mlx, data->img2);
		mlx_destroy_image(data->mlx, data->img3);
		mlx_destroy_window(data->mlx, data->wind1);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_liberator_max(data->map);
		return (ft_liberator_max(data->map1), 0);
	}
	return (1);
}

int	ft_images_load_3(t_data *data)
{
	data->img5 = mlx_xpm_file_to_image(data->mlx, "mlx/exit.xpm", &data->xpm1_x,
			&data->xpm1_y);
	if (!data->img5)
	{
		mlx_destroy_image(data->mlx, data->img1);
		mlx_destroy_image(data->mlx, data->img2);
		mlx_destroy_image(data->mlx, data->img3);
		mlx_destroy_image(data->mlx, data->img4);
		mlx_destroy_window(data->mlx, data->wind1);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_liberator_max(data->map);
		ft_liberator_max(data->map1);
		return (0);
	}
	return (1);
}
