#include <unistd.h>

char    *ft_strncpy(char *dest, char *src, unsigned int n)
{
        int     i;

        i = 0;
        while ((i < n) && (src[i]))
        {
                dest[i] = src[i];
                i++;
        }
        while (i < n)
        {
                dest[i] = '\0';
								i++;
        }
        return (dest);
}

/*
`char *strncpy(char *dest, const char *src, size_t n)`

1. `dest` 문자열에 `src` 문자열을 `n` 만큼의 내용만을 복사하는 함수이다. 
2. `src`가 `dest`보다 짧거나 같으면 남은 자리를 `'\0'`으로 채워 준다.
3. `src`가 `n`보다 짧아도 복사를 멈추고 남은 자리를 `'\0'`으로 채워 준다.
4. `n`이 `dest` 의 길이 이상이면 `dest` 의 `null` 캐릭터 자리까지 `src` 의 값으로 채워질 수 있다.

       ⇒ 즉, 예외 처리를 내가 해줄 필요 없다. 사용자가 알아서 할 것. 놂 파이팅!

1. `strcpy`는 복사할 문자열의 ‘\0’까지 복사를 시켜주지만
    
    `strncpy`는  `str`보다 작은 `n`값을 넘겨줄 경우 `‘\0’`을 따로 복사하지 않는다.
    
                      `str`보다 큰 `n`값을 넘겨주고, `dest`에 여유 공간이 있을 때만 모두 `‘\0’`으로 채운다.
*/