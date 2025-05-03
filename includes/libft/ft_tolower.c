/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:03:24 by ealves            #+#    #+#             */
/*   Updated: 2022/11/11 16:38:13 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ((c >= 'A' && c <= 'Z'))
		c += 32;
	return (c);
}

// int main()
// {
// 	char	str[] = "Sylvain Maltais";
//     printf("%c\n", ft_tolower(str[0]));
// 	printf("%c\n", tolower(str[0]));
// }
