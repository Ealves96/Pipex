/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:46:42 by ealves            #+#    #+#             */
/*   Updated: 2022/12/02 18:06:27 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*kol;

	i = 0;
	kol = (char *) s;
	while (i < n)
	{
		kol[i] = '\0';
		i++;
	}
}

// int     main(void)
// {
//     char str[] = "C'est une fonction";
// 	ft_bzero(str, 4);
// 	bzero(str, 4);
// 	//char c = 'w';
// 	// printf("%d\n", c == 'a');
// 	// printf("%d\n", (str[0] == '\0'));
//     // printf("%d\n", ft_bzero(str));
//     // printf("%d\n", bzero(str));
// }