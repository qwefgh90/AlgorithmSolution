#include <stdio.h>

int max(int a, int b){
	if (a >= b)
		return a;
	else
		return b;
}
int min(int a, int b){
	if (a > b)
		return b;
	else
		return a;
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int input1;
		int input2;
		scanf("%d %d", &input1, &input2);
		while (input1 != input2){
			if (input1 > input2){
				int minus = input1 - input2;
				int minValue = min(input1, input2);
				input1 = minus; input2 = minValue;
			}
			else{
				int minus = input2 - input1;
				int minValue = min(input1, input2);
				input1 = minus; input2 = minValue;
			}
		}
		printf("%d\n", input1);

	}
	
	return 0;
}

/*
[ 문제 ]
최대공약수를 구하는 유클리드 호제법은 ¡°두 수 m, n의 최대공약수는 두 수의 차 m-n과 두 수중에서 작은 수의 최대공약수와 같다¡± 라는 명제에 기반을 두고 있다.
이 과정을 반복해서m=n이 될 때의 m 값이 구하고자 하는 최대 공약수 이다.

두 수를 입력 받아 최대공약수를 구하는 프로그램을 작성 하시오.


[ 입 출력 조건 ]
입력
입력의 첫 줄은 테스트 케이스의 개수 T이다.
각 테스트케이스는 정수 m, n으로 이루어지고, 총 T개의 테스트케이스가 주어진다.

출력
반드시 #testcase숫자 출력 후
각 테스트케이스에 대한 최대공약수를 출력한다.

[ 입출력 예 ]
2
24 18
128 72
#testcase1
6
#testcase2
8




*/