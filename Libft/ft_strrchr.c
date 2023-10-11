/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iballest <iballest@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:09:14 by iballest          #+#    #+#             */
/*   Updated: 2023/09/12 20:19:31 by iballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	ch;

	ch = (char)c;
	str = (char *)s;
	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == ch)
			return ((char *)s + i);
		i--;
	}
	if (str[0] == ch)
		return ((char *)s);
	return (0);
}
