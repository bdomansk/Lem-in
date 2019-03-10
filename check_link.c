/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:11:45 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/14 13:11:46 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		quantity_symbols(char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			j++;
		i++;
	}
	return (j);
}

static t_links	*new_link(char **links)
{
	t_links *new;

	new = (t_links*)malloc(sizeof(t_links));
	new->name1 = ft_strdup(links[0]);
	new->name2 = ft_strdup(links[1]);
	new->next = NULL;
	return (new);
}

static void		check_room_existence(t_lemin *info, char **links)
{
	t_rooms		*start;
	int			fl1;
	int			fl2;

	fl1 = 0;
	fl2 = 0;
	start = info->rooms;
	while (info->rooms && (!fl1 || !fl2))
	{
		if (!ft_strcmp(info->rooms->name, links[0]))
			fl1 = 1;
		if (!ft_strcmp(info->rooms->name, links[1]))
			fl2 = 1;
		info->rooms = info->rooms->next;
	}
	info->rooms = start;
	if (!fl1)
		info->error_reason = ft_strjoin("incorect link, non-existent room \
NAME: ", links[0]);
	if (!fl2)
		info->error_reason = ft_strjoin("incorect link, non-existent room \
NAME: ", links[1]);
	if (info->error_reason)
		error(info);
}

static void		add_link(t_lemin *info, char **links)
{
	t_links *start;

	if (!info->links)
		info->links = new_link(links);
	else
	{
		start = info->links;
		while (info->links->next)
			info->links = info->links->next;
		info->links->next = new_link(links);
		info->links = start;
	}
	check_room_existence(info, links);
	free_words(links);
}

void			check_link(t_lemin *info, char **words)
{
	char **links;

	info->fl_links = 1;
	check_start_and_end(info);
	links = ft_strsplit(words[0], '-');
	if (!ft_strchr(words[0], (int)'-'))
		info->error_reason = ft_strjoin("incorect link without '-' \
LINE: ", words[0]);
	else if (quantity_symbols(words[0], '-') > 1)
		info->error_reason = ft_strjoin("more then 1 '-' in link \
LINE: ", words[0]);
	else if (num_words(links) != 2)
		info->error_reason = ft_strjoin("no link between rooms \
LINE: ", words[0]);
	free_words(words);
	if (info->error_reason)
		error(info);
	add_link(info, links);
}
