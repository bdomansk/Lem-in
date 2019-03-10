/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:51:23 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/25 14:51:25 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_path	*new_path(t_lemin *info, t_queue *queue)
{
	t_path *path;

	path = (t_path*)malloc(sizeof(t_path));
	path->next = NULL;
	path->text = get_path(info, queue);
	return (path);
}

static void		check_path(t_lemin *info, t_path *path)
{
	t_path	*begin;
	t_text	*start;
	int		i;

	begin = path;
	while (path)
	{
		start = path->text;
		while (path->text)
		{
			i = path->text->id;
			if (i != info->fl_start && i != info->fl_end)
				info->visited[i] = 1;
			path->text = path->text->next;
		}
		path->text = start;
		path = path->next;
	}
	path = begin;
}

static void		init_visited(t_lemin *info, t_path *begin)
{
	int i;
	int num;

	num = num_rooms(info);
	i = 0;
	while (i < num)
	{
		info->visited[i] = 0;
		i++;
	}
	if (begin)
		check_path(info, begin);
}

void			init_path(t_lemin *info)
{
	t_queue *queue;

	init_visited(info, NULL);
	queue = get_queue(info);
	info->path = new_path(info, queue);
	free_queue(queue);
}

void			get_all_paths(t_lemin *info)
{
	t_queue *queue;
	t_path	*begin;

	begin = info->path;
	info->visited[info->fl_start] = 1;
	while (info->visited[info->fl_start])
	{
		init_visited(info, begin);
		queue = get_queue(info);
		if (info->visited[info->fl_start] == 1)
		{
			info->path->next = new_path(info, queue);
			info->path = info->path->next;
		}
		free_queue(queue);
	}
	info->path = begin;
}
