#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <iostream>


int main(){
	int testcase = 0;
	char enter = 0;
	scanf("%d", &testcase);
	scanf("%c", &enter);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		char inbuffer[100000] = { 0, };
		int buffer[100000] = { 0, };
		char result[100000] = { 0, };
		int reusltOffset = 0;
		char deleteChar[100000] = { 0, };

		/*

		*/
		

		scanf("%[^\n]s", inbuffer);
		scanf("%c", &enter);
		scanf("%[^\n]s", deleteChar);
		scanf("%c", &enter);
		int len = strlen(inbuffer);

		for (int i = 0; i < len; i++){
			buffer[i] = inbuffer[i];
		}
		int deletelen = strlen(deleteChar);

		for (int j = 0; j < len; j++){
			for (int k = 0; k < deletelen; k++){
				if (deleteChar[k] == buffer[j]){
					buffer[j] = -1;
				}
			}
		}
		for (int j = 0; j < len; j++){
			if (buffer[j] != -1){
				result[reusltOffset++] = buffer[j];
			}
		}

		for (int j = len - 1; j >= 0; j--){
			if (buffer[j] == ' ')
				buffer[j] = '\0';
			else
				break;
		}


		printf("%s\n", result);

	}
}
/*
문제지
문제	특정 문자의 제거	문제코드	4-M-03
내용	제시되는 문자열에서 특정 문자를 지우려고 합니다. 첫 번째 줄에 문자열이 입력 되며 공백을 포함할 수 있으며 다음 줄에 제거 하려는 문자를 입력합니다.
첫 번째 줄에는 총 테스트 케이스의 수가 입력되며 다음 줄부터 각 케이스가 입력 됩니다. 다음 줄은 예시 문장이 입력되면 그 다음 줄에 제거 문자가 입력됩니다. 출력은 예시문장에서 제거문자를 제거한 문장을 출력합니다.

예를 들면 “samsung software membership code interview”라고 예시문장을 입력하고 제거문자로 srv를 입력한다면 amung oftwae membehip code inteiew 을 출력합니다.

[조건]
•	문자열은 ASCII코드 128자 이내로 표현됩니다.
•	문자열의 길이가 n이고 삭제 문자가 없을 경우 문자 출력 시 O(n)이 소요됩니다.
•	문자열에서 제거 문자를 삭제하고 뒤의 문자를 한 칸씩 당겨 출력했을 경우 최악의 소요시간은 O(n^2)의 시간이 소요됩니다.
•	O(n)에 가깝도록 최대한 시간을 유지하면서 문자를 제거하여 출력하는 방법을 제시하시오
입력 형식	첫째 줄은 테스트케이스 T를 입력 받아야 한다.
둘째 줄은 문장을 한줄에 입력한다
셋째 줄은 제거할 문자를 연속으로 입력한다
출력 형식	첫째 줄에 #testcaseN의 형태와 같이 번호를 출력한다
둘째 줄은 문자 제거 후의 문장을 출력한다.
예시	입력	출력
2
samsung software membership
srv
code interview
srv
#testcase1
amung oftwae membehip
#testcase2
code inteiew

*/