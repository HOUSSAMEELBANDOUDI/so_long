/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <hel-band@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 01:05:11 by hel-band          #+#    #+#             */
/*   Updated: 2024/03/28 01:05:13 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handle_x_press(t_data *data)
{
	ft_putstr("game closed.\n");
	ft_free_all(data);
	exit(1);
}

int	ft_handle_keypress(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		ft_putstr("game closed.\n");
		ft_free_all(data);
		exit(1);
	}
	else if (key == 13)
	{
		ft_move_up(data, data->map);
	}
	else if (key == 0)
		ft_move_left(data, data->map);
	else if (key == 1)
		ft_move_down(data, data->map);
	else if (key == 2)
		ft_move_right(data, data->map);
	ft_get_images(data, data->map);
	return (1);
}

void	ft_send_events(t_data *data)
{
	mlx_hook(data->win_ptr, 02, 1L << 0, &ft_handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 0L, &ft_handle_x_press, data);
	mlx_loop(data->mlx_ptr);
}
