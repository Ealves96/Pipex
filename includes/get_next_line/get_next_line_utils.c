/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:51:42 by ealves            #+#    #+#             */
/*   Updated: 2023/07/04 17:21:46 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// fd = descripteur de fichier
// buf = buffer, zone memoire ou sont stocke les lignes
// count = taille du buffer
// read = renvoi le nombre de caracteres lu
// "-1" s il y a erreur et "0s" s il a fini de lire

int	ft_strlen_gnl(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	if (c == '\0')
	{
		while (str[i])
			i++;
		return (i);
	}
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup_gnl(const char *s, int len)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	while (s[i] && i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
	free (dest);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		y;
	char	*s3;

	i = -1;
	y = -1;
	s3 = malloc(sizeof(char) * (ft_strlen_gnl(s1, '\0')
				+ ft_strlen_gnl(s2, '\0')) + 1);
	if (!s3)
		return (NULL);
	while (s1[++i])
		s3[i] = s1[i];
	while (s2[++y])
		s3[i + y] = s2[y];
	s3[i + y] = '\0';
	free(s1);
	return (s3);
}
