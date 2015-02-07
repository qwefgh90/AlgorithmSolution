#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int main(){
	int testcase;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		char input1[200] = { 0, };
		char input2[200] = { 0, };
		char result1[200] = { 0, };

		char result2[200] = { 0, };
		
		int ncount = 0;
		scanf("%s", input1);
		scanf("%s", input2);
		scanf("%d", &ncount);
		
		char* input2Ptr = input2 + ncount;
		
		memcpy(result2, input1, ncount*sizeof(char));
		memcpy(result2 + ncount, input2Ptr, strlen(input2Ptr)*sizeof(char));
		
		memcpy(result1, input1, strlen(input1)*sizeof(char));
		memcpy(result1 + strlen(input1), input2, strlen(input2)*sizeof(char));

		printf("%s\n", result1);

		printf("%s\n", result2); 

		


	}
	return 0;
}

//
//문제지
//문제	문자열 합성	문제코드	4 - B - 03
//내용	두 개의 문자열 A와 B, 한 개의 정수 n을 입력받아서 A에 B를 연결하고 A에서 n개의 문자를 B에 복사한 후 A와 B를 출력하는 프로그램을 작성하시오. (1≤n, A, B≤100)
//입력 형식	첫째 줄은 테스트케이스 T를 입력 받아야 한다.
//둘째 줄엔 문자열 A, B, 그리고 정수 n을 순차적으로 입력 받는다.
//출력 형식	첫째 줄에 #testcaseN의 형태와 같이 번호를 출력한다
//둘째 줄엔 A, B가 연결된 문자열을 출력하고, 그 다음 줄엔 n만큼의 A를 문자열 B에 복사한 문자열을 출력한다.
//예시	입력	출력
//2
//banana apple 3
//animal space 1
//#testcase1
//bananaapple
//banle
//#testcase2
//animalspace
//apace
