/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_man_colours.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:59:43 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/13 11:59:45 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_man_colours(void)
{
	ft_putstr("Colour macros : \n");
	ft_putcolourstr("DEF\n", DEF);
	ft_putcolourstr("RED\n", RED);
	ft_putcolourstr("BLUE\n", BLUE);
	ft_putcolourstr("GREEN\n", GREEN);
	ft_putcolourstr("YELLOW\n", YELLOW);
	ft_putcolourstr("PURPLE\n", PURPLE);
	ft_putcolourstr("AQUAMARINE\n", AQUAMARINE);
	ft_putcolourstr("GREY\n", GREY);
}
