/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarrnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:00:28 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/13 13:00:31 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putarrnbr(int *stack, int size)
{
	int i;

	i = 0;
	while (size > 0)
	{
		ft_putnbr(stack[i]);
		ft_putchar('\n');
		i++;
		size--;
	}
}
