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
//������
//����	���ڿ� �ռ�	�����ڵ�	4 - B - 03
//����	�� ���� ���ڿ� A�� B, �� ���� ���� n�� �Է¹޾Ƽ� A�� B�� �����ϰ� A���� n���� ���ڸ� B�� ������ �� A�� B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. (1��n, A, B��100)
//�Է� ����	ù° ���� �׽�Ʈ���̽� T�� �Է� �޾ƾ� �Ѵ�.
//��° �ٿ� ���ڿ� A, B, �׸��� ���� n�� ���������� �Է� �޴´�.
//��� ����	ù° �ٿ� #testcaseN�� ���¿� ���� ��ȣ�� ����Ѵ�
//��° �ٿ� A, B�� ����� ���ڿ��� ����ϰ�, �� ���� �ٿ� n��ŭ�� A�� ���ڿ� B�� ������ ���ڿ��� ����Ѵ�.
//����	�Է�	���
//2
//banana apple 3
//animal space 1
//#testcase1
//bananaapple
//banle
//#testcase2
//animalspace
//apace
