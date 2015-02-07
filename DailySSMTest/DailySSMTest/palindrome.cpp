#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

//접두어와 접미어 둘다 되는 최대 길이를 항목으로 갖는 테이블 생성
//홀수개는 -1 짝수개는 -0 까지 찾아서 테이블 생성

void find_pi(char* input, int* table)
{
	int i = 0, j = -1;
	table[0] = -1;
	while (i < strlen(input))
	{
		if (j == -1 || input[i] == input[j])
		{
			i++, j++;
			table[i] = j;
		}
		else j = table[j];
	}
}


int main(){
	int testcase;
	scanf("%d", &testcase);
	char result[2048] = { 0, };
	char input[1024] = { 0, };
	int table[2048 + 1] = { 0, };

	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		char input[1024] = { 0, };
		scanf("%s", input);
		//초기 문자열 + 역 문자열 합치기
		strcpy(result, input);
		int length = strlen(input);
		for (int j = length - 1; j >= 0; j--){
			result[length + (length - 1 - j)] = input[j]; //문자열 완성
		}
		
		find_pi(result, table);
		
		//abcb 케이스 통과하지 못함

		//뒤에 붙일 길이 계산
		int offset = length - table[strlen(result)];
		for (int j = offset - 1; j >= 0; j--){
			result[length + (offset - 1 - j)] = input[j];
			if (j == 0){
				result[length + (offset - 1 - j) + 1] = 0;
			}
		}
		printf("%s\n", result);
	}

	return 1;
}