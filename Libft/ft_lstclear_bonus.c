/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iballest <iballest@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:57:21 by iballest          #+#    #+#             */
/*   Updated: 2023/09/19 19:10:03 by iballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux1;
	t_list	*aux2;

	aux1 = lst[0];
	while (aux1)
	{
		aux2 = aux1->next;
		del(aux1->content);
		free(aux1);
		aux1 = aux2;
	}
	*lst = NULL;
}
