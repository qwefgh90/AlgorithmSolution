#include <stdio.h>
#include <math.h>
int main(){
	int testcase;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int input;
		scanf("%d", &input);
		int sqrtValue = sqrtl(input);
		int resultFlag = true;
		for (int j = 2; j <= sqrtValue; j++){
			if (input % j == 0){
				resultFlag = false;
				break;
			}
		}
		if (resultFlag)
			printf("Yes\n");
		else
			printf("No\n");
		
	}
	return 0;
}

/*
문제지
문제	소수 판별	문제코드	1-L-06
내용	입력 수 N이 소수 인지 아닌지 판별하는 메서드를 구현하라
입력 형식	첫째 줄은 테스트케이스 T를 입력 받아야 한다.
이후 소수 판별을 위한 정수 N이 T개 주어진다.
출력 형식	첫째 줄에 #testcaseN의 형태와 같이 번호를 출력한다
소수라면 Yes, 소수가 아니라면 No를 출력하라
예시	입력	출력
2
3
12
#testcase1.
Yes
#testcase2.
No

*/