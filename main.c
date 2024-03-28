#include "so_long.h"

void    valid_map(t_map *map)
{
    ft_check_characters(map);
    ft_check_wall(map);
    ft_is_rectangular(map);
    ft_check_name(map);
    ft_check_path(map);
}
void l()
{
    system("leaks mlx_initiation");
}
int	main(int argc, char **argv)
{
    atexit(l);
	t_data	data;
	t_map	map;
	t_img	img;

	if (argc != 2)
    {
        ft_putstr("Usage: invalid [map_file]\n");
		exit(1);
    }
	data.map = &map;
	data.img = &img;
	map.file = argv[1];
    ft_get_map(&map); // Declaration or definition of ft_get_map should be here
    valid_map(&map); // Declaration or definition of valid_map should be here
    ft_init(&data, &map);
    ft_get_images(&data, &map);
    map.move = 0;
    ft_send_events(&data);
    return (0);
}
