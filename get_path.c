/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:56:43 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/25 14:56:45 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_text	*new_text(t_lemin *info, int id)
{
	t_text *new;

	new = (t_text*)malloc(sizeof(t_text));
	new->content = info->adj_list[id]->name;
	new->next = NULL;
	new->id = id;
	return (new);
}

static t_text	*init_text(t_lemin *info, t_queue *queue)
{
	t_text *text;

	text = (t_text*)malloc(sizeof(t_text));
	text->content = info->adj_list[queue->id]->name;
	text->id = info->fl_start;
	text->next = NULL;
	return (text);
}

t_text			*get_path(t_lemin *info, t_queue *queue)
{
	t_queue *begin;
	t_text	*text;
	t_text	*start;
	int		temp;

	begin = queue;
	while (queue->next && queue->id != info->fl_start)
		queue = queue->next;
	text = init_text(info, queue);
	start = text;
	temp = queue->id_prev;
	while (queue)
	{
		if (temp == queue->id)
		{
			text->next = new_text(info, queue->id);
			text = text->next;
			temp = queue->id_prev;
		}
		queue = queue->prev;
	}
	queue = begin;
	return (start);
}
