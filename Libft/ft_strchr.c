/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iballest <iballest@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:50:46 by iballest          #+#    #+#             */
/*   Updated: 2023/09/16 18:57:21 by iballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	ch;

	ch = (char)c;
	str = (char *)s;
	i = 0;
	while (str[i] != ch)
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (str + i);
}
