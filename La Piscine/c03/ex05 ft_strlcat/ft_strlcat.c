/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:37:36 by jayang            #+#    #+#             */
/*   Updated: 2022/02/08 20:55:00 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *sub)
{
	int	cnt;

	cnt = 0;
	while (sub[cnt])
		cnt++;
	return (cnt);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;
	unsigned int	idx;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size > len_dest)
	{
		idx = 0;
		while (src[idx] && (len_dest + idx + 1 < size))
		{
			dest[len_dest + idx] = src[idx];
			idx++;
		}
		dest[len_dest + idx] = '\0';
		return (len_src + len_dst);
	}
	return (len_src + size);
}

/*
> inlcude
> 
> 
> ```
> #include <string.h>
> size_t strlcat(char *dest, const char *src, size_t size);
> ```
> 
- `dest` : `src`앞에 있는 문자열이다.
- `src`   : `dest` 뒤에 붙을 문자열이다.
- `size` : 우리가 복사를 진행할 문자열의 길이이다. minimum으로 `len_dst + size`

** 특징 **

1. `size` : `len_dest` + `len_src` + 1(`’\0’`)의 크기를 가진다.
2. `len_src`은 결과와 상관없이 일단 구해야 한다.
    
    (1) `size`의 크기가 복사할 대상인 `dest` 크기보다 작거나 같다면? → `len_src + size` 리턴
    
          * `size`가 너무 작아서 복사를 할 수 없다고 판단!
    
    (2) `size`의 크기가 복사할 대상인 `dest` 크기보다 크다면?    → `len_src + len_dest` 리턴
    
3. `src[idx]`와 `len_dest + idx + 1 < size`
    
    (1) `src[idx]` : `size`가 `src` 크기보다 커서 `‘\0’`에 의해 복사가 종료되는 경우
    
    (2) `len_dest + idx + 1 < size` : `src`가 모두 복사되기 전에 `‘\0’` 공간을 남기고 복사 종료
*/