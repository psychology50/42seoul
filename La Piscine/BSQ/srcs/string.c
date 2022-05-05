/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:16:29 by sryou             #+#    #+#             */
/*   Updated: 2022/02/22 09:41:26 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puterr(void)
{
	write(2, "map error\n", 10);
}

int	ft_atoi(char *str)
{
	int	result;

	result = 0;
	while ('0' <= *str && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	if (*str != '\0')
		return (-1);
	return (result);
}