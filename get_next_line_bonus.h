/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bagguine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:31:43 by bagguine          #+#    #+#             */
/*   Updated: 2023/12/20 23:04:47 by bagguine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *str);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strdup(const char *src);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		check_nl(char *s);
char	*ft_str_left(char **str, int nl);
char	*ft_str_nl(char **temp, char **str_nl, int nl);
char	*get_next_line(int fd);

#endif