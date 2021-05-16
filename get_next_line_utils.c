/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:18:45 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/13 13:18:45 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		len;
	const char	*c;

	if (!dst || !src)
		return (0);
	len = size;
	c = src;
	if (size != 0)
	{
		while (--len && *src)
			*dst++ = *src++;
		if (len)
			*dst++ = *src++;
	}
	if (len == 0 && size != 0)
		*dst = '\0';
	return (ft_strlen(c));
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	size_t			len;
	unsigned char	*p;
	unsigned char	str;

	if (s == NULL)
		return (NULL);
	i = 0;
	p = (unsigned char *)s;
	len = ft_strlen(s);
	str = (unsigned char)c;
	while (i <= len)
	{
		if (*p == str)
			return ((void *)p);
		i++;
		p++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen((char *)s1);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2, ssize_t num_read)
{
	size_t	i;
	size_t	j;
	char	*str;

	s2[num_read] = '\0';
	if (!s1)
		return (ft_strdup(s2));
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}
