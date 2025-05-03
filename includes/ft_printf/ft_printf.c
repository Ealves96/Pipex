/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:57:22 by ealves            #+#    #+#             */
/*   Updated: 2022/12/19 20:06:45 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	typevariables(char c, va_list listarg, int *count)
{
	if (c == 'c')
		ft_putchar((char)va_arg(listarg, int), count);
	else if (c == 's')
		ft_putstr((char *)va_arg(listarg, char *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr((int)va_arg(listarg, int), count);
	else if (c == 'u')
		ft_unsigned_putnbr((unsigned int)va_arg(listarg, unsigned int), count);
	else if (c == 'x' || c == 'X')
		ft_hexa(c, (unsigned int)va_arg(listarg, unsigned int), count);
	else if (c == '%')
		ft_putchar('%', count);
	else if (c == 'p')
		ft_print_ptr((uintptr_t)va_arg(listarg, uintptr_t), count);
}

int	ft_printf(const char *str, ...)
{
	int			count;
	int			i;
	va_list		listarg;

	i = 0;
	count = 0;
	va_start(listarg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			typevariables(str[i], listarg, &count);
		}
		else
			ft_putchar(str[i], &count);
		i++;
	}
	va_end(listarg);
	return (count);
}

// int	main()
// {
// 	// char			c = 'E';
// 	char			*s = NULL;
// 	// uintptr_t		p = -2147483648;
// 	// int				d = 54546;
// 	// int				i = 100056;
// 	// unsigned int 	u = -1245487;
// 	// unsigned int 	hex = 16;

// 	// ft_printf("f printf :%c\n", c);
// 	// printf("r printf :%c\n", c);
// 	// printf("\n");
// 	ft_printf("f printf :%s\n", s);
// 	printf("r printf :%s\n", s);
// 	printf("\n");
// 	// ft_printf("f printf :%p\n", p);
// 	// printf("r printf :%p\n", (void *)p);
// 	// printf("\n");
// 	// ft_printf("f printf :%d\n", d);
// 	// printf("r printf :%d\n", d);
// 	// printf("\n");
// 	// ft_printf("f printf :%i\n", i);
// 	// printf("r printf :%i\n", i);
// 	// printf("\n");
// 	// ft_printf("f printf :%u\n", u);
// 	// printf("r printf :%u\n", u);
// 	// printf("\n");
// 	// ft_printf("f printf :%x\n", hex);
// 	// printf("r printf :%x\n", hex);
// 	// printf("\n");
// 	// ft_printf("f printf :%X\n", hex);
// 	// printf("r printf :%X\n", hex);
// 	// printf("\n");
// 	// ft_printf("f printf :%%\n");
// 	// printf("r printf :%%\n");
// 	// printf("\n");
// 	// ft_printf("f printf\n");
// 	// printf("r printf\n");
// 	// printf("\n");
// 	// ft_printf("f printf :%d%x hello\n", d, hex);
// 	// printf("r printf :%d%x hello\n", d, hex);
// 	// printf("\n");
// 	// ft_printf("f printf :%d\n", ft_printf("hello jujuij %x", hex));
// 	// printf("r printf :%d\n", printf("hello jujuij %x", hex));
// }
