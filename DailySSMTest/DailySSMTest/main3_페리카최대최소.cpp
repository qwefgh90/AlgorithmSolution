#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int testcase;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		char input1[20];
		char input2[20];
		scanf("%s", input1);
		scanf("%s", input2);
		char* num1 = input1;
		char* num2 = input2;
		int num1Count = strlen(num1);
		int num2Count = strlen(num2);
		for (int j = 0; j < num1Count; j++){
			if (num1[j] == '6'){
				num1[j] = '5';
			}
		}
		for (int j = 0; j < num1Count; j++){
			if (num2[j] == '6'){
				num2[j] = '5';
			}
		}

		int numValue1 = atoi(num1);
		int numValue2 = atoi(num2);
		int minResult = numValue1 + numValue2;
		for (int j = 0; j < num1Count; j++){
			if (num1[j] == '5'){
				num1[j] = '6';
			}
		}
		for (int j = 0; j < num1Count; j++){
			if (num2[j] == '5'){
				num2[j] = '6';
			}
		}

		 numValue1 = atoi(num1);
		 numValue2 = atoi(num2);
		int maxResult = numValue1 + numValue2;
		
		printf("%d %d\n", minResult, maxResult);
		
	}
	return 0;
}

/*
�丮ī�� �� ���� ���̺��� ������ ���� ���� ������ ����. �׷��� �������� �ٸ� ������ �� ���� A,B �� �� �� �� ���ڸ� ���� ���� ���ϴ� ������ ���� �ߴ�.

�׷��� �丮ī�� ����� Ʋ���� ������ ������ �־��� �ΰ��� ���ڸ� 5 �� 6 ���� , 6 �� 5 �� �ٲپ� �Űܾ��� �Ǽ��� ���� �Ѵ�.

�� ���� ���ڸ� �Է����� �޾� �װ� ����� �� �ִ� �ּҰ��� �ִ밪�� ���ϴ� ���� �����̴�.

[�Է�]
ù��° �� �׽�Ʈ ���̽� N�Է�
���� ���̽� �� ��ŭ �� ���� ���� A,B �� �Է����� �־�����.(1 �� A, B �� 1 000 000).

[���]
�丮ī�� ���� �� �ִ� �ּ� , �ִ� ���� ����Ѵ�.
(�߿�! �׽�Ʈ ���̽� �������� #testcase��ȣ�� ��� �� ���� ���)

-����� ��-

�Է�
3
11 25
1430 4862
16796 58786

���
#testcase1
36 37
#testcase2
6282 6292
#testcase3
74580 85582

*/