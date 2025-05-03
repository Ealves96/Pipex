/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:04:27 by ealves            #+#    #+#             */
/*   Updated: 2022/12/02 18:19:18 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*kol;

	i = 0;
	kol = (char *) s;
	while (i < n)
	{
		kol[i] = c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	char	str[] = "Hello";
// 	char	c = 'H';

// 	printf("string before: %s\n", str);
// 	//ft_memset(str, c, 6);
// 	printf("string after: %s\n", str);
// 	memset(str, c, 6);
// 	// printf("%d\n", c == 'c');
// 	// printf("%d\n", (str[0] == 'c'));
// }
