/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 08:19:41 by jayang            #+#    #+#             */
/*   Updated: 2022/02/13 08:30:14 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	int		idx;
	char	*c_src;

	len = 0;
	while (src[len])
		len++;
	c_src = (char *)malloc(sizeof (char) * (len + 1));
	if (!(c_src)) // 정상적으로 malloc 함수가 작동하지 않은 경우
		return (-1); // 지금 굳이 해줄 필요는 없다고 생각하지만,,,rush 하다 배운 거라 써보았다.
	while (src[idx])
	{
		c_src[idx] = src[idx];
		i++;
	}
	c_src[idx] = '/0'
	return (c_src);
}

/*
## **strdup**

- 포인터 `s`가 가리키는 문자열을 복사하고, 복사된 문자열에 대한 포인터를 반환
- 복사가 진행될 배열을 생성할 때는 `null`이 들어갈 공간까지 고려해야 함.

### 1. 함수 원형

```
char *strdup(const char *s);
```

### 2. *Parameters*

- `s` : 복사할 문자열

### 3. *Return value*

- `string`을 복사한 메모리주소(복사된 문자열의 주소를 가리키는 포인터)
- 실패 시 `NULL`
*/