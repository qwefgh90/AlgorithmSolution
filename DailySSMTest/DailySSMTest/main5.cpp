#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

unsigned long long factorial[20] = { 0, };

int main()
{
	factorial[0] = 1;
	factorial[1] = 1;
	factorial[2] = 2;
	factorial[3] = 6;
	for (int i = 4; i < 20; i++) {
		factorial[i] = factorial[i-1] * i;
	}
	
	int testcase = 0;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++) {
		printf("#testcase%d\n", i + 1);
		int input = 0;
		scanf("%d", &input);
		printf("%llu\n", factorial[input]);
	}

	return 0;
}

//1부터 어떤 양의 정수 n까지의 정수를 모두 곱한 것을 말하며 n!로 나타낸다.
//
//0!= 1
//1!= 1
//2!= 2
//n!= n * (n - 1)!
//：
//와 같이 정의된다.
//
//예로 4!= 4×3×2×1 = 24 이다.
//
//n!이 주어졌을 때 결과를 출력하는 프로그램을 작성하라.
//(Hint : 변수는 int형으로만 국한되지 않는다)