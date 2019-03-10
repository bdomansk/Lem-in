/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_route.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:13:09 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/16 15:13:11 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	stop_dfs(t_lemin *info)
{
	int	i;

	i = 0;
	while (i < num_rooms(info))
	{
		info->visited[i] = 1;
		i++;
	}
}

static int	all_visited(t_lemin *info)
{
	int i;

	i = 0;
	while (i < num_rooms(info))
	{
		if (info->visited[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

static void	dfs(t_lemin *info, int id_start, int id_prev, int *flag)
{
	t_adj_list *begin;

	info->visited[id_start] = 1;
	if (id_start == info->fl_end)
	{
		(*flag) = 1;
		stop_dfs(info);
	}
	if (all_visited(info))
		return ;
	begin = info->adj_list[id_start];
	if (info->adj_list[id_start]->next)
	{
		if (info->visited[info->adj_list[id_start]->next->id] == 0)
			dfs(info, info->adj_list[id_start]->next->id, id_start, flag);
		else
		{
			info->adj_list[id_start] = info->adj_list[id_start]->next;
			dfs(info, id_start, id_prev, flag);
		}
	}
	if (id_prev != -1)
		dfs(info, id_prev, -1, flag);
	info->adj_list[id_start] = begin;
}

static void	check_flag(t_lemin *info, int flag)
{
	if (flag == 0)
	{
		info->error_reason = "there isn't connection between start and end";
		error(info);
	}
}

void		check_route(t_lemin *info)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	info->fl_start = -1;
	info->fl_end = -1;
	while (info->adj_list[i] && (info->fl_start == -1 || info->fl_end == -1))
	{
		if (!ft_strcmp(info->adj_list[i]->name, info->start))
			info->fl_start = info->adj_list[i]->id;
		if (!ft_strcmp(info->adj_list[i]->name, info->end))
			info->fl_end = info->adj_list[i]->id;
		i++;
	}
	info->visited = (int*)malloc(sizeof(int) * num_rooms(info));
	i = 0;
	while (i < num_rooms(info))
	{
		info->visited[i] = 0;
		i++;
	}
	dfs(info, info->fl_start, -1, &flag);
	check_flag(info, flag);
}
