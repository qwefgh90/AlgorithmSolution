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

			result[res_idx--] = temp % 10 + '0';	//��� ����

			op1_idx--;
			op2_idx--;
		}

		while (op1_idx != -1){
			int temp = op1[op1_idx] - '0' + upper;
			if (temp >= 10)
				upper = 1;
			else
				upper = 0;

			result[res_idx--] = temp % 10 + '0';	//��� ����

			op1_idx--;
		}

		while (op2_idx != -1){
			int temp = op2[op2_idx] - '0' + upper;
			if (temp >= 10)
				upper = 1;
			else
				upper = 0;

			result[res_idx--] = temp % 10 + '0';	//��� ����

			op2_idx--;
		}

		if (upper == 1){
			result[res_idx--] = 1 + '0';
		}

		printf("%s\n", result + (res_idx + 1));



	}
	return 0;
}


//����	�� �ڸ��� ����	�����ڵ�	1 - M - 01
//����	�� �ڸ����� ������ �����Ѵ�.�⺻ ������ ���� ǥ�� ������ ������ �� ū ���� �Է����� �־�����(�ּ� 15�ڸ� �̻�)
//�� ���� ���� ��� ���� ����Ѵ�.[����1 ����2]�� �������� �־����� �������� ������ + �̴�.LSB���� ����� �����ϸ� 4�ڸ��� ��� ����ϸ� ���ϴ�.
//
//
//�Է� ����	ù° ���� �׽�Ʈ���̽� T�� �Է� �޾ƾ� �Ѵ�.
//��° ���� ���� �� ���� �� �ٿ� �Է��Ѵ�.�ԷµǴ� �� ���ڴ� ��ĭ���� ���еȴ�
//��� ����	ù° �ٿ� #testcaseN�� ���¿� ���� ��ȣ�� ����Ѵ�
//��° �ٿ� ���� ������� ����Ѵ�.
//����	�Է�	���
//2
//102112547887454533211210 402154546897642165879999
//123123132132133 65465789798798798798
//#testcase1
//504267094785096699091209
//#testcase2
//65465912921930930931
