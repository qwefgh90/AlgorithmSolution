//한점에서 연결해보고 남은 부분을 이전 계산값을 사용하여 구현한다.
//점화식 f(n) ={ f(n-1) * f(0) }+{ f(n-2) * f(1)} +{ f(n-3) + f(2)} + .... + {f(0) * f(n-1)}
//f(0) = 1
//f(1) = 1
//n 1~19
long long int drawTable[20] = { 0, };
#include <stdio.h>r
int main(){
	drawTable[0] = 1;
	drawTable[1] = 1;
	for (int i = 2; i < 20; i++){
		unsigned int result = 0;
		for (int j = 0; j < i; j++){
			result += drawTable[i - j - 1] * drawTable[j]; //* drawTable[i - j - 1];
		
		}
		drawTable[i] = result;
	//	printf("[%d]%d\n", i, drawTable[i]);
	}
	
	int testcase;
	
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int n;
		scanf("%d", &n);
		printf("%llu\n", drawTable[n]);
	}
	return 0;
}


/*

선긋기

1 , 2 , 3 , ... , 2*n-1 , 2*n 의 숫자를 시계 방향으로 일정한 간격으로 호 위에 번호를 부여한 후 한 숫자에서 다른 숫자로 선을 그을 때 교차 하지 않게 그을 수 있는 가짓 수를 출력하는게 문제이다.

예로 , n 이 2 이면 2 가지



n 이 3 이면 5 가지 이다.



입력
첫줄에 테스트케이스 개수 T가 주어진다.
다음 줄부터, 각 테스트케이스에 대하여, n 이 입력으로 주어진다. n 의 범위는 1 부터 19 사이의 정수이다.

출력

답을 출력하기 전에 각 테스트케이스의 순서에 따라 “#testcase1”“#testcase2”... 을 출력한다. 각 테스트케이스에 대하여 가짓수를 출력한다.

입출력 예

입력
1
3

출력
#testcase1
5


*/