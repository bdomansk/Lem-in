/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolourstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:59:49 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/13 10:59:52 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putcolourstr(char *str, char *colour)
{
	if (colour)
	{
		write(1, colour, ft_strlen(colour));
		write(1, str, ft_strlen(str));
		write(1, DEF, ft_strlen(DEF));
	}
}
