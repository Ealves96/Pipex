/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:15:18 by ealves            #+#    #+#             */
/*   Updated: 2022/11/25 17:22:24 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned int	ft_foundset(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char				*s2;
	size_t				longs;
	unsigned int		i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i] && ft_foundset(s1[i], set))
		s1++;
	longs = ft_strlen(s1) - 1;
	while (ft_foundset(s1[i], set))
		i++;
	while (ft_foundset(s1[longs], set) && longs > 0)
		longs--;
	s2 = ft_substr(s1, i, (longs + 1));
	return (s2);
}

// int	main()
// {
// 	char	s1[] = "*he*llo*";
// 	char	set[] = "**";
// 	printf("%s\n", ft_strtrim(s1, set));
// 	return (0);
// }
