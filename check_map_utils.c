/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <hel-band@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:17:10 by hel-band          #+#    #+#             */
/*   Updated: 2024/03/27 16:17:13 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
	else
		ft_putchar(nb + 48);
}

void    ft_count_lines(t_map *map) 
{
    char    *str;
    int     fd;

    map->lines = 0;
    fd = open(map->file, O_RDONLY);
    if (fd < 0)
    {
        perror("Error");
        exit(1);
    }
    while ((str = get_next_line(fd)) != NULL) {
        map->lines++;
        free(str);
    }
    close(fd);
}

void    ft_get_map(t_map *map)
{
    int j;
    int fd;

    ft_count_lines(map);
    map->carte = ft_calloc(sizeof(char *), map->lines);
    if (!map->carte)
    {
        ft_putstr("Memory allocation failed\n");
        exit(1);
    }
    fd = open(map->file, O_RDONLY);
    if (fd < 0)
    {
        perror("Error");
        exit(1);
    }
    j = 0;
    while (j < map->lines)
        map->carte[j++] = get_next_line(fd);
    close(fd);
    map->columns = ft_strlen(map->carte[0]) - 1;
}

