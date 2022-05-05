/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:21:21 by jayang            #+#    #+#             */
/*   Updated: 2022/02/07 11:12:05 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex_element(unsigned char c) // 문자 치환 함수
{
	char	*c_hex;
	char	hex[2];

	c_hex = "0123456789abcdef";
	hex[0] = c_hex[c / 16];
	hex[1] = c_hex[c % 16];
	write(1, hex, 2);
}

void	print_hex_addr(unsigned long long c_addr)
{
	unsigned char	sub[16]; // 
	int				i;

	i = 0;
	while (c_addr > 0)
	{
		sub[15 - i] = c_addr % 16;
		if (sub[15 - i] < 10)
			sub[15 - i] += '0';
		else
			sub[15 - i] = (sub[15 - i] % 10) + 'a';
		c_addr /= 16;
		i++;
	}
	while (i < 16)
	{
		sub[15 - i] = '0';
		i++;
	}
	while (i > 0)
	{
		write(1, sub + (16 - i), 1);
		i--;
	}
}

void	print_padding(unsigned int spc)
{
	while (spc > 0)
	{
		write(1, " ", 1);
		spc--;
	}
}

void	print_line(unsigned char *c_addr, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	while (idx < size) // size(출력할 문자)만큼 인덱스에 접근
	{
		print_hex_element(c_addr[idx]); // 요소를 16진수로 치환하여 출력할 함수 호출
		idx++;
		if (idx % 2 == 0) // 문자 2개마다 공백 1번 출력
			write(1, " ", 1);
	}
	print_padding(40 - (idx * 2) - (size / 2)); 
	// 문자가 16개가 안 들어온 경우를 대비한 라인 맞추기용 공백
	// 무식하게 계산한 인자 값을 던짐...
	// => 입력값이 없을 때 공백을 출력한다던가 새로운 접근법이 가능할 듯 함. 피신 끝나고 재도전.
	idx = 0;
	while (idx < size) // 원본은 아스키 코드 값을 확인하여 걸러내는 과정을 거침
	{
		if (' ' <= c_addr[idx] && c_addr[idx] <= '~') // 출력 가능한 건 바로 출력
			write(1, c_addr + idx, 1);
		else
			write(1, ".", 1); // 출력 불가능한 아스키 값은 .으로 치환해서 출력
		idx++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	select_idx;
	unsigned int	element_size;
	unsigned char	*c_addr; // void 타입은 연산자로 인덱스 이동이 불가능 하므로 강제 형변환

	select_idx = 0; // 16문자 단위로 인덱스 선택
	c_addr = (unsigned char *)addr; // (unsigned char *)안 해줘도 되지만 불안해서 함
	while (size > 0) // size가 addr의 길이보다 더 큰 값을 받았을 때,
	{                // 엉뚱한 주소까지 계속 가리키게 되는 데 그것마저 모두 출력해주어야 함.
		if (size >= 16) 
		{
			element_size = 16;
			size -= 16; // size가 0이 될 때까지 16씩 빼준다. (16개 크기만큼 처리하므로)
		}
		else
		{
			element_size = size; // 남은 문자 개수를 모두 던져준다.
			size = 0; // size 값에 0을 넣고 다음 반복문을 멈춘다.
		}
		print_hex_addr((unsigned long long)c_addr + select_idx);
		// unsigned long도 8byte지만 이것도 불안해서 long long 지정
		// c_addr을 8byte 숫자로 강제 형변환하여 select_idx번 인덱스 주소'만' 전송.
	  // 즉, 0번, 16번,
		write(1, ": ", 2);
		print_line(c_addr + select_idx, element_size);
		// c_addr의 select_idx번 인덱스 주소를 넘기고, 출력할 e_size 인자도 같이 전송.
		write(1, "\n", 1);
		select_idx += 16; // 16개의 char 인덱스 단위로 잘라서 보내기 위함.
	}
	return (addr);
}