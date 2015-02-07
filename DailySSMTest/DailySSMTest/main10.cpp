#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char op1[100] = { 0, };
char op2[100] = { 0, };
char result[100] = { 0, };

char intToChar(int nvalue, int op);
int charToInt(int nvalue, char op);

inline unsigned int getResult(int nvalue, char* numberArray){
	unsigned int result = 0;
	int powvalue = 1;
	int endoffset = strlen(numberArray) - 1;
	for (int i = endoffset; i >= 0; i--){
		result += charToInt(nvalue, numberArray[i]) * powvalue;
		powvalue = powvalue * nvalue;
	}
	return result;

}
//0 <= op <= nvalue - 1
inline char intToChar(int nvalue, int op){
	if (nvalue <= 10){
		return (op + '0');
	}
	else{
		if (op >= 0 && op <= 9){
			return (op + '0');
		}
		else{
			return (op - 10 + 'A');
		}
	}
}

//문자 -> 숫자
inline int charToInt(int nvalue, char op){
	if (nvalue <= 10){
		return op - '0';
	}
	else {
		if (op >= '0' && op <= '9'){
			return (op - '0');
		}
		else{
			return (op - 'A' + 10);
		}

	}

}

//진수, 결과, 인자1, 인자2 를 입력받는다.
char* charCalculator(int nvalue, char* result, char* op1, char* op2){
	int op1_len = strlen(op1);
	int op2_len = strlen(op2);
	int res_len = 0;

	int op1_idx = op1_len - 1;
	int op2_idx = op2_len - 1;
	//char* result = NULL;

	int res_idx = 100 - 2;	//결과 버퍼 길이 -2

	int upper = 0;
	//1234123
	//1233
	while (op1_idx != -1 && op2_idx != -1){
		int temp = charToInt(nvalue, op1[op1_idx]) + charToInt(nvalue, op2[op2_idx]) + upper;
		if (temp >= nvalue)
			upper = 1;
		else
			upper = 0;

		result[res_idx--] = intToChar(nvalue, temp % nvalue);	//결과 저장

		op1_idx--;
		op2_idx--;
	}

	while (op1_idx != -1){
		int temp = charToInt(nvalue, op1[op1_idx]) + upper;
		if (temp >= nvalue)
			upper = 1;
		else
			upper = 0;

		result[res_idx--] = intToChar(nvalue, temp % nvalue);// +'0';	//결과 저장

		op1_idx--;
	}

	while (op2_idx != -1){
		int temp = charToInt(nvalue, op2[op2_idx]) + upper;
		if (temp >= nvalue)
			upper = 1;
		else
			upper = 0;

		result[res_idx--] = intToChar(nvalue, temp % nvalue);// +'0';	//결과 저장

		op2_idx--;
	}

	if (upper == 1){
		result[res_idx--] = 1 + '0';
	}

	return result + (res_idx + 1);
}

int main(){
	int testcase;

	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int nvalue = 0;//진수
		scanf("%d", &nvalue);
		scanf("%s", op1);
		scanf("%s", op2);
		char* res = charCalculator(nvalue, result, op1, op2);

		printf("%u\n", getResult(nvalue, res));
		printf("%s\n", res);



	}

	return 0;
}


//문제지
//문제	n진수의 합	문제코드	1 - L - 05
//내용	N진수로 이루어진 두 개의 수를 입력 받아 그 두 수의 합을 10진수와 N진수로
//나타내어 출력하는 프로그램을 작성하시오.
//입력 형식	첫째 줄은 테스트케이스 T를 입력 받아야 한다.
//둘째 줄에 진수를 나타내는 정수 N(2≤N≤16)을 입력 받는다.
//셋째 줄과 넷째 줄에 각각 N진수의 수를 입력 받는다.
//입력된 두 수의 합을 10진수로 나타냈을 때 21억을 넘지 않는다.
//10이상의 수는 순서대로 'A', 'B', 'C', 'D', 'E', 'F'로 나타낸다.
//출력 형식	첫째 줄에 #testcaseN의 형태와 같이 번호를 출력한다
//두 수의 합을 구하여 둘째 줄에 10진수로, 셋째 줄에
//N진수로 출력한다.
//예시	입력	출력
//2
//2
//111011
//10101
//16
//2A
//B03
//
//#testcase1
//80
//1010000
//#testcase2
//2861
//B2D
