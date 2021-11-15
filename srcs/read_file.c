#include "../include/fdf.h"

void    free_matrice(char **mat)
{
    int i;

    i = -1;
    if (mat)
    {
        while (mat[++i])
            free(mat[i]);
        free(mat);
    }
}

void    count_line(char *file, t_fdf *fdf)
{
    int fd;
    char *line;
    char **matrice;
    int     i;

    fd = open(file, O_RDONLY);
    while (gnl(fd, &line) > 0)
    {
        i = 0;
        fdf->lentgh++;
        matrice = ft_split(line, ' ');
        while (matrice[i])
            i++;
        if (fdf->width < i)
            fdf->width = i;
        free_matrice(matrice);
        free(line);
    }
}


void    read_file(char *file, t_fdf *fdf)
{
    int fd;
    char *line;
    char **matrice;
    int x;
    int y;

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_fd("fdf error : ", 2);
        ft_putendl_fd(strerror(errno), 2);
        exit(1);
    }
    line = NULL;
    x = 0;
    count_line(file, fdf);
    fdf->matrice = malloc(sizeof(int*) * fdf->lentgh);
    while (gnl(fd, &line) > 0)
    {
        matrice = ft_split(line, ' ');
        y = 0;
        fdf->matrice[x] = malloc(sizeof(int) * fdf->width);
        while (matrice[y])
        {
            fdf->matrice[x][y] = ft_atoi(matrice[y]);
            y++;
        }
        x++;
        free_matrice(matrice);
        free(line);
    }
}