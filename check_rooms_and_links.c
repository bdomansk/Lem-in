/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms_and_links.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:02:56 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/12 16:02:58 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		check_room_repeat(t_lemin *info, char **words)
{
	t_rooms *start;

	start = info->rooms;
	while (info->rooms->next)
	{
		if (!ft_strcmp(words[0], info->rooms->name))
			info->error_reason = ft_strjoin("room names are repeated \
NAME: ", words[0]);
		else if (info->rooms->x == ft_atoi(words[1]) &&
			info->rooms->y == ft_atoi(words[2]))
			info->error_reason = ft_strjoin("room coordinates are repeated \
LINE: ", info->lines->line);
		if (info->error_reason)
			error(info);
		info->rooms = info->rooms->next;
	}
	info->rooms = start;
}

static t_rooms	*new_room(char **words)
{
	t_rooms *new;

	new = (t_rooms*)malloc(sizeof(t_rooms));
	new->name = ft_strdup(words[0]);
	new->x = ft_atoi(words[1]);
	new->y = ft_atoi(words[2]);
	new->next = NULL;
	return (new);
}

static void		add_room(t_lemin *info, char **words)
{
	t_rooms *start;

	if (!info->rooms)
		info->rooms = new_room(words);
	else
	{
		start = info->rooms;
		while (info->rooms->next)
			info->rooms = info->rooms->next;
		info->rooms->next = new_room(words);
		info->rooms = start;
	}
	check_room_repeat(info, words);
	if (info->fl_start && !info->start)
		info->start = ft_strdup(words[0]);
	info->end = (info->fl_end && !info->end) ? ft_strdup(words[0]) : info->end;
	free_words(words);
}

static void		check_room(t_lemin *info, char **words)
{
	char	*itoa_x;
	char	*itoa_y;

	itoa_x = ft_itoa(ft_atoi(words[1]));
	itoa_y = ft_itoa(ft_atoi(words[2]));
	if (info->fl_links)
		info->error_reason = ft_strjoin("incorrect format, rooms are \
mixed with links. LINE: ", info->lines->line);
	else if (words[0][0] == 'L')
		info->error_reason = ft_strjoin("name of the room start \
with 'L'. LINE: ", info->lines->line);
	else if (ft_strchr(words[0], '-'))
		info->error_reason = ft_strjoin("name of the room have \
a '-'. LINE: ", info->lines->line);
	else if (ft_strcmp(words[1], itoa_x))
		info->error_reason = ft_strjoin("the X coordinate has the wrong \
format. LINE: ", info->lines->line);
	else if (ft_strcmp(words[2], itoa_y))
		info->error_reason = ft_strjoin("the Y coordinate has the wrong \
format. LINE: ", info->lines->line);
	free(itoa_x);
	free(itoa_y);
	if (info->error_reason)
		error(info);
	add_room(info, words);
}

void			check_rooms_and_links(t_lemin *info)
{
	char **words;

	words = ft_strsplit(info->lines->line, ' ');
	if (num_words(words) != 1 && num_words(words) != 3)
	{
		info->error_reason = ft_strjoin("wrong number of words for \
room or link. LINE: ", info->lines->line);
		free_words(words);
		error(info);
	}
	else if (num_words(words) == 1)
		check_link(info, words);
	else
		check_room(info, words);
}
