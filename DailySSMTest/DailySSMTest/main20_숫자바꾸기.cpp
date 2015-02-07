#include <stdio.h>
#include <stdlib.h>

//1�� ��Ʈ �� ����
int getBits(unsigned int result){
	int count = 0; 
	while (result != 0){
		int one = result & 0x00000001;
		if (one == 1){
			count++;
		}
		result = (result >> 1);
	}
	return count;
}


int main(){
	int testcase;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		unsigned int target1;
		unsigned int target2;
		scanf("%d %d", &target1, &target2);
		unsigned int result = target1 ^ target2;//xor����
		printf("%d\n", getBits(result));
	}


	return 0;
}


/*
������
����	���� �ٲٱ�	�����ڵ�	1-M-06
����	���� A�� B�� ��ȯ�ϱ� ���� �ٲ�� �ϴ� ��Ʈ ������ �����ϴ� �Լ��� �����϶�
�Է� ����	ù° ���� �׽�Ʈ���̽� T�� �Է� �޾ƾ� �Ѵ�.
���� �ٺ��� ���� A B�� T�� �־�����.
��� ����	ù° �ٿ� #testcaseN�� ���¿� ���� ��ȣ�� ����Ѵ�
�ٲ�� �ϴ� ��Ʈ ������ ���
����	�Է�	���
2
12 35
9 27
#testcase1.
5
#testcase2.
2

*/