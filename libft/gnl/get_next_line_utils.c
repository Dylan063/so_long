/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student42nice.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:34:19 by dravaono          #+#    #+#             */
/*   Updated: 2023/06/05 07:03:00 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

// char	*ft_strjoingnl(char *s1, char *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*sfinal;

// 	sfinal = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
// 	i = 0;
// 	j = 0;
// 	if (!sfinal)
// 		return (0);
// 	if (!s1 || !s2)
// 		return (0);
// 	while (s1[i])
// 	{
// 		sfinal[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j])
// 	{
// 		sfinal[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	sfinal[i] = '\0';
// 	return (sfinal);
// }

// char	*ft_strdup(const char *src)
// {
// 	size_t	i;
// 	char	*dest;

// 	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
// 	if (dest == '\0')
// 		return (0);
// 	i = 0;
// 	while (src[i])
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}
