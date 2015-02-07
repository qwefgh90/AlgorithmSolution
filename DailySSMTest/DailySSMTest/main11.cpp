#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int main(){

	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int count[10] = { 0, };
		unsigned int a = 0;	//100< x < 1000
		unsigned int b = 0;	//100,000,000
		unsigned int c = 0;
		scanf("%d %d %d", &a, &b, &c);
		unsigned int result = a*b*c;
		
		unsigned int dvalue = 0;
		unsigned int bonus = 0;
		
		while (result / 10 > 0){
			bonus = result % 10;
			result = result / 10;
			count[bonus]++;
		}
		if (result < 10){
			count[result]++;
		}
		
		for (int i = 0; i < 10; i++) {
			printf("%d\n", count[i]);
		}

	}


	return 0;
}
//
//문제지
//문제	숫자의 개수	문제코드	1 - B - 05
//내용	세 개의 자연수 A, B, C가 주어질 때 A×B×C를 계산한 결과에 0부터 9까지 각각의 숫자가 몇 번씩 쓰였는지를 구하는 프로그램을 작성하시오.
//예를 들어 A = 150, B = 266, C = 427 이라면 
//A × B × C = 150 × 266 × 427 = 17037300 이 되고,
//계산한 결과 17037300 에는 0이 3번, 1이 1번, 3이 2번, 7이 2번 쓰였다.
//입력 형식	첫째 줄은 테스트케이스 T를 입력 받아야 한다.
//다음 줄에 A, 둘째 줄에 B, 셋째 줄에 C가 주어진다.
//A, B, C, 는 모두 100보다 같거나 크고, 1, 000보다 작은 자연수이다.
//출력 형식	첫째 줄에 #testcaseN의 형태와 같이 번호를 출력한다
//둘째 줄에는 A×B×C의 결과에 0 이 몇 번 쓰였는지 출력한다.마찬가지로 셋째 줄부터 열한째 줄까지 A×B×C의 결과에 1부터 9까지의 숫자가 각각 몇 번 쓰였는지 차례로 한 줄에 하나씩 출력한다.
//예시	입력	출력
//2
//150
//266
//427
//337
//213
//911
//#testcase1
//3
//1
//0
//2
//0
//0
//0
//2
//0
//0
//#testcase2
//0
//1
//1
//1
//1
//1
//1
//0
//0
//2
