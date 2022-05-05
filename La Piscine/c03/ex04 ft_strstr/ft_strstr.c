#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j])
			{
				j++;
				if (to_find[j] == '\0') // to_find가 '\0'에 도달했다 = 모두 동일하다
					return (&str[i]);
			}
		}
		i++;
	}
	return (0);
}

/*
## strstr

- 대상 문자열 src와 대상에서 찾을 문자열 to_find, 두 개의 문자열을 매개변수로 받는다.
- 대상 문자열에서 두 번째 매개변수로 받은 문자열을 찾는다.
- 만일 대상 문자열 src에서 검색하는 문자열 to_find를 찾으면, src에서 두 문자열이 일치하는 첫 번째 문자의 위치를 리턴한다.
- Null 포인터를 입력 받을 시, Segmentation fault 발생

`char *strstr(const char *haystack, const char *needle)`

문자열안에서 문자열을 찾는 함수 `strstr` 에 대해서 알아보자.

`strstr` 함수는 `haystack` 매개변수를 기준으로 `needle`을 찾는다. 만약 `needle`이 존재하지 않으면 `Null`을 존재한다면 `haystack` 에서 `needle` 이 시작하는 주소를 반환한다. 
따라서 존재하게 되었을 때 반환값을 출력해보면 `haystack` 에서 `needle` 의 값과 일치하는 값이 시작하는 주소로부터 `haystack` 이 끝나는 지점까지의 내용이 모두 출력된다.

`haystack` 에서 찾은 `needle` 값을 복사하지 않는 이유는 메모리 효율을 생각해서 새로운 메모리를 할당하지 않고 그대로 주소값만을 반환한다.

`str1`에서 `str2`를 찾았다면 가장 먼저 나오는 곳의 위치를 리턴한다. 만일 `str2`가 `str1`에 존재하지 않는다면 널을 리턴한다.

If needle is an empty string, haystack is returned; if needle occurs nowhere in haystack, NULL
is returned;

: `to_find`가 비어있는 문자열이면 `str`이 returned, `to_find`가 str어디에도 없으면 `null` returned
*/