/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:56:17 by ealves            #+#    #+#             */
/*   Updated: 2022/11/14 15:40:04 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;

	i = 0;
	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (cast_s1[i] && cast_s2[i] && cast_s1[i] == cast_s2[i] && i + 1 < n)
		i++;
	return (cast_s1[i] - cast_s2[i]);
}

// int	main(void)
// {
// 	// char s1[5] = "Test1";
// 	// char s2[2] = "OK";
// 	// char s1[] = "Same";
// 	// char s2[] = "Size";
// 	// char s1[] = "Shorter";
// 	char s2[] = "ThanMyself";
// 	char s1[] = "ShorterTest";

// 	printf("%d\n", ft_strncmp("abcdefgh", "abcdwxyz", 4));
// 	printf("%d\n", strncmp("abcdefgh", "abcdwxyz", 4));
// }