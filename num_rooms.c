/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:46:16 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/20 17:46:19 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	num_rooms(t_lemin *info)
{
	int		i;
	t_rooms	*begin;

	begin = info->rooms;
	i = 0;
	while (info->rooms)
	{
		info->rooms = info->rooms->next;
		i++;
	}
	info->rooms = begin;
	return (i);
}
