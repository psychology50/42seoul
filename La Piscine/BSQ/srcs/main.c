/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 08:22:35 by sryou             #+#    #+#             */
/*   Updated: 2022/02/22 10:14:47 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	global_init();
	if (argc == 1)
	{
		stdinput_handler();
		ft_solve_file(STDINPUT);
	}
	else
		file_handler(argc, argv);
	return (0);
}