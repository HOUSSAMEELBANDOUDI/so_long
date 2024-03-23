#include "so_long.h"

void ft_free(t_map *map)
{
    int i;

    i = 0;
    while (i < map->lines)
        free(map->carte[i++]);
    free(map->carte);
    if (map->c_map != NULL)
    {
        i = 0;
        while (i < map->lines)
            free(map->c_map[i++]);
        free(map->c_map);
    }  
}
void    ft_is_valid_char(char c,t_map *map)
{
    if (!(c == '0' || c == '1' || c == 'E' || c == 'P' || c == 'C'))
    {
        ft_putstr("Error: Invalid character in the map\n");
        ft_free(map);
        exit (1);
    }
}

void   ft_check_exit_player_collect(int player, int ext, int collect, t_map *map)
{
    if (player != 1)
    {
        ft_putstr("Error: The map must contain 1 player\n");
        ft_free(map);
        exit (1);
    }
    if (ext != 1)
    {
        ft_putstr("Error: The map must contain 1 exit\n");
        ft_free(map);
        exit (1);
    }
    if (collect == 0)
    {
        ft_putstr("Error: the map must contain at least 1 collectible\n");
        ft_free(map);
        exit (1);
    }
}

void    ft_check_characters(t_map *map)
{
    int i;
    int player = 0;
    int ext = 0;
    int collect = 0;
    int j;

    i = 0;
    while (i < map->lines)
    {
        j = 0;
        while (j < map->columns)
        {
            ft_is_valid_char(map->carte[i][j], map);
            if (map->carte[i][j] == 'P')
            {
                player++;
                map->p_x = i;
                map->p_y = j;
            }
            else if (map->carte[i][j] == 'E')
                ext++;
            else if (map->carte[i][j] == 'C')
                collect++;
            j++;
        }
        i++;
    }
    ft_check_exit_player_collect(player, ext, collect, map);
}
