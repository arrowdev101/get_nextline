/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagguine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:06:44 by bagguine          #+#    #+#             */
/*   Updated: 2023/12/20 22:51:40 by bagguine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*byte_pointer;

	byte_pointer = (unsigned char *)str;
	while (n)
	{
		*byte_pointer = 0;
		byte_pointer++;
		n--;
	}
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*dest;
	size_t	total;

	total = nitems * size;
	if (nitems != 0 && size != 0 && total / size != nitems)
		return (NULL);
	dest = malloc(total);
	if (!dest)
		return (0);
	ft_bzero(dest, total);
	return (dest);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	size_t	i;
	char	*dest;

	if (!src)
	{
		return (NULL);
	}
	len = ft_strlen(src);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i < len && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		res[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		res[j++] = s2[i++];
	}
	res[j] = '\0';
	return (res);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*substring;

	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return ((char *)ft_calloc(1, sizeof(char)));
	if (ft_strlen(s) <= start + len)
		substring = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		substring = malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	while (s[start] && j < len)
		substring[j++] = s[start++];
	substring[j] = '\0';
	return (substring);
}
