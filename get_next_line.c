/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:07:33 by tbaricau          #+#    #+#             */
/*   Updated: 2025/10/24 13:01:02 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*res;
	size_t		pos;
	ssize_t		size;

	res = NULL;
	while (1)
	{
		pos = 0;
		while (buffer[pos] && !(pos && buffer[pos - 1] == '\n'))
			pos++;
		if (pos)
			ft_strlshift(buffer, ft_strpush(&res, buffer, pos));
		if (pos && (res == NULL || (res && res[ft_strlen(res) - 1] == '\n')))
			return (res);
		size = read(fd, buffer, BUFFER_SIZE);
		if (size <= 0)
			return (ft_freeonerror(res, size));
		buffer[size] = '\0';
	}
	return (NULL);
}
