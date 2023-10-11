/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iballest <iballest@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:50:27 by iballest          #+#    #+#             */
/*   Updated: 2023/09/25 20:16:53 by iballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long long nbr, int base, int flag)
{
	int		len;
	char	*base_str;

	len = 0;
	if (flag == 1)
		base_str = "0123456789";
	else if (flag == 2)
		base_str = "0123456789abcdef";
	else if (flag == 3)
		base_str = "0123456789ABCDEF";
	if (nbr < 0)
	{
		nbr *= -1;
		len += ft_putchar('-');
	}
	if (nbr >= base)
	{
		len += ft_putnbr_base(nbr / base, base, flag);
		len += ft_putnbr_base(nbr % base, base, flag);
	}
	else
		len += ft_putchar(base_str[nbr]);
	return (len);
}

int	ft_putpointer(unsigned long long nbr, int base, int flag)
{
	int		len;
	char	*base_str;

	len = 0;
	base_str = "0123456789abcdef";
	if (flag == 1)
	{
		len += ft_putstr("0x");
		flag = 0;
	}
	if (nbr >= (unsigned long long)base)
	{
		len += ft_putpointer(nbr / base, base, 0);
		len += ft_putpointer(nbr % base, base, 0);
	}
	else
		len += ft_putchar(base_str[nbr]);
	return (len);
}
