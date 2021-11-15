#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>
#include <sys/errno.h>
#define BUFFER_SIZE 32

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


typedef struct s_fdf
{
    int     lentgh;
    int     width;
    int     win_width;
    int     win_height;
    int     **matrice;
    void    *mlx_ptr;
    void    *win_ptr;
    t_data  img;
}  t_fdf;

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strndup(const char *s1, size_t n);
int			gnl(int fd, char **line);

// read 
void    read_file(char *file, t_fdf *fdf);

//draw
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// utils
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);


#endif