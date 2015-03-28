#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int testcase;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		char input1[20];
		char input2[20];
		scanf("%s", input1);
		scanf("%s", input2);
		char* num1 = input1;
		char* num2 = input2;
		int num1Count = strlen(num1);
		int num2Count = strlen(num2);
		for (int j = 0; j < num1Count; j++){
			if (num1[j] == '6'){
				num1[j] = '5';
			}
		}
		for (int j = 0; j < num1Count; j++){
			if (num2[j] == '6'){
				num2[j] = '5';
			}
		}

		int numValue1 = atoi(num1);
		int numValue2 = atoi(num2);
		int minResult = numValue1 + numValue2;
		for (int j = 0; j < num1Count; j++){
			if (num1[j] == '5'){
				num1[j] = '6';
			}
		}
		for (int j = 0; j < num1Count; j++){
			if (num2[j] == '5'){
				num2[j] = '6';
			}
		}

		 numValue1 = atoi(num1);
		 numValue2 = atoi(num2);
		int maxResult = numValue1 + numValue2;
		
		printf("%d %d\n", minResult, maxResult);
		
	}
	return 0;
}

/*
페리카는 이 숫자 테이블을 돌리는 것이 조금 지루해 졌다. 그래서 선생님이 다른 문제로 두 정수 A,B 를 쓴 후 이 숫자를 더한 값을 구하는 문제를 제시 했다.

그런데 페리카는 계산을 틀리게 하지는 않지만 주어진 두개의 숫자를 5 를 6 으로 , 6 을 5 로 바꾸어 옮겨쓰는 실수를 종종 한다.

두 개의 숫자를 입력으로 받아 그가 계산할 수 있는 최소값과 최대값을 구하는 것이 문제이다.

[입력]
첫번째 줄 테스트 케이스 N입력
이후 케이스 수 만큼 두 양의 정수 A,B 가 입력으로 주어진다.(1 ≤ A, B ≤ 1 000 000).

[출력]
페리카가 얻을 수 있는 최소 , 최대 합을 출력한다.
(중요! 테스트 케이스 개수마다 #testcase번호를 출력 후 정답 출력)

-입출력 예-

입력
3
11 25
1430 4862
16796 58786

출력
#testcase1
36 37
#testcase2
6282 6292
#testcase3
74580 85582

*/