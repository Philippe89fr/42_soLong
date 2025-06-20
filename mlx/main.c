/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:44:02 by vincent           #+#    #+#             */
/*   Updated: 2024/12/16 09:59:49 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

int	ft_ber_check(char *fichier)
{
	int	i;

	i = strlen(fichier);
	if (ft_strnstr(fichier, ".ber", i))
		return (1);
	return (0);
}

int	ft_map_check_set_up(t_data *data, char *fichier)
{
	data->map = ft_get_map(fichier);
	if (!data->map)
		return (0);
	if (!ft_no_map_check(fichier)
		|| !ft_walls_check_2((const char **)data->map)
		|| !ft_rectangle_check((const char **)data->map)
		|| !ft_blank_line_check(fichier) || !ft_ber_check(fichier)
		|| !ft_walls_check_1((const char **)data->map))
	{
		ft_printf("Probleme de mur, de rectangle ou empty line");
		ft_liberator_max(data->map);
		return (0);
	}
	if (!ft_dragon_check((const char **)data->map, data)
		|| !ft_gold_exit_check((const char **)data->map, data)
		|| !ft_component_check((const char **)data->map))
	{
		ft_printf("Probleme de dragon, d or ou d exit ou autre");
		ft_liberator_max(data->map);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_printf("wrong input"), 0);
	if (ft_map_check_set_up(&data, av[1]) == 0)
		return (0);
	data.map1 = ft_get_map(av[1]);
	ft_put_2_start(data.map1, data.dragon_y, data.dragon_x);
	ft_fload_2b(data.map1);
	if (!ft_fload_check(data.map1))
		return (ft_printf("Map KO"), ft_liberator_max(data.map1),
			ft_liberator_max(data.map), 0);
	if (ft_window_load(&data) == 0)
		return (0);
	if (ft_images_load_1(&data) == 0 || ft_images_load_2(&data) == 0
		|| ft_images_load_3(&data) == 0)
	{
		ft_printf("Erreur de loading photo.\n");
		return (0);
	}
	ft_put_wall_2(data.map, &data);
	mlx_key_hook(data.wind1, handle_input, &data);
	mlx_hook(data.wind1, 17, 0, handle_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
