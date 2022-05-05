/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:36:04 by jayang            #+#    #+#             */
/*   Updated: 2022/02/07 13:43:05 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	arr_length(char *arr)
{
	unsigned int	count;

	count = 0;
	while (arr[count])
		count++;
	return (count);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len_src;

	i = 0;
	len_src = arr_length(src);
	if (size == 0)
		return (len_src);
	while (src[i])
	{
		if (i >= (size - 1))
			break ;
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len_src);
}

/*
`size_t strlcpy(char * dest, const char * src, size_t size);`

## 인자

- `dest` : 복사가 진행될 목적지이다. void * 의 형태로 string뿐 아니라 다른 값도 들어올 수 있다.
- `src` : 우리가 복사를 해야하는 값이 들어있는 포인터이다.
- `size` : 최대 size - 1만큼만 복사를 진행한다. (\0값을 넣기 위해)

**1. strlcpy란**

    (1) `strlcpy`는 `dest`안에 `src`의 값을 복사하고, `src`의 길이를 `return`하는 함수이다.

    (2) `size`는 `src의 길이 이하`일때 이용되는 인자다.  

          `strlcpy`는 src의 `'\0'`값을 만나기 전 혹은 `size - 1`만큼 복사가 이루어 졌을때 복사를 중지한다.

    (3) `size` 인자는 `‘\0’`을 위한 공간을 포함해야 한다. 즉 0이하 인자를 던져주면 복사를 진행하지 않고

    `return`한다.
*/