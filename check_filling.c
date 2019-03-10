/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:57:53 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/19 16:57:55 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	check_filling(t_lemin *info)
{
	if (!info->lines)
		info->error_reason = "there are no lines";
	else if (info->ants == -1)
		info->error_reason = "not specified number of ants";
	else if (!info->rooms)
		info->error_reason = "no rooms";
	else if (!info->start)
		info->error_reason = "no command ##start";
	else if (!info->end)
		info->error_reason = "no command ##end";
	else if (!info->links)
		info->error_reason = "no links";
	if (info->error_reason)
		error(info);
}
