/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:55:07 by ealves            #+#    #+#             */
/*   Updated: 2022/12/05 22:01:56 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (src && dst)
	{
		while (dst[i] && i < size)
			i++;
		if (size <= i)
			return (i + ft_strlen(src));
		while (src[j] && i + j < size - 1)
		{
			dst[i + j] = src[j];
			j++;
		}
		if (i != size)
			dst[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}

// int	main()
// {
// 	char	dst[] = "B";
// 	char	src[] = "AAAAAAAAA";
// 	printf("%ld\n", strlcat(dst, src, 0));
// 	printf("%ld\n", ft_strlcat(dst, src, 0));
// }
// 	char	*dest;
// 	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
// 		return (0);
// 	memset(dest, 0, 15);
// 	memset(dest, 'r', 6);
// 	dest[11] = 'a';
// 	printf("%ld\n", strlcat(dest, "lorem", 15));
// 	printf("%ld\n", ft_strlcat(dest, "lorem", 15));
// }
