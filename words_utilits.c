/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_utilits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:49:51 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/13 14:49:53 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		num_words(char **words)
{
	int i;

	i = 0;
	while (words && words[i])
		i++;
	return (i);
}

void	free_words(char **words)
{
	int i;
	int	num;

	i = 0;
	num = num_words(words);
	while (i < num)
	{
		free(words[i]);
		i++;
	}
	free(words);
}
