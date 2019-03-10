/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 12:29:56 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/28 12:29:58 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		path_len(t_path *path)
{
	t_text	*begin;
	int		i;

	i = 0;
	begin = path->text;
	while (path->text->next)
	{
		i++;
		path->text = path->text->next;
	}
	path->text = begin;
	return (i);
}

void	simple_moves(t_lemin *info)
{
	int i;

	if (path_len(info->path) == 1)
	{
		ft_printf("\n");
		i = 1;
		while (info->ants >= i)
		{
			ft_printf("L%d-%s ", i, info->end);
			i++;
		}
		ft_printf("\n");
		bonuses(info);
		exit(0);
	}
}
