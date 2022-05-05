#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*c_dest;

	c_dest = dest; // dest 문자열의 첫 인덱스 주소 복사
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (c_dest);
}

/*
## strcat

- 문자열 dest / src를 받아서, dest의 끝에 src를 복사하여 붙여넣습니다.
- 문자열 dest의 `\0` 자리부터 src를 붙여넣습니다.
- 함수가 실행된 이후, dest의 끝에 `\0`을 추가합니다.
- 함수가 실행을 정상적으로 마치면 dest가 반환됩니다.
*/