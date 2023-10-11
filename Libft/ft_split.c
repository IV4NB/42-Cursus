/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iballest <iballest@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:10:17 by iballest          #+#    #+#             */
/*   Updated: 2023/09/20 17:59:57 by iballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numstring(char const *s1, char c)
{
	int	cont;
	int	trigger;
	int	i;

	i = 0;
	cont = 0;
	trigger = 0;
	if (!s1)
		return (0);
	while (s1[i])
	{
		if (s1[i] == c)
			trigger = 0;
		else if (trigger == 0)
		{
			trigger = 1;
			cont++;
		}
		i++;
	}
	return (cont);
}

static int	numchar(char const *s2, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char	**freee(char const **dst, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)dst[j]);
	}
	free(dst);
	return (NULL);
}

static char	**affect(char const *s, char **ret, char c, int numwords)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] && j < numwords)
	{
		k = 0;
		while (s[i] == c)
			i++;
		ret[j] = (char *)malloc(sizeof(char) * numchar(s, c, i) + 1);
		if (!ret[j])
			return (freee((char const **)ret, j));
		while (s[i] && s[i] != c)
			ret[j][k++] = s[i++];
		ret[j][k] = '\0';
		j++;
	}
	ret[j] = 0;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		numwords;

	if (s == NULL)
		return (NULL);
	numwords = numstring(s, c);
	ret = (char **)malloc(sizeof(char *) * (numwords + 1));
	if (!ret)
		return (NULL);
	return (affect(s, ret, c, numwords));
}
