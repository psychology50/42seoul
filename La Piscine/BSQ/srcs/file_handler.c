/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 08:34:04 by jayang            #+#    #+#             */
/*   Updated: 2022/02/22 10:13:44 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_solve_file(char *argv)
{
	int	fd;

	if (is_invalid_file(argv))
		return ;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_puterr();
	else
	{
		solve(fd);
		close(fd);
	}
}

void	file_handler(int argc, char *argv[])
{
	int	param;

	param = 1;
	while (param < argc)
	{
		global_init();
		ft_solve_file(argv[param]);
		param++;
	}
}