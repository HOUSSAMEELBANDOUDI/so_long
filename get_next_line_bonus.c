/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:21:33 by hel-band          #+#    #+#             */
/*   Updated: 2024/03/01 09:58:09 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_result(char **str, char **dst, int i)
{
	*dst = ft_substr(*str, 0, i + 1);
	*str = ft_add(str, i + 1);
	return (*dst);
}

char	*ft_add(char **str, int i)
{
	char	*new;

	new = ft_substr(*str, i, ft_strlen(*str + i));
	free(*str);
	*str = NULL;
	return (new);
}

char	*ft_get_line(char **str, char **dst, char **buffer, int fd)
{
	int	byt_read;
	int	nl;

	byt_read = read(fd, *buffer, BUFFER_SIZE);
	while (byt_read >= 0)
	{
		(*buffer)[byt_read] = '\0';
		*str = ft_strjoin(*str, *buffer);
		nl = ft_index(*str);
		if (nl != -1)
			return (ft_result(str, dst, nl));
		if (!byt_read && !*str[0])
			break ;
		if (!byt_read)
			return (ft_add(str, 0));
		byt_read = read(fd, *buffer, BUFFER_SIZE);
	}
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*str;
	char		*dst;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!str)
		str = ft_strdup("");
	if (!str)
		return (NULL);
	dst = ft_get_line(&str, &dst, &buffer, fd);
	free(buffer);
	buffer = NULL;
	return (dst);
}

int	ft_index(char *s)
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
