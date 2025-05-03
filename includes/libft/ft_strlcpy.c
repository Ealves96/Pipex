/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:57:46 by ealves            #+#    #+#             */
/*   Updated: 2022/12/02 18:26:48 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}

// int	main(void)
// {
// 	char	src[] = "1234";
// 	char	dest[6] = "123456";
// 	// char src1b[] = "abcde";
// 	// char dest1b[] = "1234567";
// 	// char src2a[] = "abcd";
// 	// char dest2a[] = "123";
// 	// char src2b[] = "abcd";
// 	// char dest2b[] = "123";
// 	// char src3a[] = "";
// 	// char dest3a[] = "";
// 	// char src3b[] = "";
// 	// char dest3b[] = "";
// 	// char src4a[] = "12345";
// 	// char dest4a[] = "abc";
// 	// char src4b[] = "12345";
// 	// char dest4b[] = "abc";
// 	printf("%lu\n", ft_strlcpy(dest, src, 6));
// 	printf("%lu\n", strlcpy(dest, src, 6));
// }
