#include <stdio.h>
#include <stdlib.h>

//1인 비트 수 세기
int getBits(unsigned int result){
	int count = 0; 
	while (result != 0){
		int one = result & 0x00000001;
		if (one == 1){
			count++;
		}
		result = (result >> 1);
	}
	return count;
}


int main(){
	int testcase;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		unsigned int target1;
		unsigned int target2;
		scanf("%d %d", &target1, &target2);
		unsigned int result = target1 ^ target2;//xor연산
		printf("%d\n", getBits(result));
	}


	return 0;
}


/*
문제지
문제	숫자 바꾸기	문제코드	1-M-06
내용	정수 A를 B로 변환하기 위해 바꿔야 하는 비트 개수를 개산하는 함수를 구현하라
입력 형식	첫째 줄은 테스트케이스 T를 입력 받아야 한다.
다음 줄부터 정수 A B가 T개 주어진다.
출력 형식	첫째 줄에 #testcaseN의 형태와 같이 번호를 출력한다
바꿔야 하는 비트 개수를 출력
예시	입력	출력
2
12 35
9 27
#testcase1.
5
#testcase2.
2

*/