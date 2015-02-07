#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int main() {
	int testcase = 0;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int x = 0;
		int y = 0;
		int z = 0;
		scanf("%d %d %d", &x, &y, &z);
		int total = 0;
		int front = (x - 2) * 2 + (y - 2) * 2;
		int back = front;
		int middle = 4*(z-2);
		total = front + back + middle;
		printf("%d\n", total);
		
	}
	return 0;
}



/*
====
====


문제	블록 색칠하기	문제코드	1-L-03
내용	크기가 1*1*1 인 블록을 가지고 가로 A 세로 B 높이 C 인 직육면체를 만든 후 A×B×C (2≤A,B,C≤120)의 블록 겉면에 페인트를 칠하였다.
아래의 그림은 3x3x3 인 경우의 보기이다.

이 때 2 개의 면만 페인트가 칠해진 블록의 개수를 구하는 게 문제이다.
입력 형식	첫째 줄은 테스트케이스 T를 입력 받아야 한다.
A , B , C 가 차례대로 입력된다. A 는 가로, B 는 세로, C 는 높이이다.
출력 형식	첫째 줄에 #testcaseN의 형태와 같이 번호를 출력한다
2개의 면만 페인트가 칠해진 블록의 개수를 첫째 줄에 출력한다.
예시	입력	출력
2
3 3 3
2 3 4
#testcase1
12
#testcase2
12

*/