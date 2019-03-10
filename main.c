/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 17:51:12 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/17 17:03:34 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int argc, char **argv)
{
	t_lemin	*info;

	info = init_info(argc, argv);
	check_input(info);
	check_filling(info);
	make_adjacency_lists(info);
	check_route(info);
	put_lines(info);
	algoritm(info);
	bonuses(info);
	return (0);
}
