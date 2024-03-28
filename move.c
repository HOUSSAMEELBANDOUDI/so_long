/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <hel-band@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:43:53 by hel-band          #+#    #+#             */
/*   Updated: 2024/03/28 01:17:07 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_left(t_data *data, t_map *map)
{
	map = data->map;
	if (map->carte[map->p_x][map->p_y - 1] == '0')
	{
		map->carte[map->p_x][map->p_y - 1] = 'P';
		map->carte[map->p_x][map->p_y] = '0';
		map->p_y--;
		ft_putnbr(++map->move);
		ft_putchar('\n');
	}
	else if (map->carte[map->p_x][map->p_y - 1] == 'C')
	{
		map->carte[map->p_x][map->p_y - 1] = 'P';
		map->carte[map->p_x][map->p_y] = '0';
		map->p_y--;
		map->collect--;
	    ft_putnbr(++map->move);
		ft_putchar('\n');
	}
	else if (map->carte[map->p_x][map->p_y - 1] == 'E' && map->collect == 0)
	{
		ft_putstr("BRAVO YOU WIN\n");
		ft_free_all(data);
		exit(1);
	}
}

void	ft_move_right(t_data *data, t_map *map)
{
	map = data->map;
	if (map->carte[map->p_x][map->p_y + 1] == '0')
	{
		map->carte[map->p_x][map->p_y + 1] = 'P';
		map->carte[map->p_x][map->p_y] = '0';
		map->p_y++;
		ft_putnbr(++map->move);
	}
	else if (map->carte[map->p_x][map->p_y + 1] == 'C')
	{
		map->carte[map->p_x][map->p_y + 1] = 'P';
		map->carte[map->p_x][map->p_y] = '0';
		map->p_y++;
		map->collect--;
		ft_putnbr(++map->move);
		ft_putchar('\n');
	}
	else if (map->carte[map->p_x][map->p_y + 1] == 'E' && map->collect == 0)
	{
		ft_putstr("BRAVO YOU WIN");
		ft_free_all(data);
		exit(1);
	}
}

void	ft_move_up(t_data *data, t_map *map)
{
	map = data->map;
	if (map->carte[map->p_x - 1][map->p_y] == '0')
	{
		map->carte[map->p_x - 1][map->p_y] = 'P';
		map->carte[map->p_x][map->p_y] = '0';
		map->p_x--;
		ft_putnbr(++map->move);
		ft_putchar('\n');
	}
	else if (map->carte[map->p_x - 1][map->p_y] == 'C')
	{
		map->carte[map->p_x - 1][map->p_y] = 'P';
		map->carte[map->p_x][map->p_y] = '0';
		map->p_x--;
		map->collect--;
		ft_putnbr(++map->move);
		ft_putchar('\n');
	}
	else if (map->carte[map->p_x - 1][map->p_y] == 'E' && map->collect == 0)
	{
		ft_putstr("BRAVO YOU WIN\n");
		ft_free_all(data);
		exit(1);
	}
}

void	ft_move_down(t_data *data, t_map *map)
{
	map = data->map;
	if (map->carte[map->p_x + 1][map->p_y] == '0')
	{
		map->carte[map->p_x + 1][map->p_y] = 'P';
		map->carte[map->p_x][map->p_y] = '0';
		map->p_x++;
		ft_putnbr(++map->move);
		ft_putchar('\n');
	}
	else if (map->carte[map->p_x + 1][map->p_y] == 'C')
	{
		map->carte[map->p_x + 1][map->p_y] = 'P';
		map->carte[map->p_x][map->p_y] = '0';
		map->p_x++;
		map->collect--;
		ft_putnbr(++map->move);
		ft_putchar('\n');
	}
	else if (map->carte[map->p_x + 1][map->p_y] == 'E' && map->collect == 0)
	{
		ft_putstr("BRAVO YOU WIN");
		ft_free_all(data);
		exit(1);
	}
}
