/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsupp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:41:58 by ealves            #+#    #+#             */
/*   Updated: 2022/12/19 17:01:31 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa(char c, unsigned long int nb, int *count)
{
	if (nb <= 9)
		ft_putchar((nb + '0'), count);
	else if (c == 'x' && (nb > 9 && nb < 16))
		ft_putchar(((nb - 10) + 'a'), count);
	else if (c == 'X' && (nb > 9 && nb < 16))
		ft_putchar(((nb - 10) + 'A'), count);
	else
	{
		ft_hexa(c, (nb / 16), count);
		ft_hexa(c, (nb % 16), count);
	}
}

void	ft_print_ptr(uintptr_t nb, int *count)
{
	if (nb == 0)
	{
		ft_putstr ("(nil)", count);
	}
	else
	{	
		ft_putstr ("0x", count);
		ft_hexa('x', nb, count);
	}
}
