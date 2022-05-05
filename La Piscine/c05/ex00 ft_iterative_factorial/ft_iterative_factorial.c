/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:45:34 by jayang            #+#    #+#             */
/*   Updated: 2022/02/10 19:49:36 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0)  // nb가 음수인 경우 처리
		return (0);
  else if (nb == 0) // 0! = 1 이므로 처리
		return (1);
	result = 1;
	while (nb > 0) // 양수인 경우에만 반복문으로 해결
	{
		result *= nb;
		nb--;
	}
	return (result);
}