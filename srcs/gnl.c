/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlahmaid <rlahmaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:25:21 by rlahmaid          #+#    #+#             */
/*   Updated: 2021/11/15 18:13:16 by rlahmaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		ft_readline(int fd, char **gard)
{
	char	*buf;
	char	*tmp;
	int		n;

	if (!(buf = malloc(BUFFER_SIZE + 1)) || (read(fd, NULL, 0) == -1))
	{
		if (buf)
			free(buf);
		return (-1);
	}
	while ((n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[n] = '\0';
		tmp = ft_strdup(*gard);
		free(*gard);
		if (!(*gard = ft_strjoin(tmp, buf)))
			return (-1);
		free(tmp);
		if (ft_strchr(*gard, '\n'))
			break ;
	}
	free(buf);
	return (n);
}

int		gnl(int fd, char **line)
{
	static char		*gard;
	char			*s;
	int				n;
	char			*tmp;

	if (!gard)
		gard = ft_strdup("");
	if ((n = ft_readline(fd, &gard)) < 0)
		return (-1);
	if ((s = ft_strchr(gard, '\n')))
	{
		*line = ft_strndup(gard, s - gard);
		tmp = ft_strdup(ft_strchr(gard, '\n') + 1);
		free(gard);
		gard = ft_strdup(tmp);
		free(tmp);
		return (1);
	}
	if (!n && gard)
	{
		*line = ft_strdup(gard);
		free(gard);
		gard = NULL;
	}
	return (0);
}
