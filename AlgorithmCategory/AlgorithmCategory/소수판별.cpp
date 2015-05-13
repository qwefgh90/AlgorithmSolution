#include <stdio.h>
#include <math.h>
int main(){
	int testcase;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int input;
		scanf("%d", &input);
		int sqrtValue = sqrtl(input);
		int resultFlag = true;
		for (int j = 2; j <= sqrtValue; j++){
			if (input % j == 0){
				resultFlag = false;
				break;
			}
		}
		if (resultFlag)
			printf("Yes\n");
		else
			printf("No\n");
		
	}
	return 0;
}

/*
������
����	�Ҽ� �Ǻ�	�����ڵ�	1-L-06
����	�Է� �� N�� �Ҽ� ���� �ƴ��� �Ǻ��ϴ� �޼��带 �����϶�
�Է� ����	ù° ���� �׽�Ʈ���̽� T�� �Է� �޾ƾ� �Ѵ�.
���� �Ҽ� �Ǻ��� ���� ���� N�� T�� �־�����.
��� ����	ù° �ٿ� #testcaseN�� ���¿� ���� ��ȣ�� ����Ѵ�
�Ҽ���� Yes, �Ҽ��� �ƴ϶�� No�� ����϶�
����	�Է�	���
2
3
12
#testcase1.
Yes
#testcase2.
No

*/