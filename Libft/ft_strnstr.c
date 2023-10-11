/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iballest <iballest@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:04:46 by iballest          #+#    #+#             */
/*   Updated: 2023/09/14 18:33:51 by iballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] && i < n)
	{
		if (str[i] == to_find[j])
		{
			while (str[i + j] && to_find[j] && to_find[j] == str[i + j] && i
				+ j < n)
				j++;
			if (j == (size_t)ft_strlen(to_find))
				return (str + i);
		}
		i++;
		j = 0;
	}
	return (0);
}
