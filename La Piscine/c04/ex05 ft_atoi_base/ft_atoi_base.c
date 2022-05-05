/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:32:56 by jayang            #+#    #+#             */
/*   Updated: 2022/02/09 17:50:29 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_space_special(char *str, int *minus) // 공백 건너뛰고, 음양 판단
{
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	*minus = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-') // '-' 나올 때마다 -1 곱함
			*minus *= -1;
		str++;
	}
	return (str); // 연산이 끝난 str 주소 리턴
}

int	check_base_error(char	*base) // base 문자열 오류 체크
{
	int	idx;
	int	target;

	idx = 0;
	while (base[idx])
	{
		target = 0;
		if (base[idx] == '+' || base[idx] == '-') // +, - 기호 거름
			return (0);
		else if (!(' ' <= base[idx] && base[idx] <= '~')) // 출력 가능한 애들만 있어야 함
			return (0);
		while (target < idx) // idx가 증가할 때마다 0부터 idx-1만큼 계속해서 중복체크
		{
			if (base[target] == base[idx])
				return (0);
			target++;
		}
		idx++;
	}
	if (idx <= 1) // base의 idx가 1이하라고 판단될 경우 진수 계산이 불가능하다고 판단.
		return (0);
	return (1);
}

int nb_base(char c, char *base) // base를 밑으로 하는 문자를 치환
{                               // 동시에 c가 base 문자열 내에 없으면 -1 리턴.
	int nb;
	
	nb = 0;
	while (base[nb])
	{
		if (c == base[nb]) // 입력받은 문자와 같은 값이 있을 경우
			return (nb);     // 해당 인덱스에 해당하는 값을 리턴!!!!!
		nb++;              // ex) "0123456789abcdef"
	}                    // 16진수 f는 1
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int 	minus; // 부호 판단
	int 	result; // 정수형 결과 저장용 변수
	int		base_rdx; // base 진수 확인용

	if (check_base_error(base)) // base 예외처리
	{
		str = ft_space_special(str, &minus); // 공백 건너뛰고, 음/양 판단
		base_rdx = 0;
		while (base[base_rdx]) // base 크기를 세어 밑을 확인
				base_rdx++;          // ex) base 크기가 16이면 16진수를 밑으로 하는 str 문자열
 		result = 0;
		while (nb_base(*str, base) != -1)
		{
			result = (result * base_rdx) + nb_base(*str, base);
					// 나머지(역순) *   자릿수   + (base 문자열의 str 인덱스 값을 가져옴)
			str++;
		}
		return (minus * result); // 결과 리턴
	}
	return (0); // base가 null이거나 size가 1일 경우
}