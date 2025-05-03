/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:42:55 by ealves            #+#    #+#             */
/*   Updated: 2022/12/19 20:06:54 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	write (1, &c, 1);
	*count += 1;
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar (str[i], count);
		i++;
	}
}

void	ft_putnbr(int nb, int *count)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2", count);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-', count);
		ft_putnbr(-nb, count);
	}
	else if (nb >= 0 && nb <= 9)
		ft_putchar((nb + '0'), count);
	else
	{
		ft_putnbr((nb / 10), count);
		ft_putnbr((nb % 10), count);
	}
}

void	ft_unsigned_putnbr(unsigned int nb, int *count)
{
	if (nb <= 9)
		ft_putchar((nb + '0'), count);
	else
	{
		ft_unsigned_putnbr((nb / 10), count);
		ft_unsigned_putnbr((nb % 10), count);
	}
}
