#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#define MAX 31

//i�� �ε��� �ϰ�� i+1�ڸ� ����
//�ִ� 32��° �ڸ� ���ڱ��� ����?
int numArr[MAX] = { 0, 2, 2 + 4, 2 + 4 + 8, };

int getIndex(int num){
	for (int i = 0; i < MAX-1; i++){
		if (numArr[i] < num && num <= numArr[i+1]){
			return i;
		}
	}
}

int main(){

	//���̺� ����
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
		int size = index + 1;//�ڸ���
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
������
����	luckynum	�����ڵ�	1-M-03
����	4 �� 7�� �̷�����ִ� ���� ����� ���ڶ�� �Ѵ�.
������ ó�� 5���� ����� ���ڴ�.

4, 7, 44, 47, 74...

���� k�� �־����� �� k�� ° ����� ���ڸ� ���ϴ� ���� ������.
�Է� ����	ù° ���� �׽�Ʈ���̽� T�� �Է� �޾ƾ� �Ѵ�.
���� k( 1<= k <= 10^9) �� �־�����.
��� ����	ù° �ٿ� #testcaseN�� ���¿� ���� ��ȣ�� ����Ѵ�
k�� ° ����� ���ڸ� ����Ѵ�.
����	�Է�	���
2
5
10000047
#testcase1
74
#testcase2
44774447447477474774444

*/