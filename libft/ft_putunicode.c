/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:02:44 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/11 16:02:46 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunicode(int symbol)
{
	char	*str;
	int		len;

	str = ft_unicode_check(symbol, &len);
	write(1, str, len);
	free(str);
}
