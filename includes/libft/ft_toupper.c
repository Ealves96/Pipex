/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:44:20 by ealves            #+#    #+#             */
/*   Updated: 2022/11/11 16:34:05 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 'a' && c <= 'z'))
		c -= 32;
	return (c);
}

// int main()
// {
// 	char	str[] = "dylvain Maltais";

//     printf("%c\n", ft_toupper(str[0]));
// 	printf("%c\n", toupper(str[0]));
// }