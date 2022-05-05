/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:35:43 by jayang            #+#    #+#             */
/*   Updated: 2022/02/10 21:53:30 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index <= 1) // 1의 개수를 모두 세면 결과가 나온다..!!!!
		return (index);
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}