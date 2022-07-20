/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:54:20 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/20 09:54:28 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free_ptr(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static t_bool	ft_read_file(char **s_fdbuf, int fd, char *buf)
{
	ssize_t	read_bytes;
	char	*fdbuf_temp;

	read_bytes = 1;
	if (s_fdbuf[fd] == NULL)
		return (FALSE);
	while (ft_strchr(s_fdbuf[fd], '\n') == NULL && read_bytes)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if ((!ft_strlen(s_fdbuf[fd]) && read_bytes == 0) || read_bytes == -1)
		{
			ft_free_ptr(&s_fdbuf[fd]);
			return (FALSE);
		}
		else if (read_bytes == 0)
			break ;
		buf[read_bytes] = '\0';
		fdbuf_temp = s_fdbuf[fd];
		s_fdbuf[fd] = ft_strjoin(s_fdbuf[fd], buf);
		ft_free_ptr(&fdbuf_temp);
	}
	return (TRUE);
}

static char	*ft_get_line(char **s_fdbuf, int fd)
{
	char	*line;
	char	*fdbuf;
	int		buf_idx;

	fdbuf = s_fdbuf[fd];
	if (ft_strchr(fdbuf, '\n') == NULL)
	{
		line = ft_strdup(fdbuf);
		s_fdbuf[fd] = NULL;
	}
	else
	{
		buf_idx = 0;
		while (fdbuf[buf_idx] != '\n')
			buf_idx++;
		line = (char *)malloc(buf_idx + 2);
		if (line == NULL)
			return (NULL);
		if (ft_strlcpy(line, fdbuf, buf_idx + 2) == 0)
			return (NULL);
		s_fdbuf[fd] = ft_strdup((char *)(fdbuf + buf_idx + 1));
	}
	ft_free_ptr(&fdbuf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s_fdbuf[OPEN_MAX];
	char		*buf;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	if (s_fdbuf[fd] == NULL)
		s_fdbuf[fd] = ft_strdup("");
	if (ft_read_file(s_fdbuf, fd, buf) == FALSE)
	{
		ft_free_ptr(&buf);
		return (NULL);
	}
	line = ft_get_line(s_fdbuf, fd);
	if (line == NULL)
	{
		ft_free_ptr(&s_fdbuf[fd]);
		return (NULL);
	}
	ft_free_ptr(&buf);
	return (line);
}
