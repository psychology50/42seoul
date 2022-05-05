#include <unistd.h>

char    *ft_strcpy(char *dest, char *src)
{
        int     size;

        size = 0;
        while (src[size])
        {
                dest[size] = src[size];
                size++;
        }
        dest[size] = '\0';
        return (dest);
}

/*
`char* strcpy(char* dest, const char* src)`

1. `dest` 문자열에 `src` 문자열을 복사하는 함수이다.
2. `src` 문자열이 `Null` 캐릭터가 되기전까지 `dest` 에 `src` 값을 대입하는 방식으로 알고리즘이 되어있다.
3. `dest` 문자열의 길이가 `src` 의 문자열 길이보다 짧으면 잘못된 메모리에 `src` 의 내용을 채우는 문제가 생길 수 있다.  ⇒ 잘 쓰는 것은 사용자의 몫이기 때문에 따로 예외 처리를 해줄 필요가 없다.

*/