/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:50:51 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/09 18:50:56 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		check_start_and_end(t_lemin *info)
{
	if (info->fl_start && !info->start)
		info->error_reason = ft_strjoin("command ##start applies to \
the LINE: ", info->lines->line);
	else if (info->fl_end && !info->end)
		info->error_reason = ft_strjoin("command ##end applies to \
the LINE: ", info->lines->line);
	else if (info->fl_links && !info->end)
		info->error_reason = "no command ##end";
	else if (info->fl_links && !info->start)
		info->error_reason = "no command ##start";
	if (info->error_reason)
		error(info);
}

static int	is_comment(t_lemin *info)
{
	char *s;

	s = info->lines->line;
	if (s[0] != '#')
		return (0);
	else
	{
		check_start_and_end(info);
		if (!ft_strcmp(s, "##start"))
			info->fl_start++;
		if (!ft_strcmp(s, "##end"))
			info->fl_end++;
		if (info->fl_start > 1)
			info->error_reason = "input data have more than one start";
		if (info->fl_end > 1)
			info->error_reason = "input data have more than one end";
		if ((info->fl_end == 1 || info->fl_start == 1) && info->ants == -1)
			info->error_reason = "start or end command before ants";
		if (info->error_reason)
			error(info);
		return (1);
	}
}

static void	add_line(t_lemin *info, char *line, t_lines **begin)
{
	if (!info->lines)
	{
		info->lines = (t_lines*)malloc(sizeof(t_lines));
		info->lines->line = ft_strdup(line);
		info->lines->next = NULL;
		*begin = info->lines;
	}
	else
	{
		info->lines->next = (t_lines*)malloc(sizeof(t_lines));
		info->lines->next->line = ft_strdup(line);
		info->lines = info->lines->next;
		info->lines->next = NULL;
	}
}

static void	check_ants(t_lemin *info)
{
	char	*itoa;

	check_start_and_end(info);
	info->ants = ft_atoi(info->lines->line);
	itoa = ft_itoa(info->ants);
	if (ft_strcmp(info->lines->line, itoa))
	{
		free(itoa);
		info->error_reason = ft_strjoin("invalid number format of \
ants. LINE: ", info->lines->line);
		error(info);
	}
	free(itoa);
	if (info->ants < 0)
	{
		info->error_reason = ft_strjoin("number of \
ants is less than 0. LINE: ", info->lines->line);
		error(info);
	}
}

void		check_input(t_lemin *info)
{
	char	*line;
	t_lines	*begin;

	begin = NULL;
	line = NULL;
	while (get_next_line(0, &line) == 1 && line && ft_strlen(line))
	{
		add_line(info, line, &begin);
		ft_strdel(&line);
		if (!is_comment(info))
		{
			if (info->ants == -1)
				check_ants(info);
			else
				check_rooms_and_links(info);
		}
	}
	ft_strdel(&line);
	info->lines = begin;
}
