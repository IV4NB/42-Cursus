/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iballest <iballest@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:34:38 by iballest          #+#    #+#             */
/*   Updated: 2023/09/15 16:04:43 by iballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	char	*ret;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) <= start)
		return (ft_strdup(""));
	if ((size_t)ft_strlen(s + start) < len)
		len = (size_t)ft_strlen(s + start);
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (0);
	count = 0;
	while (count < len)
	{
		ret[count] = s[start + count];
		count++;
	}
	ret[count] = '\0';
	return (ret);
}
