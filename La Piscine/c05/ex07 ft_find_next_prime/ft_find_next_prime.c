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

int     my_is_prime(unsigned long long n)
{
        unsigned long long i;

        i = 2;
        while (i * i < n)
        {
                if (n % i == 0)
                        return (0);
                i++;
        }
        return (1)
}

int     ft_find_next_prime(int nb)
{
        int     next_nb;

		if (nb <= 1)
			return (0);
        next_nb = nb;
        while (next_nb <= 2147483647) //  int 표현 범위 넘어서 면 0 리턴
        { // 2147483647은 int가 표현 가능한 가장 큰 값이자 소수이므로 그 이상은 예외 처리 신경 x
            if (my_is_prime((unsigned long long)next_nb)
                return (next_nb);
            next_nb++;
        }
		return (0);
}