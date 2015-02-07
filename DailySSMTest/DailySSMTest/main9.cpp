#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
int main(){
	int testcase = 0;
	scanf("%d", &testcase);
	char op1[10000] = { 0, };
	char op2[10000] = { 0, };
	char result[10001] = { 0, };
	int temp_op1 = 0;
	int temp_op2 = 0;

	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		memset(op1, 0, 1024);
		memset(op2, 0, 1024);
		memset(result, 0, 2048);
		scanf("%s", op1);
		//char* ptr = op1;
		scanf("%s", op2);


		/*while (ptr[0] != ' '){
		ptr++;
		}
		ptr[0] = '\0';
		strcpy(op2, (ptr + 1));*/
		int op1_len = strlen(op1);
		int op2_len = strlen(op2);
		int res_len = 0;

		int op1_idx = op1_len - 1;
		int op2_idx = op2_len - 1;
		//char* result = NULL;

		int res_idx = 10001 - 2;

		int upper = 0;
		//1234123
		//1233
		while (op1_idx != -1 && op2_idx != -1){
			int temp = op1[op1_idx] - '0' + op2[op2_idx] - '0' + upper;
			if (temp >= 10)
				upper = 1;
			else
				upper = 0;

			result[res_idx--] = temp % 10 + '0';	//결과 저장

			op1_idx--;
			op2_idx--;
		}

		while (op1_idx != -1){
			int temp = op1[op1_idx] - '0' + upper;
			if (temp >= 10)
				upper = 1;
			else
				upper = 0;

			result[res_idx--] = temp % 10 + '0';	//결과 저장

			op1_idx--;
		}

		while (op2_idx != -1){
			int temp = op2[op2_idx] - '0' + upper;
			if (temp >= 10)
				upper = 1;
			else
				upper = 0;

			result[res_idx--] = temp % 10 + '0';	//결과 저장

			op2_idx--;
		}

		if (upper == 1){
			result[res_idx--] = 1 + '0';
		}

		printf("%s\n", result + (res_idx + 1));



	}
	return 0;
}


//문제	긴 자릿수 덧셈	문제코드	1 - M - 01
//내용	긴 자릿수의 덧셈을 구현한다.기본 데이터 형이 표현 가능한 수보다 더 큰 값이 입력으로 주어진다(최소 15자리 이상)
//이 값을 더한 결과 값을 출력한다.[숫자1 숫자2]의 형식으로 주어지며 연산자의 종류는 + 이다.LSB부터 계산을 진행하며 4자리씩 끊어서 계산하면 편하다.
//
//
//입력 형식	첫째 줄은 테스트케이스 T를 입력 받아야 한다.
//둘째 줄은 더할 두 수를 한 줄에 입력한다.입력되는 두 숫자는 빈칸으로 구분된다
//출력 형식	첫째 줄에 #testcaseN의 형태와 같이 번호를 출력한다
//둘째 줄에 더한 결과값을 출력한다.
//예시	입력	출력
//2
//102112547887454533211210 402154546897642165879999
//123123132132133 65465789798798798798
//#testcase1
//504267094785096699091209
//#testcase2
//65465912921930930931
