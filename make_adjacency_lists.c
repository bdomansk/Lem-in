/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_adjacency_lists.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:40:40 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/20 12:40:42 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_adj_list	*new_adj_list(t_rooms *room, int i)
{
	t_adj_list *new;

	new = (t_adj_list*)malloc(sizeof(t_adj_list));
	new->name = room->name;
	new->id = i;
	new->next = NULL;
	return (new);
}

static void			add_to_adj_list2(t_lemin *info, int id1, int id2)
{
	t_adj_list	*begin;
	t_adj_list	*new;

	if (id1 == id2)
		return ;
	begin = info->adj_list[id1];
	while (info->adj_list[id1]->next)
	{
		if (info->adj_list[id1]->id == id2)
			break ;
		info->adj_list[id1] = info->adj_list[id1]->next;
	}
	if (info->adj_list[id1]->id == id2)
	{
		info->adj_list[id1] = begin;
		return ;
	}
	new = (t_adj_list*)malloc(sizeof(t_adj_list));
	new->id = id2;
	new->next = NULL;
	new->name = info->adj_list[id2]->name;
	info->adj_list[id1]->next = new;
	info->adj_list[id1] = begin;
}

static void			add_to_adj_list(t_lemin *info)
{
	t_links *begin;
	int		i;
	int		id1;
	int		id2;

	begin = info->links;
	while (info->links)
	{
		i = 0;
		id1 = -1;
		id2 = -1;
		while (info->adj_list[i] && (id1 == -1 || id2 == -1))
		{
			if (!ft_strcmp(info->links->name1, info->adj_list[i]->name))
				id1 = info->adj_list[i]->id;
			if (!ft_strcmp(info->links->name2, info->adj_list[i]->name))
				id2 = info->adj_list[i]->id;
			i++;
		}
		add_to_adj_list2(info, id1, id2);
		add_to_adj_list2(info, id2, id1);
		info->links = info->links->next;
	}
	info->links = begin;
}

void				make_adjacency_lists(t_lemin *info)
{
	int			size;
	int			i;
	t_adj_list	**adj_list;
	t_rooms		*begin;

	size = num_rooms(info);
	i = 0;
	begin = info->rooms;
	adj_list = (t_adj_list**)malloc(sizeof(t_adj_list*) * (size + 1));
	while (i < size)
	{
		adj_list[i] = new_adj_list(info->rooms, i);
		info->rooms = info->rooms->next;
		i++;
	}
	adj_list[i] = NULL;
	info->rooms = begin;
	info->adj_list = adj_list;
	add_to_adj_list(info);
}
