#include "so_long.h"


void    ft_replace(t_map *map, int x, int y)
{
    if (x < 0 || y < 0 || x >= map->lines || y >= map->columns || map->c_map[x][y] == '1' || map->c_map[x][y] == 'z')
        return;   
    map->c_map[x][y] = 'z';
    ft_replace(map, x - 1, y);
    ft_replace(map, x + 1, y);
    ft_replace(map, x, y - 1);
    ft_replace(map, x, y + 1);

}
void ft_check_path(t_map *map)
{
    int i;
    int j;

    ft_duplicate(map);
    ft_replace(map, map->p_x, map->p_y);
    i = 1;
    while (i < map->lines - 1)
    {
        j = 1;
        while (j < map->columns - 1)
        {
            if (map->c_map[i][j] == 'E' || map->c_map[i][j] == 'C')
                ft_set_errors(map, "Error : invalid path\n");
            j++;
        }
        i++;
    }
}

void    ft_duplicate(t_map *map)
{
    int i;
    map->c_map = ft_calloc(sizeof(char *), map->lines);

    i = 0;
    while (i < map->lines)
    {
        map->c_map[i] = ft_strdup(map->carte[i]);
        i++;
    }
}


