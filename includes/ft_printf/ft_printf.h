/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:27:21 by ealves            #+#    #+#             */
/*   Updated: 2022/12/09 17:27:35 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

void	ft_putchar(char c, int *count);
void	ft_putnbr(int nb, int *count);
void	ft_putstr(char *str, int *count);
void	ft_print_ptr(uintptr_t nb, int *count);
void	ft_unsigned_putnbr(unsigned int nb, int *count);
void	typevariables(char c, va_list listarg, int *count);
void	ft_hexa(char c, unsigned long int nb, int *count);
int		ft_printf(const char *str, ...);

#endif