/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:18:48 by ealves            #+#    #+#             */
/*   Updated: 2022/12/07 23:44:08 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (big == NULL && len == 0)
		return (NULL);
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		while ((big[i + j] == little[j]) && i + j < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}

// int	main()
// {
// 	// char	s1[] = "lorem ipsumm dolor sit amet";
// 	// char	s2[] = "ipsumm";

// 	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15));
// 	printf("%s\n", strnstr("lorem ipsum dolor sit amet", "dolor", 15));
// }