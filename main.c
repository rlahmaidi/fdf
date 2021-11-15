#include "include/fdf.h"


int     main(int ac, char **av)
{
    t_fdf fdf;
    int x, y;
    if (ac == 2)
    {
        read_file(av[1], &fdf);
        
    }
    return 0;
}