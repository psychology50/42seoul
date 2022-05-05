/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:57:48 by jayang            #+#    #+#             */
/*   Updated: 2022/02/10 19:48:02 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)  // 음수 처리
		return (0);
	else if (nb == 0) // 0! = 1
		return (1);
	if (nb == 1) // 재귀가 1을 만나면 종료되고 차례로 값을 리턴시켜 결과를 곱함.
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}