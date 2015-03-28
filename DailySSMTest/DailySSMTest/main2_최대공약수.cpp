#include <stdio.h>

int max(int a, int b){
	if (a >= b)
		return a;
	else
		return b;
}
int min(int a, int b){
	if (a > b)
		return b;
	else
		return a;
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++){
		printf("#testcase%d\n", i + 1);
		int input1;
		int input2;
		scanf("%d %d", &input1, &input2);
		while (input1 != input2){
			if (input1 > input2){
				int minus = input1 - input2;
				int minValue = min(input1, input2);
				input1 = minus; input2 = minValue;
			}
			else{
				int minus = input2 - input1;
				int minValue = min(input1, input2);
				input1 = minus; input2 = minValue;
			}
		}
		printf("%d\n", input1);

	}
	
	return 0;
}

/*
[ ���� ]
�ִ������� ���ϴ� ��Ŭ���� ȣ������ ���Ƶ� �� m, n�� �ִ������� �� ���� �� m-n�� �� ���߿��� ���� ���� �ִ������� ���٢��� ��� ������ ����� �ΰ� �ִ�.
�� ������ �ݺ��ؼ�m=n�� �� ���� m ���� ���ϰ��� �ϴ� �ִ� ����� �̴�.

�� ���� �Է� �޾� �ִ������� ���ϴ� ���α׷��� �ۼ� �Ͻÿ�.


[ �� ��� ���� ]
�Է�
�Է��� ù ���� �׽�Ʈ ���̽��� ���� T�̴�.
�� �׽�Ʈ���̽��� ���� m, n���� �̷������, �� T���� �׽�Ʈ���̽��� �־�����.

���
�ݵ�� #testcase���� ��� ��
�� �׽�Ʈ���̽��� ���� �ִ������� ����Ѵ�.

[ ����� �� ]
2
24 18
128 72
#testcase1
6
#testcase2
8




*/