/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaricau <tbaricau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:09:51 by tbaricau          #+#    #+#             */
/*   Updated: 2025/10/24 12:59:04 by tbaricau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strpush(char **s0, char *s1, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;

	res = (char *)malloc(sizeof(char) * (ft_strlen(*s0) + len + 1));
	if (res == NULL)
	{
		free(*s0);
		*s0 = res;
		return (0);
	}
	i = 0;
	j = 0;
	while (*s0 && (*s0)[j])
		res[i++] = (*s0)[j++];
	j = 0;
	while (j < len)
		res[i++] = s1[j++];
	res[i] = '\0';
	free(*s0);
	*s0 = res;
	return (len);
}

void	ft_strlshift(char *s, size_t offset)
{
	size_t	i;

	i = 0;
	while (s[offset])
		s[i++] = s[offset++];
	s[i] = '\0';
	return ;
}

char	*ft_freeonerror(char *s, ssize_t error)
{
	if (error == 0)
		return (s);
	free(s);
	return (NULL);
}
