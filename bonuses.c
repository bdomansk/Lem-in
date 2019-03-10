/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 16:10:38 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/22 16:10:40 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	show_path(t_text *text)
{
	t_text *begin;

	begin = text;
	while (text)
	{
		ft_printf("%s", text->content);
		if (text->next)
			ft_printf("->");
		else
			ft_printf("\n\n");
		text = text->next;
	}
	text = begin;
}

void	show_all_path(t_path *path)
{
	t_path	*begin;
	int		i;

	i = 0;
	begin = path;
	while (path)
	{
		ft_printf("%d) ", i);
		show_path(path->text);
		i++;
		path = path->next;
	}
	path = begin;
}

void	bonuses(t_lemin *info)
{
	if (info->flags->f && !info->flags->a)
	{
		ft_printf("\nTHE FASTEST WAY: ");
		show_path(info->path->text);
	}
	if (info->flags->a)
	{
		ft_printf("\nAnts can walk on these ways:\n");
		show_all_path(info->path);
	}
	if (info->flags->l)
		system("leaks lem-in");
	if (info->flags->m)
		system("killall afplay");
}
