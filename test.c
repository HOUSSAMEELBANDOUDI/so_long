#include <mlx.h> // Include the mlx library

int main(void)
{
    void *mlx; // The magical mlx pointer
    void *win; // The window pointer
    int width = 100, height = 100;
    // Initialize mlx
    mlx = mlx_init();

    // Create a window
    win = mlx_new_window(mlx, 800, 600, "Texture Printing Spell");

    // Load a texture image
    void *img = mlx_xpm_file_to_image(mlx, "texture.xpm", &width, &height);

    // Display the texture on the window
    mlx_put_image_to_window(mlx, win, img, 0, 0);

    // Your enchanted window awaits your further commands

    mlx_loop(mlx);

    return 0;
}
