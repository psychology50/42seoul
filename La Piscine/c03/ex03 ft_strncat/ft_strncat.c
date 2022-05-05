#include <unistd.h>

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
`strncpy`와 같이 매개변수로 얼마만큼 붙일 것인지 길이 `n` 을 받고 `n` 만큼 `src` 의 내용을 붙여주고 널 문자를 붙여준다. 이 함수도 `dest` 의 남아있는 공간보다 `n` 의 크기가 큰 경우에 정의되지 않은 결과가 발생한다.

반환 값으로 `dest` 의 주소를 반환한다.
*/