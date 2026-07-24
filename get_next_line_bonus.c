/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:50:15 by tbaricau          #+#    #+#             */
/*   Updated: 2025/10/24 13:00:15 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*res;
	size_t		pos;
	ssize_t		size;

	res = NULL;
	while (1)
	{
		pos = 0;
		while (buffer[fd][pos] && !(pos && buffer[fd][pos - 1] == '\n'))
			pos++;
		if (pos)
			ft_strlshift(buffer[fd], ft_strpush(&res, buffer[fd], pos));
		if (pos && (res == NULL || (res && res[ft_strlen(res) - 1] == '\n')))
			return (res);
		size = read(fd, buffer[fd], BUFFER_SIZE);
		if (size <= 0)
			return (ft_freeonerror(res, size));
		buffer[fd][size] = '\0';
	}
	return (NULL);
}
