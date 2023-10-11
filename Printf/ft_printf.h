/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iballest <iballest@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:55:50 by iballest          #+#    #+#             */
/*   Updated: 2023/09/25 20:15:41 by iballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	conv(char c, va_list args);
int	ft_printf(char const *str, ...);
int	ft_putpointer(unsigned long long nbr, int base, int flag);
int	ft_putnbr_base(long long nbr, int base, int flag);
int	ft_putstr(char *str);
int	ft_putchar(char c);

#endif