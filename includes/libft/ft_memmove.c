/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:55:44 by ealves            #+#    #+#             */
/*   Updated: 2022/12/05 16:13:17 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*csrc;
	char	*cdest;

	i = 0;
	csrc = (char *) src;
	cdest = (char *) dest;
	if (!cdest || !csrc)
		return (0);
	if (cdest < csrc)
	{
		while (i < n)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	else
	{
		csrc = csrc + (n - 1);
		cdest = cdest + (n - 1);
		while (n--)
			*cdest-- = *csrc--;
	}
	return (dest);
}

// int	main(int argc, const char *argv[])
// {
// 	(void) argc;
// 	(void) argv;
// 	char	src[27] = "lorem ipsum dolor sit amet";
// 	char	*dest;

// 	dest = src + 1;

// 	printf("%s\n", (char *) ft_memmove(dest, src, 8));
// 	printf("%s\n", (char *) memmove(dest, src, 8));
// 	return (0);
// }
