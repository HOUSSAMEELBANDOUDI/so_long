#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>

# define FLOOR  "files/floor.xpm"
# define Walls "files/wall.xpm"
# define Player "files/player.xpm"
# define Collect "files/cc.xpm"
# define Lbab "files/exit.xpm"

typedef struct s_map
{
    char    **carte;
    char    **c_map;
    char    *file;
    int     lines;
    int     columns;
    int     p_x;
    int     p_y;
}             t_map;

typedef struct s_img
{
	void			*img1;
	void			*img2;
	void			*img3;
	void			*img4;
	void			*img5;
	int				w;
	int				h;
    
}					t_img;

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_img   *img;
    t_map   *map;
}           t_data;

//check map utils
void	ft_putchar(char c);
void	ft_putstr(char *s);
void    ft_free(t_map *map);
void    ft_is_valid_char(char c, t_map *map);
void    ft_check_exit_player_collect(int player, int ext, int collect, t_map *map);
void    ft_check_characters(t_map *map);
void    ft_is_rectangular(t_map *map);
void    ft_set_errors(t_map *map ,char *str);
void    ft_check_wall(t_map *map);
void    ft_check_name(t_map *map);
void    ft_replace(t_map *map, int x, int y);
void    ft_duplicate(t_map *map);
void    ft_check_path(t_map *map);
//get images
void    ft_init(t_data *data, t_map *map);
void    ft_get_images(t_data *data, t_map *map);
void    ft_put_images(t_data *data, t_map *map, int i, int j);
void    ft_print_game(t_data *data, t_map *map);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char			*get_next_line(int fd);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*ft_calloc(size_t count, size_t size);
int				ft_index(char *s);
int				ft_strlen(const char *s);
char			*ft_strjoin(char *s1, char const *s2);
char			*ft_strdup(char const *s1);
char			*ft_add(char **str, int i);
char			*ft_result(char **str, char **dst, int i);
char			*ft_get_line(char **str, char **dst, char **buffer, int fd);
#endif
