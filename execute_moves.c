/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 12:36:16 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/28 12:36:19 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char	*get_next_room(t_lemin *info, t_moves *moves)
{
	t_text	*start;
	int		id;

	start = moves->text;
	while (moves->id_room != moves->text->id)
	{
		moves->text = moves->text->next;
	}
	moves->id_room = moves->text->next->id;
	moves->text = start;
	id = moves->id_room;
	return (info->adj_list[id]->name);
}

static void	put_move(t_lemin *info)
{
	colours(info, info->moves);
	ft_printf("L%d-%s ", info->moves->num, get_next_room(info, info->moves));
	stop_colours(info);
}

void		execute_moves(t_lemin *info)
{
	t_moves *start;
	char	*line;

	line = NULL;
	start = info->moves;
	while (info->moves)
	{
		if (info->moves->active)
		{
			put_move(info);
			if (info->moves->id_room == info->fl_end)
				info->moves->active = 0;
		}
		info->moves = info->moves->next;
	}
	info->moves = start;
	if (!info->flags->s)
		ft_printf("\n");
	else
	{
		while (get_next_line(1, &line) == 1 && line && ft_strlen(line))
			ft_strdel(&line);
		ft_strdel(&line);
	}
}
