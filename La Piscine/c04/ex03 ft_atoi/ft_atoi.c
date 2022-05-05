/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:49:23 by jayang            #+#    #+#             */
/*   Updated: 2022/02/09 13:44:39 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
char	*ft_isspace(char *str)
{
	if (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	return (str);
}

char	*ft_check_minus(char *str, int *minus)
{
	*minus = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*minus *= -1;
		str++;
	}
	return (str);
}

int	ft_atoi(char *str)
{
	int	minus;
	int	result;

	str = ft_isspace(str);
	str = ft_check_minus(str, &minus);
	result = 0;
	while ('0' <= *str && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (minus * result);
}

/*
**1. atoi, atof, atol 함수 이름의 기원**

atoi 함수를 살펴보면 a - to - i 이렇게 나눌 수 있습니다. a = char(ASCII), i = int 로 보면 ch**a**r(**A**SCII) to integer 라는 이름으로 풀 수 있습니다.

즉. char 타입을 int 타입으로 변경한다. 이렇게 이해하시면 되겠습니다.

atoi = char to int = 문자열을 정수 타입으로

atof = char to double = 문자열을 실수 타입으로

atol = char to long int = 문자열을 long 정수 타입으로

중요한것은 여기서 char는 char[N], char* 로 표현이 되는 문자열을 말합니다.

개인적으로는 저는 char* to int 이 표현이 더 정확한 표현이라고 생각이 듭니다.
*/