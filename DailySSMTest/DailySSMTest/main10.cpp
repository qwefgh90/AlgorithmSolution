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

//���� -> ����
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

//����, ���, ����1, ����2 �� �Է¹޴´�.
char* charCalculator(int nvalue, char* result, char* op1, char* op2){
	int op1_len = strlen(op1);
	int op2_len = strlen(op2);
	int res_len = 0;

	int op1_idx = op1_len - 1;
	int op2_idx = op2_len - 1;
	//char* result = NULL;

	int res_idx = 100 - 2;	//��� ���� ���� -2

	int upper = 0;
	//1234123
	//1233
	while (op1_idx != -1 && op2_idx != -1){
		int temp = charToInt(nvalue, op1[op1_idx]) + charToInt(nvalue, op2[op2_idx]) + upper;
		if (temp >= nvalue)
			upper = 1;
		else
			upper = 0;

		result[res_idx--] = intToChar(nvalue, temp % nvalue);	//��� ����

		op1_idx--;
		op2_idx--;
	}

	while (op1_idx != -1){
		int temp = charToInt(nvalue, op1[op1_idx]) + upper;
		if (temp >= nvalue)
			upper = 1;
		else
			upper = 0;

		result[res_idx--] = intToChar(nvalue, temp % nvalue);// +'0';	//��� ����

		op1_idx--;
	}

	while (op2_idx != -1){
		int temp = charToInt(nvalue, op2[op2_idx]) + upper;
		if (temp >= nvalue)
			upper = 1;
		else
			upper = 0;

		result[res_idx--] = intToChar(nvalue, temp % nvalue);// +'0';	//��� ����

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
		int nvalue = 0;//����
		scanf("%d", &nvalue);
		scanf("%s", op1);
		scanf("%s", op2);
		char* res = charCalculator(nvalue, result, op1, op2);

		printf("%u\n", getResult(nvalue, res));
		printf("%s\n", res);



	}

	return 0;
}


//������
//����	n������ ��	�����ڵ�	1 - L - 05
//����	N������ �̷���� �� ���� ���� �Է� �޾� �� �� ���� ���� 10������ N������
//��Ÿ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//�Է� ����	ù° ���� �׽�Ʈ���̽� T�� �Է� �޾ƾ� �Ѵ�.
//��° �ٿ� ������ ��Ÿ���� ���� N(2��N��16)�� �Է� �޴´�.
//��° �ٰ� ��° �ٿ� ���� N������ ���� �Է� �޴´�.
//�Էµ� �� ���� ���� 10������ ��Ÿ���� �� 21���� ���� �ʴ´�.
//10�̻��� ���� ������� 'A', 'B', 'C', 'D', 'E', 'F'�� ��Ÿ����.
//��� ����	ù° �ٿ� #testcaseN�� ���¿� ���� ��ȣ�� ����Ѵ�
//�� ���� ���� ���Ͽ� ��° �ٿ� 10������, ��° �ٿ�
//N������ ����Ѵ�.
//����	�Է�	���
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
