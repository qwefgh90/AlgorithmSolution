#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#define MAX 31

//i번 인덱스 일경우 i+1자리 숫자
//최대 32번째 자리 숫자까지 있음?
int numArr[MAX] = { 0, 2, 2 + 4, 2 + 4 + 8, };

int getIndex(int num){
	for (int i = 0; i < MAX-1; i++){
		if (numArr[i] < num && num <= numArr[i+1]){
			return i;
		}
	}
}

int main(){

	//테이블 구성
	numArr[0] = 0;
//	numArr[30] = pow(2, 30);
	int temp = 2;
	for (int i = 0; i < 29; i++){
		numArr[i + 1] = temp + numArr[i];
		temp *= 2;
	}
	numArr[MAX - 1] = temp;
	
	int testcase = 0;
	scanf("%d", &testcase);
	for (int j = 0; j < testcase; j++){
		printf("#testcase%d\n", j + 1);
		char result[MAX + 2] = { 0, };
		int count;//1 <   && < 10^9
		scanf("%d", &count);
		int index = getIndex(count);
		int size = index + 1;//자리수
		int seq = count - numArr[index];
		seq = seq - 1;

		for (int i = 0; i < size; i++){
			result[size - 1 - i] = seq >> i & 0x00000001;
			if (result[size - 1 - i] == 0x00000001){
				result[size - 1 - i] = '7';
			}
			else{
				result[size - 1 - i] = '4';

			}
		}
		printf("%s\n",result);
	}
	return 0;
}

/*
문제지
문제	luckynum	문제코드	1-M-03
내용	4 나 7로 이루어져있는 수를 행운의 숫자라고 한다.
다음은 처음 5개의 행운의 숫자다.

4, 7, 44, 47, 74...

정수 k가 주어졌을 때 k번 째 행운의 숫자를 구하는 것이 문제다.
입력 형식	첫째 줄은 테스트케이스 T를 입력 받아야 한다.
정수 k( 1<= k <= 10^9) 가 주어진다.
출력 형식	첫째 줄에 #testcaseN의 형태와 같이 번호를 출력한다
k번 째 행운의 숫자를 출력한다.
예시	입력	출력
2
5
10000047
#testcase1
74
#testcase2
44774447447477474774444

*/