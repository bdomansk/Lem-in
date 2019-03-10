/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:47:07 by bdomansk          #+#    #+#             */
/*   Updated: 2017/11/10 14:17:18 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_min(int n, char *str)
{
	int i;

	n = 214748364;
	i = 9;
	str[11] = '\0';
	str[10] = '8';
	str[0] = '-';
	while (i >= 1)
	{
		if (n >= 10)
		{
			str[i] = n % 10 + 48;
			n = n / 10;
		}
		else
			str[i] = n + 48;
		i--;
	}
	return (str);
}

static char	*ft_str(int n, char *str, int i, int sign)
{
	if (n == -2147483648)
		return (ft_min(n, str));
	str[i + 1] = '\0';
	if (sign)
		str[0] = '-';
	while (i >= sign)
	{
		if (n >= 10)
		{
			str[i] = n % 10 + 48;
			n = n / 10;
		}
		else
			str[i] = n + 48;
		i--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		sign;
	int		i;
	char	*str;
	int		x;

	i = 1;
	sign = 0;
	if (n < 0 && n != -2147483648)
	{
		sign = 1;
		n = -n;
	}
	x = n;
	while (x >= 10 && i++ > -1)
		x = x / 10;
	if (n == -2147483648)
		str = (char*)malloc(11 + 1);
	else if (!(str = (char*)malloc(sign + i + 1)))
		return (0);
	return (ft_str(n, str, sign + i - 1, sign));
}
