/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:01:25 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/09 18:01:27 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	error(t_lemin *info)
{
	if (info->flags->m)
		system("afplay fail-trombone.mp3&");
	if (info->flags->c)
		ft_printf("%s", RED);
	if (info->flags->e)
		ft_printf("ERROR: %s\n", info->error_reason);
	else
		ft_printf("ERROR\n");
	if (info->flags->c)
		ft_printf("%s", DEF);
	if (!info->flags->h)
	{
		if (info->flags->l)
			system("leaks lem-in");
		exit(1);
	}
}
