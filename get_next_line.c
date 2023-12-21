/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagguine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:02:22 by bagguine          #+#    #+#             */
/*   Updated: 2023/12/20 23:07:39 by bagguine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_str_left(char **str, int nl)
{
	char	*res;
	int		i;

	i = ft_strlen(*str + nl);
	res = ft_substr(*str, nl, i);
	free(*str);
	*str = NULL;
	return (res);
}

char	*ft_str_nl(char **temp, char **str_nl, int nl)
{
	*str_nl = ft_substr(*temp, 0, nl + 1);
	*temp = ft_str_left(temp, nl + 1);
	return (*str_nl);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*str_nl;
	char		buffer_read[BUFFER_SIZE + 1];
	int			size_read;
	int			nl;

	if (!temp)
		temp = ft_strdup("");
	size_read = read(fd, buffer_read, BUFFER_SIZE);
	while (size_read >= 0)
	{
		buffer_read[size_read] = 0;
		temp = ft_strjoin(temp, buffer_read);
		nl = check_nl(temp);
		if (nl != -1)
			return (ft_str_nl(&temp, &str_nl, nl));
		if (!size_read && !temp[0])
			break ;
		if (!size_read)
			return (ft_str_left(&temp, 0));
		size_read = read(fd, buffer_read, BUFFER_SIZE);
	}
	free(temp);
	temp = NULL;
	return (NULL);
}
