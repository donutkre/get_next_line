/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:22:46 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/15 11:22:46 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*(unsigned char *)(s + i++) = (unsigned char)c;
	return (s);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = count * size;
	ptr = malloc(i);
	if (ptr)
		ft_memset(ptr, 0, i);
	return (ptr);
}

int	read_buf(int fd, char **backup)
{
	char		*buf;
	ssize_t		read_size;

	read_size = BUFFER_SIZE;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (-1);
	while (ft_strchr(*backup, '\n') == NULL && read_size == BUFFER_SIZE)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
			break ;
		*backup = ft_strjoin(*backup, buf, read_size);
		if (*backup == NULL)
		{
			read_size = -1;
			break ;
		}
	}
	free(buf);
	if (read_size < 0)
		return (-1);
	if (ft_strchr(*backup, '\n') != NULL)
		return (1);
	return (0);
}

char	*next_line(char **backup)
{
	char		*line;
	char		*tmp;
	char		*newline;

	newline = ft_strchr(*backup, '\n');
	if (newline == NULL)
	{
		tmp = ft_strdup(*backup);
		free(*backup);
		*backup = NULL;
		return (tmp);
	}
	line = (char *)malloc(sizeof(char) * (newline - *backup + 1));
	if (!line)
		return (NULL);
	ft_strlcpy(line, *backup, newline - *backup + 1);
	tmp = *backup;
	*backup = ft_strdup(++newline);
	if (*backup == NULL)
		return (NULL);
	free(tmp);
	return (line);
}

int	get_next_line(int fd, char **line)
{
	static char	*s;
	int			n;

	n = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (ft_strchr(s, '\n') == NULL)
	{
		n = read_buf(fd, &s);
		if (n == -1)
			return (-1);
	}
	if ((n == 1) || (n == 0))
	{
		*line = next_line(&s);
		if (*line == NULL)
			return (-1);
	}
	return (n);
}
