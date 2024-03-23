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

void    ft_get_map(t_map *map)
{
    char    *str;
    int     fd;
    int     j;

    map->lines = 0;
    fd = open(map->file, O_RDONLY);
    if (fd < 0)
    {
        //printf("Error: open file failed\n");
        perror ("Error");
        exit(1);
    }
    while ((str = get_next_line(fd)) != NULL)
    {
        map->lines++;
        free(str);
    }
    close(fd);
    map->carte = ft_calloc(sizeof(char *), map->lines);
    if (!map->carte)
    {
        ft_putstr("Memory allocation failed\n");
        exit(1);
    }
    fd = open(map->file, O_RDONLY);
    j = 0;
    while (j < map->lines)
        map->carte[j++] = get_next_line(fd);
    close(fd);
    map->columns = ft_strlen(map->carte[0]) - 1;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        ft_putstr("Usage: invalid [map_file]\n");
        return (1);
    }
    t_map *map = malloc(sizeof(t_map));
    t_data *data = malloc(sizeof(t_data));
    t_img *img = malloc(sizeof(t_img));

    
    if (!map || !data || !img)
    {
        ft_putstr("Memory allocation failed");
        return (1);
    }

    map->file = av[1];
    ft_get_map(map);
    ft_check_characters(map);
    ft_check_wall(map);
    ft_is_rectangular(map);
    ft_check_name(map);
    ft_check_path(map);
    data->img = img;
    data->map = map;
    ft_init(data, map);
    ft_get_images(data, map);
    mlx_loop(data->mlx_ptr);


    ft_free(map);
    free(map);
    return (0);
}
