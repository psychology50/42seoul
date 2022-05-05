/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_ctrl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:56:04 by jayang            #+#    #+#             */
/*   Updated: 2022/02/21 20:57:02 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_print_errno(char *param_str, int err)
{
	ft_putstr(basename(g_path));
	ft_putstr(": ");
	ft_putstr(param_str);
	ft_putstr(": ");
	ft_putstr(strerror(err));
	ft_putchar('\n');
}

void	bad_type_err(char *str)
{
	ft_putstr(basename(g_path));
	ft_putstr(": ");
	ft_putstr(str);
	ft_putstr(": ");
	ft_putstr("Bad file descriptor");
	ft_putchar('\n');
}