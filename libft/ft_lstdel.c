/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:54:17 by bdomansk          #+#    #+#             */
/*   Updated: 2017/11/12 19:04:20 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	tmp = NULL;
	if (!alst || !*alst || !del)
		return ;
	while (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		if ((*alst)->next)
			tmp = (*alst)->next;
		else
			tmp = NULL;
		free(*alst);
		*alst = tmp;
	}
}
