/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 12:09:34 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/28 12:09:35 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		init_moves(t_lemin *info)
{
	t_moves *moves;

	moves = (t_moves*)malloc(sizeof(t_moves));
	moves->next = NULL;
	moves->active = 0;
	info->moves = moves;
}

static int		check_moves(t_moves *moves)
{
	t_moves *begin;

	begin = moves;
	while (moves)
	{
		if (moves->active)
		{
			moves = begin;
			return (1);
		}
		moves = moves->next;
	}
	moves = begin;
	return (0);
}

static t_moves	*new_moves(t_lemin *info, int *i)
{
	t_moves	*moves;

	moves = (t_moves*)malloc(sizeof(t_moves));
	moves->next = NULL;
	moves->active = 1;
	moves->id_room = info->fl_start;
	moves->num = *i;
	moves->text = info->path->text;
	return (moves);
}

static void		add_moves(t_lemin *info, int *i)
{
	t_moves *begin;
	t_path	*start;

	begin = info->moves;
	while (info->moves->next)
		info->moves = info->moves->next;
	start = info->path;
	while ((*i) <= info->ants && info->path)
	{
		if (info->ants - (*i) + info->fastest < path_len(info->path))
			break ;
		info->moves->next = new_moves(info, i);
		info->moves = info->moves->next;
		info->path = info->path->next;
		(*i)++;
	}
	info->moves = begin;
	info->path = start;
}

void			moves(t_lemin *info)
{
	int	i;

	i = 1;
	info->fastest = path_len(info->path);
	init_moves(info);
	if (info->ants)
		ft_printf("\n");
	while (i <= info->ants || check_moves(info->moves))
	{
		add_moves(info, &i);
		execute_moves(info);
	}
}
