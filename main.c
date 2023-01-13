/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:35:25 by rertzer           #+#    #+#             */
/*   Updated: 2022/12/26 16:55:19 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_sldata	sldata;

	if (argc != 2)
		error_exit(&sldata, NO_ARG);
	init_data(&sldata);
	init_bermap(&sldata, argv[1]);
	check_bermap(&sldata);
	init_game(&sldata);
}
