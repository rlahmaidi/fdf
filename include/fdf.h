#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>
#include <sys/errno.h>
#define BUFFER_SIZE 32

typedef struct s_fdf
{
    int     lentgh;
    int     width;
    int     **matrice;
    void    *mlx_ptr;
    void    *win_ptr;
}  t_fdf;

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strndup(const char *s1, size_t n);
int			gnl(int fd, char **line);

// read 
void    read_file(char *file, t_fdf *fdf);

// utils
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);


#endif