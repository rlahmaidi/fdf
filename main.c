#include "include/fdf.h"

int     main_loop(void *fdf)
{
    printf("%d %d\n", ((t_fdf*)fdf)->win_height, ((t_fdf*)fdf)->win_width);
    
    return 0;
}

int     main(int ac, char **av)
{
    t_fdf fdf;
    fdf.win_height = 1000;
    fdf.win_width = 2000;
    if (ac == 2)
    {
        read_file(av[1], &fdf);
        fdf.mlx_ptr = mlx_init();
        fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, fdf.win_width, fdf.win_height, "fdf");
        fdf.img.img = mlx_new_image(fdf.mlx_ptr, fdf.win_width, fdf.win_height);
        fdf.img.addr = mlx_get_data_addr(fdf.img.img, &(fdf.img.bits_per_pixel), &(fdf.img.line_length), &(fdf.img.endian));
        my_mlx_pixel_put(&(fdf.img), 1000, 500, 0x00FF0000);
        mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img.img, 0, 0);
        //mlx_loop_hook(fdf.mlx_ptr, main_loop, &fdf);
        mlx_loop(fdf.mlx_ptr);
    }
    return 0;
}