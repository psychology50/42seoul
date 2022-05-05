# macro : makefile을 편리하게 쓰기 위함. 변수 선언 정도
CC = gcc
CHLAGS = -Wall -Wextra -Werror

TARGET = libft.a # 목적파일 : 명령어 수행 후 최종적으로 나온 결과를 저장할 파일
SRCS = src/ft_putchar.c src/ft_swap.c src/ft_putstr.c src/ft_strlen.c
OBJS = $(SRCS:.c=.o)
# $(<문자열>:<우측으로부터 매칭될 문자열>=<치환될 문자열>)
# $(MACRO_NAME:OLD=NEW)

HEADER = includes

all : $(TARGET)
# make는 makefile을 순차적으로 읽어서 가장 처음 나오는 규칙을 수행한다.
# all이란 더미타겟이 바로 첫 번째 타겟으로써 작용하게 된다.
# all이란 타겟을 정의하는 것은 관습이지만 의존 관계로써 정의해두면 편리하다.
# 실행 파일을 여러 개 생성할 때 사용하는 방법으로, 다중 타겟을 지정하는 방법인데
# 문제에서 make libft.a 와 같으면 된다고 했으므로 target 하나만 넣어주면 끝난다.

# 구조
# target : dependency  // 목적 파일을 만들기 위한 재료 파일
#   command    // 실행되어야 하는 명령어

%.o : %.c  # 모든 .c 파일을 .o 파일로 컴파일해준다. %는 와일드 카드 *과 같은 의미.
	$(CC) $(CHLAGS) -c -I $(HEADER) $< -o $@
# gcc -Wall -Wextra -Werror -c -I includes libft.a -o (source .... )
# gcc -I : 헤더 파일을 소스 내에 추가시킨다. 폴더명만 적어도 I 옵션에 의해 잘 찾아간다.

# @ : 현재 타켓의 이름
# ^ : 현재 타겟의 종속 항목 리스트
# < : 타겟을 생성하기 위해 열거된 종송 항목 리스트 중에 가장 왼쪽에 기술된 첫 번째 objs

$(TARGET) : $(OBJS)
	ar rscv $@ $^

# r : 지정한 아카이브로 obj 파일 추가, 기존에 존재하면 치환
# c : 아카이브(library file) 생성
# s : 아카이브 index 생성 (안 하면 ranlib을 따로 해주어야 함)
# v : 파일 정보 조회

clean: # make 진행 중에 생성된 목적 파일 제거
	rm -rf $(OBJS)

fclean: clean # make로 만들어진 생성 파일 제거
	rm -rf $(TARGET)

re: fclean all