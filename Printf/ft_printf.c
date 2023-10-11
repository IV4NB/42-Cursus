/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iballest <iballest@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:51:02 by iballest          #+#    #+#             */
/*   Updated: 2023/09/25 20:32:45 by iballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
		i += write(1, &str[i], 1);
	return (i);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		convcounter;

	va_start(args, str);
	i = 0;
	convcounter = 0;
	while (str[i])
	{
		if (str[i] == '%')
			convcounter += conv(str[++i], args);
		else
			convcounter += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (convcounter);
}

int	conv(char c, va_list args)
{
	int	convcounter;

	convcounter = 0;
	if (c == 'c')
		convcounter += ft_putchar(va_arg(args, int));
	else if (c == 's')
		convcounter += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		convcounter += ft_putpointer((uintptr_t)va_arg(args, void *), 16, 1);
	else if (c == 'd' || c == 'i')
		convcounter += ft_putnbr_base(va_arg(args, int), 10, 1);
	else if (c == 'u')
		convcounter += ft_putnbr_base(va_arg(args, unsigned int), 10, 1);
	else if (c == '%')
		convcounter += ft_putchar('%');
	else if (c == 'x')
		convcounter += ft_putnbr_base(va_arg(args, unsigned int), 16, 2);
	else if (c == 'X')
		convcounter += ft_putnbr_base(va_arg(args, unsigned int), 16, 3);
	return (convcounter);
}
