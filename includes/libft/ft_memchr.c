/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:17:33 by ealves            #+#    #+#             */
/*   Updated: 2022/12/02 18:15:31 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*cs;
	size_t				i;

	i = 0;
	cs = (const unsigned char *)s;
	while (i < n)
	{
		if (cs[i] == (unsigned char) c)
			return ((void *) &cs[i]);
		i++;
	}
	return (NULL);
}

// int	main()
// {
// 	char	s[] = {0, 1, 2 ,3 ,4 ,5};

// 	printf("%p\n", (char *) memchr(s, '0', 1));
// 	printf("%p\n", (char *) ft_memchr(s, '0', 1));
// }
