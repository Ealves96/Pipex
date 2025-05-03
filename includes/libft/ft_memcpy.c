/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:56:47 by ealves            #+#    #+#             */
/*   Updated: 2022/12/05 21:57:09 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*csrc;
	char	*cdest;

	i = 0;
	csrc = (char *) src;
	cdest = (char *) dest;
	if (dest && src)
	{
		while (i < n)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char dest[100];
// 	memset(dest, 'A', 100);
// 	char 	*rtn = (char *)ft_memcpy(NULL, NULL, 2);
// 	char	src[6] = "Coucou";
// 	// char	dest[4] = "Elie";

// 	// printf("%s\n", ft_memcpy(NULL, NULL, 2));
// 	printf("%s\n", memcpy(NULL, NULL, 2));
// }