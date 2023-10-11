/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iballest <iballest@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:54:16 by iballest          #+#    #+#             */
/*   Updated: 2023/09/12 19:27:14 by iballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	count;
	size_t	i;
	size_t	ret;

	if (size > (size_t)ft_strlen(dest))
		ret = ft_strlen(src) + ft_strlen(dest);
	else
		ret = ft_strlen(src) + size;
	i = 0;
	count = ft_strlen(dest);
	while (src[i] && (count + 1) < size)
	{
		dest[count] = src[i];
		i++;
		count++;
	}
	dest[count] = '\0';
	return (ret);
}
