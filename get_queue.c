/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 15:52:33 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/22 15:52:35 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		check_new_level(t_lemin *info, t_queue *all, t_queue *begin)
{
	int		temp_id;
	t_queue	*start;

	temp_id = info->adj_list[begin->id]->next->id;
	if (info->visited[temp_id] == 1)
		return (0);
	start = all;
	while (all)
	{
		if (temp_id == all->id)
			return (0);
		all = all->next;
	}
	all = start;
	return (1);
}

static t_queue	*new_level(t_lemin *info, t_queue *begin, t_queue *prev)
{
	int		temp_id;
	t_queue	*new;

	temp_id = info->adj_list[begin->id]->next->id;
	new = (t_queue*)malloc(sizeof(t_queue));
	new->id = temp_id;
	new->id_prev = begin->id;
	new->prev = prev;
	new->level = begin->level + 1;
	new->next = NULL;
	info->visited[temp_id] = 1;
	return (new);
}

static t_queue	*init_queue(t_lemin *info)
{
	t_queue *queue;

	queue = (t_queue*)malloc(sizeof(t_queue));
	queue->id = info->fl_end;
	queue->prev = NULL;
	queue->id_prev = -1;
	queue->level = 0;
	queue->next = NULL;
	info->visited[info->fl_end] = 1;
	return (queue);
}

static void		add_lvl(t_lemin *info, t_queue *all, t_queue *queue)
{
	t_queue		*begin;
	t_adj_list	*start;

	begin = queue;
	start = info->adj_list[begin->id];
	while (queue->next)
		queue = queue->next;
	while (info->adj_list[begin->id]->next)
	{
		if (check_new_level(info, all, begin))
		{
			queue->next = new_level(info, begin, queue);
			queue = queue->next;
		}
		info->adj_list[begin->id] = info->adj_list[begin->id]->next;
	}
	info->adj_list[begin->id] = start;
	queue = begin;
}

t_queue			*get_queue(t_lemin *info)
{
	t_queue	*queue;
	t_queue	*begin;

	queue = init_queue(info);
	begin = queue;
	while (queue)
	{
		add_lvl(info, begin, queue);
		queue = queue->next;
	}
	queue = begin;
	return (queue);
}
