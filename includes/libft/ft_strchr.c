/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:31:26 by ealves            #+#    #+#             */
/*   Updated: 2022/12/02 18:20:41 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}

// int	main()
// {
// 	char	s[8] = "bonjour";
// 	int		c = 's';

// 	//printf("%s\n", ft_strchr(s, c));
// 	printf("%s\n", strchr(s, c));
// }
