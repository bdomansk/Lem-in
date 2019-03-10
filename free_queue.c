/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:54:07 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/25 14:54:09 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_queue(t_queue *queue)
{
	if (!queue)
		return ;
	if (queue->next)
		free_queue(queue->next);
	free(queue);
}
