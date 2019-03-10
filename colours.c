/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 12:11:29 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/28 12:11:31 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	colours(t_lemin *info, t_moves *moves)
{
	int i;

	if (info->flags->c)
	{
		i = moves->num % 5;
		if (i == 0)
			ft_printf("%s", GREEN);
		else if (i == 1)
			ft_printf("%s", YELLOW);
		else if (i == 2)
			ft_printf("%s", BLUE);
		else if (i == 3)
			ft_printf("%s", PURPLE);
		else if (i == 4)
			ft_printf("%s", AQUAMARINE);
	}
}

void	stop_colours(t_lemin *info)
{
	if (info->flags->c)
		ft_printf("%s", DEF);
}
