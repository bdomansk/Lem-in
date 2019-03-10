/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_manual.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:53:16 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/09 15:53:18 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	put_manual(t_lemin *info)
{
	char	*line;
	int		fd;

	info->flags->h = 1;
	if (info->error_reason)
		error(info);
	if (info->flags->c)
		ft_printf("%s", AQUAMARINE);
	line = NULL;
	fd = open("manual", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_printf("%s\n", line);
		free(line);
	}
	if (info->flags->c)
		ft_printf("%s", DEF);
	if (info->flags->l)
		system("leaks lem-in");
	exit(0);
}

void	put_lines(t_lemin *info)
{
	t_lines *begin;

	begin = info->lines;
	while (info->lines)
	{
		ft_printf("%s\n", info->lines->line);
		info->lines = info->lines->next;
	}
	info->lines = begin;
}
