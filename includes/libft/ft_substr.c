/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:15:47 by ealves            #+#    #+#             */
/*   Updated: 2022/12/05 22:38:21 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_safe(const char *s)
{
	if (!s)
		return (0);
	return (ft_strlen(s));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	size_t			i;
	unsigned int	longs;

	i = 0;
	new = NULL;
	longs = (unsigned int)ft_strlen_safe(s);
	if (!s || start > longs)
	{
		new = malloc(sizeof(char) * 1);
		if (!new)
			return (0);
	}
	else
	{
		if ((unsigned int)len > (longs - start))
			len = longs - start;
		new = malloc(sizeof(char) * (len + 1));
		if (!new)
			return (0);
		while (s[start] != '\0' && i < len)
			new[i++] = s[start++];
	}
	new[i] = '\0';
	return (new);
}
