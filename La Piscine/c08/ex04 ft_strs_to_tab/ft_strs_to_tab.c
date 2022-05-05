/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:32:16 by jayang            #+#    #+#             */
/*   Updated: 2022/02/15 13:08:56 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	while (av[len])
		len++;
	return (len);
}

char	*ft_strcpy(int size, char *str)
{
	int	idx;
	char *sub;

	sub = (char *)malloc(sizeof (char) * (size + 1));
	if (!sub)
		return (0);
	idx = 0;
	while (av[idx])
	{
		sub[idx] = av[idx];
		idx++;
	}
	sub[idx] = '\0';
	return (sub);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av) // 구조체를 리턴하는 함수
{
	int	idx;
	t_stock_str	*stock_ptr; // t_stock_str 타입 포인터!! int *ptr처럼 생각하면 된다.

	stock_ptr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1);
	// malloc 함수를 사용해서 필요한 공간만큼 heap 영역에 구조체 할당
	if (!stock_ptr) // 구조체가 만들어지지 않을 경우 null 포인터 반환
		return (0);
	idx = 0;
	while (idx < ac)
	{
		stock_ptr[idx].size = ft_strlen(av[idx]);
		stock_ptr[idx].str = av[idx];
		stock_ptr[idx].copy = ft_strcpy(stock_ptr[idx].size, av[idx]);
		idx++;
	}
	stock_ptr[idx].str = 0;
	return (stock_ptr);
}