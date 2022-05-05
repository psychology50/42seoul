/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 08:37:13 by jayang            #+#    #+#             */
/*   Updated: 2022/02/12 12:53:09 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_sqrt(int nb)
{
	unsigned long long	num;
	unsigned long long	nb_2;

	if (nb <= 0) // nb가 0보다 작을 경우 모두 처리.
		return (0);	
	nb_2 = (unsigned long long)nb; // 남은 nb는 모두 양수밖에 없으므로 unsigned로 형변환
	num = 1;
	while (nb_2 >= (num * num)) // num * num이 오버플로우 나버리면 음수값을 가지게 됨.
	{
		if (nb_2 == (num * num))
			return ((int)num); // 리턴할 때는 다시 int타입으로 강제 형변환
		num++;
	}
	return (0);
}