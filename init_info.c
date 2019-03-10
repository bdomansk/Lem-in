/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 12:34:19 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/07 12:34:27 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_flags	*init_flags(void)
{
	t_flags	*flags;

	flags = (t_flags*)malloc(sizeof(t_flags));
	flags->h = 0;
	flags->e = 0;
	flags->l = 0;
	flags->c = 0;
	flags->s = 0;
	flags->a = 0;
	flags->f = 0;
	flags->m = 0;
	return (flags);
}

static void		add_flags(t_lemin *info, char *s)
{
	int i;

	i = 1;
	while (s[i])
	{
		if (!ft_strchr("helcsafm", (int)s[i]))
		{
			info->error_reason = ft_strjoin("wrong flags : ", s);
			put_manual(info);
		}
		info->flags->h = (s[i] == 'h') ? 1 : info->flags->h;
		info->flags->e = (s[i] == 'e') ? 1 : info->flags->e;
		info->flags->l = (s[i] == 'l') ? 1 : info->flags->l;
		info->flags->c = (s[i] == 'c') ? 1 : info->flags->c;
		info->flags->s = (s[i] == 's') ? 1 : info->flags->s;
		info->flags->a = (s[i] == 'a') ? 1 : info->flags->a;
		info->flags->f = (s[i] == 'f') ? 1 : info->flags->f;
		info->flags->m = (s[i] == 'm') ? 1 : info->flags->m;
		i++;
	}
}

static void		check_flags(t_lemin *info, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			add_flags(info, argv[i]);
		else
		{
			info->error_reason = ft_strjoin("wrong flags - ", argv[i]);
			put_manual(info);
		}
		i++;
	}
}

t_lemin			*init_info(int argc, char **argv)
{
	t_lemin	*info;

	info = (t_lemin*)malloc(sizeof(t_lemin));
	info->flags = init_flags();
	info->lines = NULL;
	info->rooms = NULL;
	info->links = NULL;
	info->start = NULL;
	info->end = NULL;
	info->path = NULL;
	info->error_reason = NULL;
	info->fl_start = 0;
	info->fl_end = 0;
	info->fl_links = 0;
	info->ants = -1;
	if (argc > 1)
		check_flags(info, argc, argv);
	if (info->flags->h)
		put_manual(info);
	return (info);
}
