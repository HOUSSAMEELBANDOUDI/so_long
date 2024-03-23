#include "so_long.h"

void    ft_init(t_data *data, t_map *map)
{
    data->mlx_ptr = mlx_init();
    if (data->mlx_ptr == NULL)
    {
        ft_putstr("Error : failed connection with x_server\n");
        exit(1);   
    }
    data->win_ptr = mlx_new_window(data->mlx_ptr, map->columns * 64,  map->lines * 64,"so_long");
    if (data->win_ptr == NULL)
    {
        ft_putstr("Error : failed to create the window\n");
        free(data->mlx_ptr);
        exit (1);
    }
}

void ft_get_images(t_data *data, t_map *map)
{
    // Check if data->img is valid
    if (!data || !data->img)
    {
        ft_putstr("Error: Invalid data structure\n");
        exit(1);
    }
    // Load images
    data->img->img1 = mlx_xpm_file_to_image(data->mlx_ptr, "texture.xpm", &data->img->w, &data->img->h);
    data->img->img2 = mlx_xpm_file_to_image(data->mlx_ptr, Walls, &data->img->w, &data->img->h);
    data->img->img3 = mlx_xpm_file_to_image(data->mlx_ptr, Player, &data->img->w, &data->img->h);
    data->img->img4 = mlx_xpm_file_to_image(data->mlx_ptr, Collect, &data->img->w, &data->img->h);
    data->img->img5 = mlx_xpm_file_to_image(data->mlx_ptr, Lbab, &data->img->w, &data->img->h);

    // Check if image loading operations are successful
    if (data->img->img1 == NULL || data->img->img2 == NULL || data->img->img3 == NULL 
        || data->img->img4 == NULL || data->img->img5 == NULL)
    {
        ft_putstr("Error: Failed to load images\n");
        exit(1);
    }

    ft_print_game(data, map); // Corrected position of the function call
}


void    ft_put_images(t_data *data, t_map *map, int i, int j)
{
    if (map->carte[i][j] == '0')
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img1, j * 64, i * 64);
    else if (map->carte[i][j] == '1')
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img2, j * 64, i * 64);
    else if (map->carte[i][j] == 'P')
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img3, j * 64, i * 64);
    else if (map->carte[i][j] == 'C')
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img4, j * 64, i * 64);
    else if (map->carte[i][j] == 'E')
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img5, j * 64, j * 64);
}   

void    ft_print_game(t_data *data, t_map *map)
{
    int i;
    int j;

    i = 0;
    while (i < map->lines)
    {
        j = 0;
        while ( j < map->columns)
        {
            ft_put_images(data, map, i, j);
            j++;
        }
        i++;
    }
}
