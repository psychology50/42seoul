/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 08:49:55 by jayang            #+#    #+#             */
/*   Updated: 2022/02/13 09:17:19 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.c>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*sub;
	int	cnt;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	sub = (int *)malloc(sizeof (int) * (max - min));
	if (!(sub))
		return (-1);
	cnt = 0;
	while (min > max)
	{
		sub[cnt] = min;
		cnt++;
		min++;
	}
	*range = sub;
	return (cnt);
}