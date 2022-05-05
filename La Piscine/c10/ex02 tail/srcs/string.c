/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:57:21 by jayang            #+#    #+#             */
/*   Updated: 2022/02/21 17:51:21 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_print_errno(char *param_str, int err)
{
	ft_putstr(basename(g_path));
	ft_putstr(": ");
	ft_putstr(param_str);
	ft_putstr(": ");
	ft_putstr(strerror(err));
	ft_putchar('\n');
}