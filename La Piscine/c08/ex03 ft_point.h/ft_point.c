#include "./ft_point.h"

void set_point(t_point *point)
{
		point->x = 42; // (*point).x = 42 
		point->y = 21; // (*point).y = 21
		// 구조체가 가지고 있는 x인자에 직접적으로 접근한다.
}

int main(void)
{
		t_point point; // t_point 타입의 point 구조체를 생성한다.

		set_point(&point); // 구조체의 주소를 넘김
		return (0);
}