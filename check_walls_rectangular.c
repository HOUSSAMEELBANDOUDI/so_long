# include "so_long.h"

void    ft_is_rectangular(t_map *map)
{
    int i;
    int size;

    i = 1;
    while (i < map->lines)
    {
        size = ft_strlen(map->carte[i]) - 1;
        if (i == map->lines - 1)
            size++;
        if (size != map->columns)
        {
            ft_putstr("Error: map must be rectangular\n");
            ft_free(map);
            exit(1);
        }
        i++;
    }
}

void    ft_set_errors(t_map *map, char *str)
{
    ft_putstr(str); // ft_putstr;
    ft_free(map);
    exit(1);
}

void   ft_check_wall(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (i < map->lines && map->carte[i][0] == '1' && map->carte[i][map->columns -1] == '1')
    {
        if (i == 0 || i == map->lines - 1)
        {
            j = 0;
            while (j < map->columns)
            {
                if (map->carte[i][j] != '1')
                    ft_set_errors(map, "Error: map must be surrounded by walls\n");
                j++;
            }
        }
        i++;
    }
    if (i < map->lines)
        ft_set_errors(map, "Error: map must be surrounded by walls\n");
}

void    ft_check_name(t_map *map)
{
    int len;

    len = ft_strlen(map->file);
    if (!(len >= 4 && map->file[len - 1] == 'r' && map->file[len - 2] == 'e'
        && map->file[len - 3] == 'b' && map->file[len - 4] == '.'))
        ft_set_errors(map, "Error: map must be ended with .ber\n");
}