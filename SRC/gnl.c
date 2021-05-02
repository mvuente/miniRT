/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:46:19 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/22 11:46:21 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char		*bufrecorder(char *tmp, char buf)
{
	char	*old;
	int		length;

	old = tmp;
	length = ft_strlen(old);
	if (!(tmp = (char*)malloc(sizeof(char) * length + 2)))
		malloc_error();
	ft_bzero(tmp, length + 2);
	ft_memmove(tmp, old, length);
	tmp[length] = buf;
	free(old);
	return (tmp);
}

int			gnl(int fd, char **line)
{
	int		ret;
	char	buf[1];
	char	*tmp;

	if (!(tmp = (char*)malloc(sizeof(char))))
		malloc_error();
	*tmp = '\0';
	*line = tmp;
	while ((ret = read(fd, buf, 1) > 0))
	{
		if (buf[0] != '\n')
		{
			tmp = bufrecorder(tmp, buf[0]);
			*line = tmp;
		}
		else
			return (ret);
	}
	if (!ret)
		return (0);
	return (-1);
}
